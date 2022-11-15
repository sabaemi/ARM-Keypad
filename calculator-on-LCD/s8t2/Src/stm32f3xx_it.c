/**
  ******************************************************************************
  * @file    stm32f3xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2020 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"
#include "stm32f3xx.h"
#include "stm32f3xx_it.h"

/* USER CODE BEGIN 0 */
#include "LiquidCrystal.h"
extern long long int a1;
extern int op;
extern long long int a2;
extern long double eq;
extern char str[100];
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F3xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f3xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles EXTI line0 interrupt.
*/
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */

  /* USER CODE END EXTI0_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
  /* USER CODE BEGIN EXTI0_IRQn 1 */
  for(int i=0;i<4;i++){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_RESET);
		
		if(i==0){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0)){
				if(op==0){
				 a1=a1*10+1;
		     sprintf(str, "%lld", a1);
         setCursor(0,0);
	       print(str);
				}
				if(op!=0){
				 a2=a2*10+1;
		     sprintf(str, "%lld", a2);
         setCursor(0,2);
	       print(str);
				}
			}
		}
		if(i==1){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0)){
				if(op==0){
				 a1=a1*10+2;
		     sprintf(str, "%lld", a1);
         setCursor(0,0);
	       print(str);
				}
					if(op!=0){
				 a2=a2*10+2;
		     sprintf(str, "%lld", a2);
         setCursor(0,2);
	       print(str);
				}
			}
		}
		if(i==2){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0)){
				if(op==0){
				 a1=a1*10+3;
		     sprintf(str, "%lld", a1);
         setCursor(0,0);
	       print(str);
				}
				if(op!=0){
				 a2=a2*10+3;
		     sprintf(str, "%lld", a2);
         setCursor(0,2);
	       print(str);
				}
			}
		}
		if(i==3){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0)){
				op=1;
         setCursor(0,1);
	       print("/");
			}
		}
	}
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET);
	while(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0));
  /* USER CODE END EXTI0_IRQn 1 */
}

/**
* @brief This function handles EXTI line1 interrupt.
*/
void EXTI1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI1_IRQn 0 */

  /* USER CODE END EXTI1_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
  /* USER CODE BEGIN EXTI1_IRQn 1 */
  for(int i=0;i<4;i++){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_RESET);
		
		if(i==0){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1)){
				if(op==0){
				 a1=a1*10+4;
		     sprintf(str, "%lld", a1);
         setCursor(0,0);
	       print(str);
				}
				if(op!=0){
				 a2=a2*10+4;
		     sprintf(str, "%lld", a2);
         setCursor(0,2);
	       print(str);
				}
			}
		}
		if(i==1){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1)){
				if(op==0){
				 a1=a1*10+5;
		     sprintf(str, "%lld", a1);
         setCursor(0,0);
	       print(str);
				}
				if(op!=0){
				 a2=a2*10+5;
		     sprintf(str, "%lld", a2);
         setCursor(0,2);
	       print(str);
				}				
			}
		}
		if(i==2){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1)){
				if(op==0){
				 a1=a1*10+6;
		     sprintf(str, "%lld", a1);
         setCursor(0,0);
	       print(str);
				}
				if(op!=0){
				 a2=a2*10+6;
		     sprintf(str, "%lld", a2);
         setCursor(0,2);
	       print(str);
				}
			}
		}
		if(i==3){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1)){
				op=2;
         setCursor(0,1);
	       print("*");
			}
		}
	}
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET);
	while(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1));
  /* USER CODE END EXTI1_IRQn 1 */
}

/**
* @brief This function handles EXTI line2 and Touch Sense controller.
*/
void EXTI2_TSC_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI2_TSC_IRQn 0 */

  /* USER CODE END EXTI2_TSC_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
  /* USER CODE BEGIN EXTI2_TSC_IRQn 1 */
  for(int i=0;i<4;i++){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_RESET);
		
		if(i==0){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)){
				if(op==0){
				 a1=a1*10+7;
		     sprintf(str, "%lld", a1);
         setCursor(0,0);
	       print(str);
				}
				if(op!=0){
				 a2=a2*10+7;
		     sprintf(str, "%lld", a2);
         setCursor(0,2);
	       print(str);
				}
			}
		}
		if(i==1){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)){
				if(op==0){
				 a1=a1*10+8;
		     sprintf(str, "%lld", a1);
         setCursor(0,0);
	       print(str);
				}
				if(op!=0){
				 a2=a2*10+8;
		     sprintf(str, "%lld", a2);
         setCursor(0,2);
	       print(str);
				}
			}
		}
		if(i==2){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)){
				if(op==0){
				 a1=a1*10+9;
		     sprintf(str, "%lld", a1);
         setCursor(0,0);
	       print(str);
				}
				if(op!=0){
				 a2=a2*10+9;
		     sprintf(str, "%lld", a2);
         setCursor(0,2);
	       print(str);
				}
			}
		}
		if(i==3){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)){
				op=3;
         setCursor(0,1);
	       print("-");
			}
		}
	}
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET);
	while(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2));
  /* USER CODE END EXTI2_TSC_IRQn 1 */
}

/**
* @brief This function handles EXTI line3 interrupt.
*/
void EXTI3_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI3_IRQn 0 */

  /* USER CODE END EXTI3_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
  /* USER CODE BEGIN EXTI3_IRQn 1 */
  for(int i=0;i<4;i++){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_RESET);
		
		if(i==0){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3)){
				clear();
				 a1=0;
         op=0;
         a2=0;
         eq=0;
         str[0]='\0';
			}
		}
		if(i==1){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3)){
				if(op==0){
				 a1=a1*10+0;
		     sprintf(str, "%lld", a1);
         setCursor(0,0);
	       print(str);
				}
				if(op!=0){
				 a2=a2*10+0;
		     sprintf(str, "%lld", a2);
         setCursor(0,2);
	       print(str);
				}
			}
		}
		if(i==2){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3)){
				
				switch(op){
					case 1: {
					if(a2==0){
					 setCursor(0,3);
	         print("can't divide by zero");
					 str[0]='\0';
					}
						else eq=(double)a1/(double)a2;
					}
						break;
					case 2:  eq=(double)a1*(double)a2;
						break;
					case 3:  eq=(double)a1-(double)a2;
						break;
					case 4:  eq=(double)a1+(double)a2;
						break;	
				}
				if( str[0]!='\0'){
		     sprintf(str, "%LF", eq);
         setCursor(0,3);
	       print(str);
				}
				op=0;
			}
		}
		if(i==3){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET);
			if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3)){
				op=4;
         setCursor(0,1);
	       print("+");
			}
		}
	}
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET);
	while(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3));
  /* USER CODE END EXTI3_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
