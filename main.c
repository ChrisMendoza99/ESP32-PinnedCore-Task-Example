#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
/*
    Code was made by Christopher A. Mendoza
    UTEP 2022
    last edited: 11/3/2022
*/

/*Task Handlers*/
TaskHandle_t Task1;
TaskHandle_t Task2;

void Task_code1(void *parameter)
{
    while(1)
    {
        printf("Task 1 running [%i]\n", xTaskGetTickCount());
        vTaskDelay(2500 / portTICK_PERIOD_MS); 
    }

}
void Task_code2(void *parameter)
{
    while(1)
    {
        printf("Task 2 running [%i]\n", xTaskGetTickCount());
   
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        
    }
}

void app_main(void)
{

    /*Creation of the Task pinned to a core*/
    /*
    xTaskCreatePinnedToCore(
        task function name,
        "insert name of the task"
        ,stack size,
        task input parameter,
        priority level, 
        task handle ,
        taskCore
        );
    */
    xTaskCreatePinnedToCore(Task_code1,"Task_1",2048,NULL,2, &Task1 ,0);
    xTaskCreatePinnedToCore(Task_code2,"Task_2",2048,NULL,2, &Task2 ,1);

}