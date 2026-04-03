#include "stm32f10x.h"                  // Device header
#include "FreeRTOS.h"
#include "Task.h"


#include "Delay.h"
#include "LED.h"
#include "Key.h"

TaskHandle_t myTaskHandle;

void myTask(void *arg)
{
	while(1)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
		vTaskDelay(500);
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
		vTaskDelay(500);
	}
}


int main(void)
{
	/*模块初始化*/
	LED_Init();		//LED初始化
	Key_Init();		//按键初始化
	xTaskCreate(myTask,"myTask",128,NULL,2,&myTaskHandle);
	vTaskStartScheduler();	
	while (1)
	{
//		LED1_ON();
//		Delay_ms(500);
//		LED1_OFF();
//		Delay_ms(500);
	}
}
