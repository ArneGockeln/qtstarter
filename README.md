# qtstarter
C++/Qt5 starter project with cmake build system, QtQuick, QtWidgets, AppIcon, macOS bundle and macdeployqt support.

## Usage
1. Clone the repository.

2. Add the bin path of your Qt installation to your `~/.bash_profile`:

```
# there should be an entry like this:
export PATH="$PATH:~/sourcecode/sdk/QtLatest/5.12.0/clang_64/bin"
```

3. Add the bin path of your CMake installation to your `~/.bash_profile`:

```
# there should be an entry like this:
export PATH="$PATH:/Applications/CMake.app/Contents/bin"
```

4. If you want to make a QtQuick app use the `quick_app` folder. For a QtWidgets app use the `widgets_app` folder.

5. Edit the `CMakeLists.txt` file and set the `CMAKE_PREFIX_PATH` variable to your Qt bin path as described in 2.

## Build a debug version
Just run `./build.sh` in your app root directory. It will create a `build` directory and compile the app. On every run the script removes the build directory entirely. To prevent this, go to the build directory and run `make`.

## Build a release version and deploy
1. Check that the program `macdeployqt` is within your PATH variable.

```
$ which macdeployqt
$ ~/sourcecode/sdk/QtLatest/5.12.0/clang_64/bin/macdeployqt
```

2. In the folder `res/` there is a file `AppIcon.icns` and `AppIcon.png`. Replace these files with your AppIcon. 

3. In `CMakeLists.txt` on line 26 and following set the variables to your needs.

4. Again run `./build.sh release` in your app root directory but with parameter `release`:

```
$ ./build.sh release
```

Now there is a bundle `AppName.app` in the build folder ready to ship.

## Test
Tested with the following environment:

- macOS Mojave 10.14.3 
- Sublime Text 3
- Qt 5.12 clang_64
- CMake 3.13.3
