/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DEBUG_PIN_RED_Pin GPIO_PIN_13
#define DEBUG_PIN_RED_GPIO_Port GPIOC
#define DEBUG_PIN_BLUE_Pin GPIO_PIN_15
#define DEBUG_PIN_BLUE_GPIO_Port GPIOC
#define NRST_Pin GPIO_PIN_10
#define NRST_GPIO_Port GPIOG
#define MOTOR_DRV_SOC_Pin GPIO_PIN_1
#define MOTOR_DRV_SOC_GPIO_Port GPIOC
#define MOTOR_DRV_SOB_Pin GPIO_PIN_2
#define MOTOR_DRV_SOB_GPIO_Port GPIOC
#define MOTOR_DRV_SOA_Pin GPIO_PIN_3
#define MOTOR_DRV_SOA_GPIO_Port GPIOC
#define BEMF_C_Pin GPIO_PIN_0
#define BEMF_C_GPIO_Port GPIOA
#define BEMF_B_Pin GPIO_PIN_1
#define BEMF_B_GPIO_Port GPIOA
#define BEMF_A_Pin GPIO_PIN_2
#define BEMF_A_GPIO_Port GPIOA
#define HALL_SPI_CS_Pin GPIO_PIN_4
#define HALL_SPI_CS_GPIO_Port GPIOA
#define HALL_SPI_SCK_Pin GPIO_PIN_5
#define HALL_SPI_SCK_GPIO_Port GPIOA
#define HALL_SPI_MISO_Pin GPIO_PIN_6
#define HALL_SPI_MISO_GPIO_Port GPIOA
#define HALL_SPI_MOSI_Pin GPIO_PIN_7
#define HALL_SPI_MOSI_GPIO_Port GPIOA
#define HALL_ALERT_Pin GPIO_PIN_4
#define HALL_ALERT_GPIO_Port GPIOC
#define USER_LED_Pin GPIO_PIN_0
#define USER_LED_GPIO_Port GPIOB
#define USER_BUTTON_Pin GPIO_PIN_1
#define USER_BUTTON_GPIO_Port GPIOB
#define VBAT_SENSE_Pin GPIO_PIN_11
#define VBAT_SENSE_GPIO_Port GPIOB
#define MOTOR_DRV_INLA_Pin GPIO_PIN_13
#define MOTOR_DRV_INLA_GPIO_Port GPIOB
#define MOTOR_DRV_INLB_Pin GPIO_PIN_14
#define MOTOR_DRV_INLB_GPIO_Port GPIOB
#define MOTOR_DRV_INLC_Pin GPIO_PIN_15
#define MOTOR_DRV_INLC_GPIO_Port GPIOB
#define MOTOR_DRV_NFAULT_Pin GPIO_PIN_7
#define MOTOR_DRV_NFAULT_GPIO_Port GPIOC
#define MOTOR_DRV_NSLEEP_Pin GPIO_PIN_8
#define MOTOR_DRV_NSLEEP_GPIO_Port GPIOC
#define MOTOR_DRV_INHA_Pin GPIO_PIN_8
#define MOTOR_DRV_INHA_GPIO_Port GPIOA
#define MOTOR_DRV_INHB_Pin GPIO_PIN_9
#define MOTOR_DRV_INHB_GPIO_Port GPIOA
#define MOTOR_DRV_INHC_Pin GPIO_PIN_10
#define MOTOR_DRV_INHC_GPIO_Port GPIOA
#define CAN_TRCV_STB_Pin GPIO_PIN_11
#define CAN_TRCV_STB_GPIO_Port GPIOC
#define UART_TX_Pin GPIO_PIN_6
#define UART_TX_GPIO_Port GPIOB
#define UART_RX_Pin GPIO_PIN_7
#define UART_RX_GPIO_Port GPIOB
#define BOOT_Pin GPIO_PIN_8
#define BOOT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
