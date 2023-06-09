cmake_minimum_required (VERSION 3.7)
set(CMAKE_TOOLCHAIN_FILE "Toolchain.cmake")
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

add_compile_definitions(XIP_BOOT_HEADER_ENABLE=1)
add_compile_definitions(XIP_EXTERNAL_FLASH=1)
#add_compile_definitions(__Vectors=__isr_vector)
#add_compile_definitions(__Vectors=__isr_vector)

project(bootloader)

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -DDEBUG")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -g")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -D__STARTUP_CLEAR_BSS")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -D__STARTUP_INITIALIZE_NONCACHEDATA")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mcpu=cortex-m7")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -Wall")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mfloat-abi=hard")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mfpu=fpv5-d16")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mthumb")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -fno-common")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -ffunction-sections")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -fdata-sections")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -ffreestanding")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -fno-builtin")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mapcs")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -std=gnu99")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -fno-exceptions")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -fno-unwind-tables")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDEBUG")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCPU_MIMXRT1062DVL6A")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DFSL_RTOS_FREE_RTOS")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-m7")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfloat-abi=hard")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfpu=fpv5-d16")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mthumb")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -MMD")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -MP")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-common")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffunction-sections")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fdata-sections")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffreestanding")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-builtin")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mapcs")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-exceptions")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-unwind-tables")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCPU_MIMXRT1062DVL6A")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFSL_RTOS_FREE_RTOS")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-m7")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfloat-abi=hard")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfpu=fpv5-d16")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mthumb")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -MMD")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -MP")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-common")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffunction-sections")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdata-sections")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffreestanding")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-builtin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mapcs")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=g++99")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -g")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mcpu=cortex-m7")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wall")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mfloat-abi=hard")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mfpu=fpv5-d16")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --specs=nano.specs")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --specs=nosys.specs")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fno-common")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -ffunction-sections")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fno-builtin")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mthumb")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mapcs")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --gc-sections")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -z")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} muldefs")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Map=output.map")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -u _printf_float")

set(LINKER_SCRIPT "system/device.ld")

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

  ./system/startup.S

  ./system/fsl_flexspi_nor_boot.c
  ./system/flexspi_nor_config.c
  ./system/sdram_ini_dcd.c

  ./system/syscalls.c
  ./system/utils/fsl_sbrk.c
  ./system/handlers.c
  #./source/FreeRTOS/freertos_heap.c
  ./source/FreeRTOS/freertos_hooks.c
  ./modules/FreeRTOS/portable/GCC/ARM_CM4F/port.c
  ./modules/FreeRTOS/portable/MemMang/heap_4.c

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

set_target_properties(bootloader.elf PROPERTIES LINK_DEPENDS ${CMAKE_SOURCE_DIR}/${LINKER_SCRIPT})

set_property(SOURCE ./system/startup.S PROPERTY LANGUAGE C)

add_custom_command(TARGET ${PROJECT_NAME}.elf
  POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} ARGS -O srec   ${PROJECT_NAME}.elf ${PROJECT_NAME}.srec
  COMMAND ${CMAKE_OBJCOPY} ARGS -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
)
