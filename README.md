<div align="center">

# STM32 Embedded Systems Lab

### Register-level firmware experiments for the STM32F401 microcontroller

`Embedded C` · `STM32F401` · `GPIO` · `ADC` · `Proteus` · `STM32CubeIDE`

</div>

## Overview

This repository contains bare-metal STM32 exercises focused on direct peripheral-register configuration. The projects demonstrate GPIO input/output, button-sequence validation, LED feedback, ADC conversion, and hardware simulation without relying on a high-level application framework.

## Included projects

### Secure Access Sequence Checker

- Reads four push buttons from GPIOA pins.
- Captures a four-button access sequence.
- Compares input against the configured correct sequence.
- Activates a success LED for a valid sequence.
- Activates warning LEDs for an invalid sequence.
- Includes a reset input to clear the current state.

### ADC / Output Control Exercise

- Configures GPIO and ADC1 directly through registers.
- Waits for ADC conversion completion.
- Maps input ranges to multiple GPIO output patterns.
- Uses a push button for an additional output/reset interaction.

## Hardware flow

```mermaid
flowchart LR
    Inputs[Buttons / Analog input] --> GPIOADC[GPIO + ADC registers]
    GPIOADC --> Logic[Firmware state and sequence logic]
    Logic --> Outputs[Status LEDs / output pins]
```

## Repository structure

```text
MostafaMedhat(0522019)Embedded System/
├── SecureAccess_task2/
│   ├── Inc/          Device headers
│   ├── Src/main.c    Access-sequence firmware
│   └── Startup/      STM32 startup assembly
├── exam_stm32_mostafamedhat_0522019/
│   ├── Inc/
│   ├── Src/main.c    ADC and GPIO exercise
│   └── Startup/
└── *.pdsprj          Proteus simulation projects
```

## Requirements

- STM32CubeIDE or a compatible ARM GCC toolchain
- STM32F401 target configuration
- Proteus, if you want to open the included simulation projects
- An STM32F401 board for hardware testing

## Build and run

1. Import the selected project into STM32CubeIDE.
2. Confirm that the MCU target is `STM32F401CCUx`.
3. Build the Debug or Release configuration.
4. Connect the board through ST-LINK and flash the generated firmware.
5. Wire inputs and LEDs to the GPIO pins used in `Src/main.c`, or run the corresponding Proteus simulation.

## Implementation notes

- Peripheral clocks, modes, inputs, and outputs are configured through CMSIS device registers.
- The examples use polling and blocking button-release waits for instructional clarity.
- Pin mappings should be verified in `main.c` before connecting physical hardware.

## Recommended improvements

- Add switch debouncing and non-blocking state machines.
- Move pin definitions and sequences to configuration headers.
- Add circuit diagrams and a short hardware demonstration video.
- Remove generated `Debug/` output files from source control in a future cleanup.

## Author

[Mostafa Medhat](https://github.com/MostafaMedhat19)
