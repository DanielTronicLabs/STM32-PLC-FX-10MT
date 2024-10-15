/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//C:\Users\USUARIO\STM32CubeIDE\workspace_1.16.0\PRUEBA_FX_6MT\Debug
char msg0[] = "entrada1\r\n";
char msg1[] = "entrada1\r\n";
char msg2[] = "entrada2\r\n";
char msg3[] = "entrada3\r\n";
char msg4[] = "entrada4\r\n";
char msg5[] = "entrada5\r\n";
char btn1[] = "boton -\r\n";
char btn2[] = "boton +\r\n";
char btn3[] = "boton ^\r\n";
char btn4[] = "boton set\r\n";
int j = 0;
int i = 0;
//uint8_t led[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
uint8_t led[8] = { 0x02, 0x01, 0x10, 0x20, 0x04, 0x08, 0x40, 0x80 };
uint8_t display[17] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t segment_map[10] = { 0x3F, // 0: 0b00111111 -> A, B, C, D, E, F encendidos (G y DP apagados)
		0x06,  // 1: 0b00000110 -> B, C encendidos (A, D, E, F, G y DP apagados)
		0x5B,  // 2: 0b01011011 -> A, B, D, E, G encendidos (C, F y DP apagados)
		0x4F,  // 3: 0b01001111 -> A, B, C, D, G encendidos (E, F y DP apagados)
		0x66,  // 4: 0b01100110 -> B, C, F, G encendidos (A, D, E y DP apagados)
		0x6D,  // 5: 0b01101101 -> A, C, D, F, G encendidos (B, E y DP apagados)
		0x7D,  // 6: 0b01111101 -> A, C, D, E, F, G encendidos (B y DP apagados)
		0x07,  // 7: 0b00000111 -> A, B, C encendidos (D, E, F, G y DP apagados)
		0x7F,  // 8: 0b01111111 -> Todos los segmentos encendidos (DP apagado)
		0x6F, // 9: 0b01101111 -> A, B, C, D, F, G encendidos (E y DP apagados)
		};
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		/* Lee el estado del botón (pin PC13) */
		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET) // ENTRADA X0
				{
			HAL_UART_Transmit(&huart2, (uint8_t*) msg0, strlen(msg0),
			HAL_MAX_DELAY);
			/* Esperar 1 segundo */
			i = 0;
			HAL_Delay(1000);
		}

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == GPIO_PIN_RESET) // ENTRADA X1
				{
			HAL_UART_Transmit(&huart2, (uint8_t*) msg1, strlen(msg1),
			HAL_MAX_DELAY);
			/* Esperar 1 segundo */
			///HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);// BUZZER ON
			i = 1;
			HAL_Delay(1000);
			///HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); // BUZZER OFF
			///HAL_Delay(1000);
		}

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == GPIO_PIN_RESET) // ENTRADA X2
				{
			HAL_UART_Transmit(&huart2, (uint8_t*) msg2, strlen(msg2),
			HAL_MAX_DELAY);
			/* Esperar 1 segundo */
			i = 2;
			HAL_Delay(1000);
		}

		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == GPIO_PIN_RESET) // ENTRADA X3
				{
			HAL_UART_Transmit(&huart2, (uint8_t*) msg3, strlen(msg3),
			HAL_MAX_DELAY);
			/* Esperar 1 segundo */
			i = 3;
			HAL_Delay(1000);
		}

		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) == GPIO_PIN_RESET) // ENTRADA X4
				{
			HAL_UART_Transmit(&huart2, (uint8_t*) msg4, strlen(msg4),
			HAL_MAX_DELAY);
			/* Esperar 1 segundo */
			i = 4;
			HAL_Delay(1000);
		}
		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) == GPIO_PIN_RESET) // ENTRADA X5
				{
			HAL_UART_Transmit(&huart2, (uint8_t*) msg5, strlen(msg5),
			HAL_MAX_DELAY);
			/* Esperar 1 segundo */
			i = 5;
			HAL_Delay(1000);
		}

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == GPIO_PIN_RESET) // BOTON -
				{
			HAL_UART_Transmit(&huart2, (uint8_t*) btn1, strlen(btn1),
			HAL_MAX_DELAY);
			/* Esperar 1 segundo */
			i = 6;
			HAL_Delay(100);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
		} else {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
		}

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == GPIO_PIN_RESET) // BOTON +
				{
			HAL_UART_Transmit(&huart2, (uint8_t*) btn2, strlen(btn2),
			HAL_MAX_DELAY);
			/* Esperar 1 segundo */
			i = 7;
			HAL_Delay(100);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
		} else {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
		}

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == GPIO_PIN_RESET) // BOTON ^
				{
			HAL_UART_Transmit(&huart2, (uint8_t*) btn3, strlen(btn3),
			HAL_MAX_DELAY);
			/* Esperar 1 segundo */
			HAL_Delay(100);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
		}

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == GPIO_PIN_RESET) // BOTON set
				{
			HAL_UART_Transmit(&huart2, (uint8_t*) btn4, strlen(btn4),
			HAL_MAX_DELAY);
			/* Esperar 1 segundo */
			HAL_Delay(100);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
		}

		display[0] = segment_map[0];
		display[1] = segment_map[1];
		display[2] = segment_map[2];
		display[3] = segment_map[3];
		display[4] = led[i]; // LED INDICADOR
		display[5] = segment_map[4];
		display[6] = segment_map[5];
		display[7] = segment_map[6];
		display[8] = segment_map[7];
		display[9] = segment_map[8];
		display[10] = segment_map[9];
		display[11] = segment_map[0];
		display[12] = 0X00; // no existe
		display[13] = segment_map[1];
		display[14] = segment_map[2];
		display[15] = segment_map[3];
		display[16] = segment_map[4];

		TM1640_Start();
		TM1640_SendByte(0x40); // Configurar en modo escritura
		TM1640_Stop();

		TM1640_Start();
		TM1640_SendByte(0xC0); // Dirección inicial de la memoria del display
		TM1640_Stop();

		TM1640_Start();
		for (j = 0; j < 17; j++)  //�?��?16�?显示数�?�
				{
			TM1640_SendByte(display[j]);
		}
		TM1640_Stop();

		TM1640_Start();
		TM1640_SendByte(0x8C); // control display
		TM1640_Stop();

	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA8 PA9 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB11 PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB3 PB4 PB6 PB7
                           PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void TM1640_Delay(void) {
	// Retraso breve (dependiendo de tu frecuencia de reloj)
	HAL_Delay(1);
}

void TM1640_Start(void) {
	// Iniciar la comunicación
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET); // CLOCK
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET); // DATA
	TM1640_Delay();
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET); // DATA
}

void TM1640_Stop(void) {
	// Terminar la comunicación
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET); // CLOCK
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET); // DATA
	TM1640_Delay();
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET); // CLOCK
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET); // DATA
}

void TM1640_SendByte(uint8_t data) {
	// Enviar un byte de datos al TM1640
	for (int i = 0; i < 8; i++) {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET); // CLOCK
		TM1640_Delay();
		if (data & 0x01) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET); // DATA
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET); // DATA
		}
		data >>= 1;
		TM1640_Delay();
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET); // CLOCK
		TM1640_Delay();
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

