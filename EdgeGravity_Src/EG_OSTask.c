/*
 *          ___          _____          ___           ___                    ___           ___           ___
 *         /  /\        /  /::\        /  /\         /  /\                  /  /\         /  /\         /  /\          ___        ___           ___         ___
 *        /  /:/_      /  /:/\:\      /  /:/_       /  /:/_                /  /:/_       /  /::\       /  /::\        /__/\      /  /\         /  /\       /__/|
 *       /  /:/ /\    /  /:/  \:\    /  /:/ /\     /  /:/ /\              /  /:/ /\     /  /:/\:\     /  /:/\:\       \  \:\    /  /:/        /  /:/      |  |:|
 *      /  /:/ /:/_  /__/:/ \__\:|  /  /:/_/::\   /  /:/ /:/_            /  /:/_/::\   /  /:/~/:/    /  /:/~/::\       \  \:\  /__/::\       /  /:/       |  |:|
 *     /__/:/ /:/ /\ \  \:\ /  /:/ /__/:/__\/\:\ /__/:/ /:/ /\          /__/:/__\/\:\ /__/:/ /:/___ /__/:/ /:/\:\  ___  \__\:\ \__\/\:\__   /  /::\     __|__|:|
 *     \  \:\/:/ /:/  \  \:\  /:/  \  \:\ /~~/:/ \  \:\/:/ /:/          \  \:\ /~~/:/ \  \:\/:::::/ \  \:\/:/__\/ /__/\ |  |:|    \  \:\/\ /__/:/\:\   /__/::::\
 *      \  \::/ /:/    \  \:\/:/    \  \:\  /:/   \  \::/ /:/            \  \:\  /:/   \  \::/~~~~   \  \::/      \  \:\|  |:|     \__\::/ \__\/  \:\     ~\~~\:\
 *       \  \:\/:/      \  \::/      \  \:\/:/     \  \:\/:/              \  \:\/:/     \  \:\        \  \:\       \  \:\__|:|     /__/:/       \  \:\      \  \:\
 *        \  \::/        \__\/        \  \::/       \  \::/                \  \::/       \  \:\        \  \:\       \__\::::/      \__\/         \__\/       \__\/
 *         \__\/                       \__\/         \__\/                  \__\/         \__\/         \__\/           ~~~~
 *
 *
 * @ 名称: EG_OSTask.c
 * @ 描述:
 * @ 作者: SummerFalls
 * @ 日期: 2020年8月16日
 * @ 版本: V1.0
 * @ 历史: V1.0 2020年8月16日 Summary
 *
 * Copyright (c) 2020 SummerFalls. All rights reserved.
 */

#include "EG_Include.h"

static const char StackOverflowMsg[] = "\r\n\r\n__________xRTOS_FATAL_ERR:\t\tSTACK OVERFLOW...\t\tTaskName:\t";
static const char MallocFailedMsg[] =  "\r\n\r\n__________xRTOS_ERR:\t\tMALLOC FAILED...\r\n\r\n";

volatile uint32_t RunTimeCounter = 0UL;

/*
 *********************************************************************************************************
 *   函 数 名: App_Printf
 *   功能说明: 线程安全的printf方式，支持从中断中调用（但是要求FreeRTOS内核启动之后再使用该函数）
 *   形    参: 同printf的参数。
 *             在C中，当无法列出传递函数的所有实参的类型和数目时,可以用省略号指定参数表
 *   返 回 值: 无
 *********************************************************************************************************
 */
void App_Printf(char *format, ...) {
    char buf_str[512];
    va_list v_args;

    va_start(v_args, format);
    (void) vsnprintf((char*) &buf_str[0], (size_t) sizeof(buf_str), (char const*) format, v_args);
    va_end(v_args);

    /* 互斥信号量 */
    osMutexAcquire(xMutex_printfHandle, osWaitForever);

    printf("%s", buf_str);

    osMutexRelease(xMutex_printfHandle);
}

