# Configuration overview

## Description

This folder contains an empty project in STM32CubeIDE with the MCU configuration required for further software development. It serves as a project base.

<img src="https://github.com/user-attachments/assets/aefd9759-3e74-452f-96d7-2dcceb505311" width="720"/>

### Clock Configuration
- HSE Value: 24 MHz (Quartz crystal frequency)
- System Clock Frequency: 160 MHz (AHB, APB1, APB2)
- Pins: PF0 [RCC_OSC_IN], PF1: [RCC_OSC_OUT]

### ADC
TODO

### CAN FD
- Baud Rate (Nominal): 1 Mbps
- Baud Rate (Data): 5 Mbps
- Pins: PA11 [CANFD_RX], PA12[CANFD_TX]
  
### SPI - TMAG5170 Hall sensor
- Calculated Baud Rate: 10 Mbps
- SPI mode: 0 (CPOL=0, CPHA=0)
- Data Size: 8-bit
- Direction: 2-line (Full Duplex)
- Pins: PA4 [HALL_SPI_CS], PA5 [HALL_SPI_SCK], PA6: [HALL_SPI_MISO], PA7 [HALL_SPI_MOSI]
  
### UART - Debug
- Baud Rate: 460800 bps
- Pins: PB6 [UART_TX], PB7 [UART_RX]

### Timer - PWM
TODO

### Serial wire debug
- Pins: PA13: [SWD_SWDIO], PA14 [SWD_SWCLK]

### Other GPIO - TODO

// ADC
- PA0: BEMF_C (ADC1_IN1)
- PA1: BEMF_B (ADC1_IN2)
- PA2: BEMF_A (ADC1_IN3)
- PC1: MOTOR_DRV_SOC (ADC1_IN7)
- PC2: MOTOR_DRV_SOB (ADC1_IN8)
- PC3: MOTOR_DRV_SOA (ADC1_IN9)
- PB11: VBAT_SENSE (ADC1_IN14)

// PWM
- PA8: MOTOR_DRV_INHA (TIM1_CH1)
- PA9: MOTOR_DRV_INHB (TIM1_CH2)
- PA10: MOTOR_DRV_INHC (TIM1_CH3)
- PB13: MOTOR_DRV_INLA (TIM1_CH1N)
- PB14: MOTOR_DRV_INLB (TIM1_CH2N)
- PB15: MOTOR_DRV_INLC (TIM1_CH3N)

// GPIO
- PB0: USER_LED - TODO
- PB1: USER_BUTTON - TODO
- PB8: BOOT - TODO
- PC4: HALL_ALERT - Hall sensor interrupt
- PC7: MOTOR_DRV_NFAULT - TODO
- PC8: MOTOR_DRV_NSLEEP - TODO
- PC11: CAN_TRCV_STB - TODO
- PC13: DEBUG_PIN_RED - TODO
- PC15: DEBUG_PIN_BLUE - TODO
- PG10: NRST - TODO
