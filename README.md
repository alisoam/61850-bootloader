# Bootloader

## Requirements
- gcc for arm processors
``` sh
sudo apt install gcc-arm-none-eabi
```

## Build
for the  first time (update the Toolchain.cmake if it is necessary):
``` sh
cp Toolchain.sample.cmake Toolchain.cmake
mkdir build && cd build
cmake ../
```
