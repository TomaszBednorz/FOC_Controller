cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_C_STANDARD                11)
set(CMAKE_C_STANDARD_REQUIRED       ON)
set(CMAKE_C_EXTENSIONS              ON)
set(CMAKE_CXX_STANDARD              20)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            ON)
set(PROJ_PATH                       ${CMAKE_CURRENT_SOURCE_DIR})
message("Build type: "              ${CMAKE_BUILD_TYPE})

# Core project settings
project(FOC-Controller)
enable_language(C CXX ASM)

# Core MCU flags, CPU, instruction set and FPU setup
set(CPU_PARAMETERS
    -mthumb
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16	
    -mfloat-abi=hard
)

# Set linker script
set(linker_script_SRC               ${PROJ_PATH}/STM32G473RCTX.ld)
set(EXECUTABLE                      ${CMAKE_PROJECT_NAME})

# List of source files to compile
set(sources_SRCS
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_adc.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_adc_ex.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_cordic.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_cortex.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma_ex.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_exti.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_fdcan.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ex.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ramfunc.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_gpio.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr_ex.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc_ex.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_spi.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_spi_ex.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_tim.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_tim_ex.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart_ex.c
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_adc.c
    ${PROJ_PATH}/CUBE/Config/Src/adc.c
    ${PROJ_PATH}/CUBE/Config/Src/cordic.c
    ${PROJ_PATH}/CUBE/Config/Src/fdcan.c
    ${PROJ_PATH}/CUBE/Config/Src/gpio.c
    ${PROJ_PATH}/CUBE/Config/Src/main.c
    ${PROJ_PATH}/CUBE/Config/Src/spi.c
    ${PROJ_PATH}/CUBE/Config/Src/stm32g4xx_hal_msp.c
    ${PROJ_PATH}/CUBE/Config/Src/stm32g4xx_it.c
    ${PROJ_PATH}/CUBE/Config/Src/syscalls.c
    ${PROJ_PATH}/CUBE/Config/Src/sysmem.c
    ${PROJ_PATH}/CUBE/Config/Src/system_stm32g4xx.c
    ${PROJ_PATH}/CUBE/Config/Src/tim.c
    ${PROJ_PATH}/CUBE/Config/Src/usart.c
    ${PROJ_PATH}/CUBE/Startup/startup_stm32g473rctx.s
)

# Include directories
set(include_path_DIRS
    ${PROJ_PATH}/CUBE/Config/Inc
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Inc
    ${PROJ_PATH}/CUBE/STM32G4xx_HAL_Driver/Inc/Legacy
    ${PROJ_PATH}/CUBE/CMSIS/Device/ST/STM32G4xx/Include
    ${PROJ_PATH}/CUBE/CMSIS/Include
)

# Symbols definition
set(symbols_SYMB
    "DEBUG"
    "USE_HAL_DRIVER"
    "STM32G473xx"
)

# Executable files
add_executable(${EXECUTABLE} ${sources_SRCS})

# Include paths
target_include_directories(${EXECUTABLE} PRIVATE ${include_path_DIRS})

# Project symbols
target_compile_definitions(${EXECUTABLE} PRIVATE ${symbols_SYMB})

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
    ${CPU_PARAMETERS}
    -Wall
    -Wextra
    -Wpedantic
    -Wno-unused-parameter
    -O0 -g3 -ggdb
)

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
    -T${linker_script_SRC}
    ${CPU_PARAMETERS}
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
    --specs=nosys.specs
    -u _printf_float                # STDIO float formatting support
    -Wl,--start-group
    -lc
    -lm
    -lstdc++
    -lsupc++
    -Wl,--end-group
    -Wl,--print-memory-usage
)

# Execute post-build to print size
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE}>
)

# Convert output to hex and binary
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.hex
)

# Convert to bin file -> add conditional check?
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.bin
)