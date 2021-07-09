#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#define RED_LED 18
#define GREEN_LED 17
#define BLUE_LED 16

#define GPIO_ON     1
#define GPIO_OFF    0

void GreenLEDTask(void *param)
{
	for( ;; )
	{
		gpio_put(GREEN_LED, GPIO_ON);
		vTaskDelay(50);
		gpio_put(GREEN_LED, GPIO_OFF);
		vTaskDelay(100);
        	gpio_put(GREEN_LED, GPIO_ON);
		vTaskDelay(50);
		gpio_put(GREEN_LED, GPIO_OFF);
		vTaskDelay(100);
        	gpio_put(GREEN_LED, GPIO_ON);
		vTaskDelay(50);
		gpio_put(GREEN_LED, GPIO_OFF);
		vTaskDelay(100);
        	gpio_put(GREEN_LED, GPIO_ON);
		vTaskDelay(50);
		gpio_put(GREEN_LED, GPIO_OFF);
		vTaskDelay(300);
	}
}

void RedLEDTask(void *param)
{
	for( ;; )
	{
		gpio_put(RED_LED, GPIO_ON);
		vTaskDelay(750);
		gpio_put(RED_LED, GPIO_OFF);
		vTaskDelay(750);
	}
}

void BlueLEDTask(void *param)
{
	for( ;; )
	{
		gpio_put(BLUE_LED, GPIO_ON);
		vTaskDelay(50);
		gpio_put(BLUE_LED, GPIO_OFF);
		vTaskDelay(200);
        	gpio_put(BLUE_LED, GPIO_ON);
		vTaskDelay(50);
		gpio_put(BLUE_LED, GPIO_OFF);
		vTaskDelay(200);
        	gpio_put(BLUE_LED, GPIO_ON);
		vTaskDelay(50);
		gpio_put(BLUE_LED, GPIO_OFF);
		vTaskDelay(1000);
	}
}


int main() 
{
    stdio_init_all();

    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);

    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);

    gpio_init(BLUE_LED);
    gpio_set_dir(BLUE_LED, GPIO_OUT);

    TaskHandle_t gLEDtask = NULL;
    TaskHandle_t rLEDtask = NULL;
    TaskHandle_t bLEDtask = NULL;

	BaseType_t xReturned;
    \
	xReturned = xTaskCreate(
                    GreenLEDTask,
                    "Green LED",
                    512,
                    NULL,
                    1,
                    &gLEDtask);

    xReturned = xTaskCreate(
                    RedLEDTask,
                    "Red LED",
                     512,
                     NULL,
                     1,
                     &rLEDtask);
    
    xReturned = xTaskCreate(
                    BlueLEDTask,
                    "Blue LED",
                     512,
                     NULL,
                     1,
                     &bLEDtask);

    vTaskStartScheduler();

    while(1)
    {
        configASSERT(0);    /* We should never get here */
    }

}
