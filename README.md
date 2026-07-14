# STM32F407 Discovery Learning Project

## Overview

This project is a hands-on embedded software learning platform for the STM32F407 Discovery board. It demonstrates how to build a modular firmware application using FreeRTOS, the STM32 HAL, and C++ while following a professional embedded software architecture.

The main goal is to create a solid foundation for embedded development by combining real-time operating systems, hardware abstraction layers, and maintainable application design.

## Objectives

- Learn embedded firmware development on the STM32F407 platform
- Integrate FreeRTOS with STM32 HAL and C++
- Build a layered and maintainable software architecture
- Use CMake as a reproducible build system for embedded projects

## Technologies Used

- Microcontroller: STM32F407VGTx
- RTOS: FreeRTOS with CMSIS-RTOS V2
- HAL: STM32F4xx HAL Driver
- Core libraries: ARM CMSIS Core and DSP libraries
- Programming languages: C and C++17
- Build system: CMake
- Toolchain: arm-none-eabi-gcc / arm-none-eabi-g++
- Programming/debugging: OpenOCD and ST-LINK

## Software Architecture

The project is organized around clear separation of concerns:

- Application: user-facing application logic and task behavior
- Boards: board-specific initialization and hardware configuration
- Components: reusable abstractions for communication and peripheral services
- Drivers: low-level hardware driver implementations
- ThirdParty: vendor and third-party libraries such as CMSIS, HAL, and FreeRTOS

## Project Structure

```text
.
├── Application/
├── Boards/
│   └── v1/
│       └── CubeMX-Generated/
├── Components/
├── Drivers/
├── ThirdParty/
├── cmake/
└── CMakeLists.txt
```

## Prerequisites

Before building the project, make sure the following tools are installed:

- ARM GNU Toolchain
- CMake
- Make or Ninja
- OpenOCD
- ST-LINK drivers (if required by your host system)

## Building the Project

From the project root, run:

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

You can also build directly from the repository root:

```bash
cmake --build build
```

## Flashing the Firmware

Ensure the STM32F407 Discovery board is connected through ST-LINK. After building the firmware, flash it using a suitable debugger or programmer tool such as OpenOCD.

Example workflow:

```bash
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg
```

Then flash the generated firmware binary from another terminal session using your preferred flashing command.

## Usage

After successful flashing, the firmware will start the embedded application and demonstrate the basic architecture and task-based execution model of the project.

This repository is intended for learning, experimentation, and gradual feature development.
