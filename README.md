
# What's all this then?

TBD

# How to compile

## You will need

- cmake
- GNU make
- The AVR toolchain (on ubuntu Linux this can be obtained by running `apt install gcc-avr`)
- The AVR libraries/headers (on ubuntu linux this can be obtained by running `apt install avr-libc`)

## Commands

> [!NOTE]
> Before you compile, check the model number of the Atmel chip you are compiling for.
> Change lines 7 and 8 of [CMakeLists.txt](./src/CMakeLists.txt) to reflect the correct chip
> Line 7 is to tell the compiler/linker/programmer and line 8 is to ensure that the right code gets compiled in

```bash
cd src
cmake . -DCMAKE_TOOLCHAIN_FILE=generic-gcc-avr.cmake
make
```

This will output a file called `atmega-xmas-star.hex`

# How to flash to the device

```bash
avrdude -p m48 -Uflash:w:atmega-xmas-star.hex -c usbtiny
```

> [!NOTE]
> - Change the value of the `-p` parameter to reflect the chip you are sending to
> - Change the value of the `-c` parameter to reflect the programmer you are using.
>
> See `avrdude` docs for more details.

# Attributions
Thanks to Matthias Kleeman for the cmake AVR configuration file [generic-gcc-avr.cmake](https://github.com/mkleemann/cmake-avr/blob/master/generic-gcc-avr.cmake)