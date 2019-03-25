#!/bin/sh
# description: Build the application in debug mode: binary only. 
# Or in release mode, creating a macOS app bundle. On each build,
# the build directory is removed entirely.
# 
# Note: QtLatest/5.12.0/clang_64/bin needs to be in PATH variable
# 
# usage: ./build.sh [release]
# 
if [ -d "build" ]; then
	rm -rf ./build 
fi

mkdir build
cd build
if [ $# -lt 1 ]; then
	# build in debug mode, binary only
	cmake -DCMAKE_BUILD_TYPE=Debug ..
else
	# build in release mode, macOS app bundle
	cmake -DCMAKE_BUILD_TYPE=Release ..
fi
make

# macdeployqt
if [ $# -gt 0 ]; then
	# find app bundle name
	BUNDLENAME=$(find . -maxdepth 1 -name *.app)
	if [ -z "$BUNDLENAME" ]; then
		echo "Bundle not found."
		exit 1
	fi
	# qmldir
	QMLDIR=$(find $(pwd)/.. -name views| sed -e 's/build\/\.\.\///'| tr -d '[:space:]')
	if [ -z "$QMLDIR" ]; then
		# no qml views directory found, macdeployqt for QtWidgets application
		echo "Deploy Widget application"
		macdeployqt $BUNDLENAME	-verbose=2 -dmg
	else 
		# qml directory found, macdeployqt for QtQuick application
		echo "Deploy Quick application"
		macdeployqt $BUNDLENAME -verbose=2 -dmg -qmldir=$QMLDIR
	fi
fi

exit 0