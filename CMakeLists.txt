cmake_minimum_required (VERSION 3.7)
SET(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

add_compile_definitions(XIP_BOOT_HEADER_ENABLE=1)
add_compile_definitions(XIP_EXTERNAL_FLASH=1)
add_compile_definitions(__Vectors=__isr_vector)
add_compile_definitions(__Vectors=__isr_vector)

project(bootloader)

set(CMAKE_CXX_COMPILER /home/ali/.local/bin/arm-none-eabi-g++)
set(CMAKE_C_COMPILER /home/ali/.local/bin/arm-none-eabi-gcc)
set(CMAKE_AR /home/ali/.local/bin/arm-none-eabi-ar)
SET(CMAKE_LINKER /home/ali/.local/bin/arm-none-eabi-gcc)
SET(CMAKE_OBJCOPY /home/ali/.local/bin/arm-none-eabi-objcopy)

SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -DDEBUG")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -g")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -D__STARTUP_CLEAR_BSS")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -D__STARTUP_INITIALIZE_NONCACHEDATA")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mcpu=cortex-m7")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -Wall")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mfloat-abi=hard")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mfpu=fpv5-d16")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mthumb")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -fno-common")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -ffunction-sections")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -fdata-sections")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -ffreestanding")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -fno-builtin")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mapcs")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -std=gnu99")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDEBUG")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCPU_MIMXRT1062DVL6A")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DFSL_RTOS_FREE_RTOS")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-m7")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfloat-abi=hard")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfpu=fpv5-d16")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mthumb")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -MMD")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -MP")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-common")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffunction-sections")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fdata-sections")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffreestanding")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-builtin")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mapcs")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCPU_MIMXRT1062DVL6A")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFSL_RTOS_FREE_RTOS")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-m7")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfloat-abi=hard")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfpu=fpv5-d16")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mthumb")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -MMD")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -MP")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-common")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffunction-sections")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdata-sections")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffreestanding")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-builtin")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mapcs")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu99")

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -g")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mcpu=cortex-m7")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wall")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mfloat-abi=hard")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mfpu=fpv5-d16")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --specs=nano.specs")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --specs=nosys.specs")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fno-common")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -ffunction-sections")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fdata-sections")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -ffreestanding")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fno-builtin")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mthumb")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mapcs")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --gc-sections")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -z")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} muldefs")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Map=output.map")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -u _printf_float")

set(LINKER_SCRIPT "system/MIMXRT1062xxxxx_flexspi_nor.ld")

# -Xlinker --wrap=malloc -Xlinker --wrap=free
set (CMAKE_C_LINK_EXECUTABLE "<CMAKE_LINKER> ${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/${LINKER_SCRIPT} <OBJECTS> <LINK_LIBRARIES> -o <TARGET>")
set (CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_LINKER> ${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/${LINKER_SCRIPT} <OBJECTS> <LINK_LIBRARIES> -o <TARGET>")

include_directories(
  ./include
  ./include/usb
  ./board
  ./include/FreeRTOS
  ./modules/FreeRTOS/portable/GCC/ARM_CM4F
)

include(device.cmake)
include(FreeRTOS.cmake)

add_executable(bootloader.elf
  ./board/clock_config.c
  ./board/peripherals.c
  ./board/pin_mux.c
  ./board/board.c

  #  ./system/startup.S
  #  ./system/startup.c

  ./system/startup_MIMXRT1062.S

  ./system/evkmimxrt1060_flexspi_nor_config.c
  ./system/evkmimxrt1060_sdram_ini_dcd.c
  ./system/fsl_flexspi_nor_boot.c

  ./system/syscalls.c
  ./system/utils/fsl_sbrk.c
  ./system/base_handlers.c
  #./source/FreeRTOS/freertos_heap.c
  ./source/FreeRTOS/freertos_hooks.c
  ./modules/FreeRTOS/portable/GCC/ARM_CM4F/port.c
  ./modules/FreeRTOS/portable/MemMang/heap_4.c

  #./source/usb/usb_device_cdc_acm.c
  #./source/usb/usb_device_ch9.c
  #./source/usb/usb_device_class.c
  #  ./source/usb/usb_device_descriptor.c
  #  ./source/usb/virtual_com.c

  ./source/swo.c
  ./source/main.c
  ./source/mem_test.c
  ./source/mem_test_runner.c
)

target_link_libraries(bootloader.elf
  device
  FreeRTOS
)

target_include_directories(bootloader.elf PUBLIC
)

#set_target_properties(bootloader.elf PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})

set_property(SOURCE ./system/startup_MIMXRT1062.S PROPERTY LANGUAGE C)

add_custom_command(TARGET ${PROJECT_NAME}.elf
  POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} ARGS -O srec   ${PROJECT_NAME}.elf ${PROJECT_NAME}.srec
  COMMAND ${CMAKE_OBJCOPY} ARGS -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
)