#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
	/* setting all LED lights like red green and blue state to false */
	Board_LED_Set(0, true);
	Board_LED_Set(1, true);
	Board_LED_Set(2, true);
}
/* red light*/
static void vLEDRed(void *pvParameters)
{
	bool LedState = false;
	while (1)
	{

		Board_LED_Set(0, LedState);
		/* 1 sec on */
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(0, !LedState); //setting the state to off

		/* 0.5 sec off */
		vTaskDelay(3 * configTICK_RATE_HZ + configTICK_RATE_HZ / 2);
	}

}

/* green light */
static void vLEDGreen(void *pvParameters)
{
	bool LedState = false;
	vTaskDelay(configTICK_RATE_HZ + configTICK_RATE_HZ / 2);
	while (1)
		
	{

		Board_LED_Set(1, LedState);
		/* 1 sec on */
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(1, !LedState); //setting the state to off
		/* 0.5 sec off */
		vTaskDelay(3 * configTICK_RATE_HZ + configTICK_RATE_HZ / 2);
	}

}
/* Blue light */
static void vLEDBlue(void *pvParameters)
{
	bool LedState = false;
	vTaskDelay(3 * configTICK_RATE_HZ);
	while (1)
	{

		Board_LED_Set(2, LedState);
		/* 1 sec on */
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(2, !LedState); //setting the state to off
		/* 0.5 sec off */
		vTaskDelay(3 * configTICK_RATE_HZ + configTICK_RATE_HZ / 2);
	}

}
int main(void)
{
	prvSetupHardware();

	xTaskCreate(vLEDRed, (signed char* ) "vLEDRed", configMINIMAL_STACK_SIZE,
			NULL, (tskIDLE_PRIORITY + 3UL), (xTaskHandle*) NULL);

	xTaskCreate(vLEDGreen, (signed char* ) "vLEDGreen",
			configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 2UL),
			(xTaskHandle*) NULL);

	xTaskCreate(vLEDBlue, (signed char* ) "vLEDBlue", configMINIMAL_STACK_SIZE,
			NULL, (tskIDLE_PRIORITY + 1UL), (xTaskHandle*) NULL);
	/* Start the scheduler */
	vTaskStartScheduler();
	/* Should never arrive here */
	return 1;

}
