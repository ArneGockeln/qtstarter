cmake_minimum_required(VERSION 3.8)
project(quickapp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Qt
# Set this to your Qt installation
set(ICON_NAME AppIcon)
set(CMAKE_PREFIX_PATH ~/sourcecode/sdk/QtLatest/5.9.2/clang_64)
set(CMAKE_AUTOMOC ON) # For meta object compiler 
set(CMAKE_AUTOUIC ON) # Resource files
set(CMAKE_AUTORCC ON) # UI Files
set(RESOURCE_FILES 
	res/resources.qrc
	res/${ICON_NAME}.icns
	res/${ICON_NAME}.png
)
find_package(Qt5Core REQUIRED)
# QtQuick Application
find_package(Qt5Quick REQUIRED)
# QtWidget Application
# find_package(Qt5Widgets REQUIRED)

# macOS Bundle building
set(OS_BUNDLE "")
if(CMAKE_BUILD_TYPE STREQUAL "Release")
set(OS_BUNDLE "MACOSX_BUNDLE")
set(COMPANY "Awesome Company")
set(COPYRIGHT "Copyright (c) 2019 Awesome Company. All rights reserved.")
set(IDENTIFIER "com.awesomecompany.appname")
set(PROJECT_VERSION 1.0)
set(MACOSX_BUNDLE_BUNDLE_NAME AppName)
set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})
set(MACOSX_BUNDLE_LONG_VERSION_STRING ${PROJECT_VERSION})
set(MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION})
set(MACOSX_BUNDLE_COPYRIGHT ${COPYRIGHT})
set(MACOSX_BUNDLE_GUI_IDENTIFIER ${IDENTIFIER})
set(MACOSX_BUNDLE_ICON_FILE ${ICON_NAME})
else(CMAKE_BUILD_TYPE STREQUAL "Release")
set(CMAKE_BUILD_TYPE Debug)
endif()

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
include_directories(${PROJECT_SOURCE_DIR})

# source files
file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

# executable
add_executable(${PROJECT_NAME} ${OS_BUNDLE} ${SOURCE_FILES} ${RESOURCE_FILES})
if(CMAKE_BUILD_TYPE STREQUAL "Release")
set_target_properties(${PROJECT_NAME} PROPERTIES 
	MACOSX_BUNDLE TRUE 
	RESOURCE "${RESOURCE_FILES}"
	OUTPUT_NAME "${MACOSX_BUNDLE_BUNDLE_NAME}"
)
endif()

# QtQuick Application
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)
# QtWidget Application
# target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)
