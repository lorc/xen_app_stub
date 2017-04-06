# XEN Native application template

## Build instructions

Open `toolchain-aarch64.cmake` and correct paths to your aarch64 crosscompiler.

```sh
# mkdir build
# cd build
# cmake ../ -DCMAKE_TOOLCHAIN_FILE=../toolchain-aarch64.cmake
# make
```

Use

```sh
# make
```
to rebuild project if there are any changes.