void vTaskLED(void *argument) {
//    LED_SetBlinkInterval(LED1, 1000, BLINK_MODE_AUTO);

    for (;;) {
//        LED_BlinkProcess();

        /* osDelayUntil 是绝对延时，osDelay 是相对延时 */
        osDelayUntil(OS_LED_DELAY_BASE);
    }
}

void vTaskGUI(void *argument) {
    /* USER CODE BEGIN vTaskGUI */
    MX_TouchGFX_Process();
    /* Infinite loop */
    for (;;) {
        osDelay(10);
    }
    /* USER CODE END vTaskGUI */
}

void vTaskKEY(void *argument) {
    uint8_t KeyVal = 0;

#ifdef USE_PRINTF
    char pcWriteBuffer[512] = { 0 };
#endif

    /* 打印 Logo 及相关信息 */
    UART_PrintPrjInfo(pcWriteBuffer);

    //__ASM volatile("BKPT #0");

    for (;;) {
        if (KEY_Scan(KEY_S1) == KEY_ON) {
#ifdef USE_PRINTF
            PRINTF("=================================================\r\n");
            PRINTF("任务名      任务状态 优先级   剩余栈 任务序号\r\n");
            vTaskList(pcWriteBuffer);
            PRINTF("%s\r\n", pcWriteBuffer);
            PRINTF("B : 阻塞, R : 就绪, D : 删除, S : 暂停\r\n");

//            PRINTF("\r\n任务名称\t运行计数\t使用率\r\n");
//            vTaskGetRunTimeStats(pcWriteBuffer);
//            PRINTF("%s\r\n", pcWriteBuffer);
#endif
        }

        if (KEY_Scan(KEY_S2) == KEY_ON) {
            UART_PrintPrjInfo(pcWriteBuffer);
            KeyVal = 0;
            osMessageQueuePut(GUI_MsgQHandle, &KeyVal, 0, 0);
        }

        if (KEY_Scan(KEY_S3) == KEY_ON) {
            KeyVal = 1;
            osMessageQueuePut(GUI_MsgQHandle, &KeyVal, 0, 0);
        }

        osDelay(200);
//        osThreadYield();
    }
}

/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
void configureTimerForRunTimeStats(void) {
    RunTimeCounter = 0UL;

    /* 开启 FreeRTOS 系统计数定时器，要求中断时间至少为100us(即SysTick的10倍) */
    HAL_TIM_Base_Start_IT(&htim7);
}

unsigned long getRunTimeCounterValue(void) {
    /* RunTimeCounter 在 HAL_TIM_PeriodElapsedCallback() 中自增 */
    return RunTimeCounter;
}

void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName) {
    /* Run time stack overflow checking is performed if
     configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
     called if a stack overflow is detected. */
    const char *pStr = StackOverflowMsg;

    while (*pStr) {
        while (LL_USART_IsActiveFlag_TXE(USART1) == RESET);
        LL_USART_TransmitData8(USART1, *pStr++);
    }

    while (*pcTaskName) {
        while (LL_USART_IsActiveFlag_TXE(USART1) == RESET);
        LL_USART_TransmitData8(USART1, *pcTaskName++);
    }
}

void vApplicationMallocFailedHook(void) {
    /* vApplicationMallocFailedHook() will only be called if
     configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
     function that will get called if a call to pvPortMalloc() fails.
     pvPortMalloc() is called internally by the kernel whenever a task, queue,
     timer or semaphore is created. It is also called by various parts of the
     demo application. If heap_1.c or heap_2.c are used, then the size of the
     heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
     FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
     to query the size of free heap space that remains (although it does not
     provide information on how the remaining heap might be fragmented). */

    const char *pStr = MallocFailedMsg;

    while (*pStr) {
        while (LL_USART_IsActiveFlag_TXE(USART1) == RESET);
        LL_USART_TransmitData8(USART1, *pStr++);
    }
}
