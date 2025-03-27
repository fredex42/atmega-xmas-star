cmake_minimum_required(VERSION 3.10)

# Set project name and language
project(AtmegaXmasStar C)

# Set MCU type and flags
set(MMCU_TYPE atmega48)
set(CMAKE_C_FLAGS "-D__AVR_ATmega48P__")

find_path(AVR_SYS_HEADERS "avr/interrupt.h" "avr/io.h" HINTS "/usr/include/avr" "/usr/lib/avr/include" "/usr/lib/avr/include" "/usr/lib/avr/aarch64-linux-gnu/include" REQUIRED)
# # Set AVR tools path (if needed)
# set(AVR_GCC_PATH /usr/bin/avr-gcc)

# Add the source files
set(SOURCES
    main.c
    gpio.c
    timer.c
)

# Create the executable (with .elf extension)
add_executable(atmega-xmas-star.elf ${SOURCES})

# # Specify the compiler flags for the AVR platform
set_target_properties(atmega-xmas-star.elf PROPERTIES
    COMPILE_OPTIONS "-I${AVR_SYS_HEADERS} -mmcu=${MMCU_TYPE}"
    LINK_OPTIONS "-mmcu=${MMCU_TYPE}"
)

# Add custom command to generate the .hex file from the .elf file
add_custom_command(TARGET atmega-xmas-star.elf POST_BUILD
    COMMAND avr-objcopy -j .text -j .data -O ihex $<TARGET_FILE:atmega-xmas-star.elf> atmega-xmas-star.hex
    COMMENT "Generating HEX file"
)

# Clean command (automatically handled by CMake)
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "*.hex")
