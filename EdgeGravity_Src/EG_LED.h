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
 * @ 名称: EG_LED.h
 * @ 描述:
 * @ 作者: SummerFalls
 * @ 日期: 2020年8月16日
 * @ 版本: V1.0
 * @ 历史: V1.0 2020年8月16日 Summary
 *
 * Copyright (c) 2020 SummerFalls. All rights reserved.
 */

#ifndef EDGEGRAVITY_SRC_EG_LED_H_
#define EDGEGRAVITY_SRC_EG_LED_H_

#include "EG_Include.h"

#define OS_LED_DELAY_BASE   10U /* vTaskLED 任务中执行 osDelay 的时基 */
#define NUM_OF_LED           0U /* 可用 LED 数量 */

typedef enum {
    LED1,
} LED_LIST_t;

/* 若闪烁模式为手动，则手动调用 LL_GPIO_TogglePin() 进行 LED 的翻转 */
typedef enum {
    BLINK_MODE_AUTO,
    BLINK_MODE_MANUAL,
} BLINK_MODE_t;

typedef struct {
    GPIO_TypeDef        *GPIOx;
    uint32_t            GPIO_Pin;
    volatile uint16_t   blinkInterval;
    volatile uint16_t   blinkCount;
    BLINK_MODE_t        blinkMode;
} LED_PATTERN_t;

void LED_SetBlinkInterval(LED_LIST_t LED_Sel, uint16_t Interval, BLINK_MODE_t blinkMode);
void LED_BlinkProcess(void);

//#define LED1_ON()      HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET)
//#define LED1_OFF()     HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET)
//#define LED1_TOGGLE()  HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin)

//#define LED1_ON()      LL_GPIO_SetOutputPin(LED1_GPIO_Port, LED1_Pin)
//#define LED1_OFF()     LL_GPIO_ResetOutputPin(LED1_GPIO_Port, LED1_Pin)
//#define LED1_TOGGLE()  LL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin)

#endif /* EDGEGRAVITY_SRC_EG_LED_H_ */
