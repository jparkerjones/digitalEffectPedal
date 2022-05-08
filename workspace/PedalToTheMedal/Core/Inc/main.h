/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32h7xx_hal.h"

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
#define NAV1_CENTER_Pin GPIO_PIN_2
#define NAV1_CENTER_GPIO_Port GPIOE
#define E3_Pin GPIO_PIN_3
#define E3_GPIO_Port GPIOE
#define NAV1_B_Pin GPIO_PIN_4
#define NAV1_B_GPIO_Port GPIOE
#define NAV1_D_Pin GPIO_PIN_5
#define NAV1_D_GPIO_Port GPIOE
#define NAV1_A_Pin GPIO_PIN_6
#define NAV1_A_GPIO_Port GPIOE
#define KEY_Pin GPIO_PIN_13
#define KEY_GPIO_Port GPIOC
#define NAV1_C_Pin GPIO_PIN_1
#define NAV1_C_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_3
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_1
#define LED2_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_3
#define LED3_GPIO_Port GPIOA
#define INPUT_JACK_DETECT_Pin GPIO_PIN_7
#define INPUT_JACK_DETECT_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_11
#define LCD_CS_GPIO_Port GPIOE
#define LCD_WR_RS_Pin GPIO_PIN_13
#define LCD_WR_RS_GPIO_Port GPIOE
#define EXTERNAL_IO_1_Pin GPIO_PIN_15
#define EXTERNAL_IO_1_GPIO_Port GPIOE
#define BYPASS_DETECT_Pin GPIO_PIN_12
#define BYPASS_DETECT_GPIO_Port GPIOB
#define EXTERNAL_IO_2_Pin GPIO_PIN_13
#define EXTERNAL_IO_2_GPIO_Port GPIOB
#define Output_Jack_Detect_Pin GPIO_PIN_0
#define Output_Jack_Detect_GPIO_Port GPIOD
#define ROT2_BUTTON_Pin GPIO_PIN_5
#define ROT2_BUTTON_GPIO_Port GPIOB
#define ROT2_A_Pin GPIO_PIN_6
#define ROT2_A_GPIO_Port GPIOB
#define ROT2_A_EXTI_IRQn EXTI9_5_IRQn
#define ROT2_B_Pin GPIO_PIN_7
#define ROT2_B_GPIO_Port GPIOB
#define ROT2_B_EXTI_IRQn EXTI9_5_IRQn
#define ROT1_BUTTON_Pin GPIO_PIN_9
#define ROT1_BUTTON_GPIO_Port GPIOB
#define ROT1_A_Pin GPIO_PIN_0
#define ROT1_A_GPIO_Port GPIOE
#define ROT1_A_EXTI_IRQn EXTI0_IRQn
#define ROT1_B_Pin GPIO_PIN_1
#define ROT1_B_GPIO_Port GPIOE
#define ROT1_B_EXTI_IRQn EXTI1_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
