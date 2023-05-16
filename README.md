# Bootloader
Bootloader of the 61850 board.
For more information and documentation see [here](https://github.com/alisoam/61850-docs).

## Requirements
- gcc for arm processors
``` sh
sudo apt install gcc-arm-none-eabi
```

- cmake
``` sh
sudo apt install cmake
```

- JLink
Download from [here](https://www.segger.com/downloads/jlink/)


## For the First Time
- create the Toolchain.cmake from Toolchain.sample.cmake
- run the following commands:
```
make init
```


## Development
### Build
``` sh
make
```

### Program
``` sh
make program
```
