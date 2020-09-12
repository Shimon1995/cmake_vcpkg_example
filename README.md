# Cmake vcpkg example

## Usage

You're free to scale your project inside ```src/``` directory, `CMakeLists.txt` file is already set up for this.

To add a library to your project 
- list its names in dependencies vcpkg.json.
- run vcpkg install <library>
- integrate a library for IDE vcpkg integrate install
- add two lines of code to CMakeLists.txt file
```CMake
find_package(<library> CONFIG REQUIRED)
target_link_libraries(example PRIVATE <library>)
```
 
## Running Project

If you use UNIX, cmake may be denied access to launch vcpkg, to prevent this, recursively change the ownership of the vcpkg directory to yourself from root or use sudo to launch cmake. If you decided to use sudo as a prefix, `build/` directory will be owned by root, so you'd need to apply either of previos steps about build/ directory.

```sh
$ cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}scripts/buildsystems/vcpkg.cmake
$ cmake --build build/
$ ./build/example
```