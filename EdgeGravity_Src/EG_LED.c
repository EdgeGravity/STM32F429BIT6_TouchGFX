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
 * @ 名称: EG_LED.c
 * @ 描述:
 * @ 作者: SummerFalls
 * @ 日期: 2020年8月16日
 * @ 版本: V1.0
 * @ 历史: V1.0 2020年8月16日 Summary
 *
 * Copyright (c) 2020 SummerFalls. All rights reserved.
 */

#include "EG_Include.h"

LED_PATTERN_t LedList[NUM_OF_LED] = {
//    {LED1_GPIO_Port, LED1_Pin, 1000, 0, BLINK_MODE_AUTO},
};

/*******************************************************************************
* @name   : LED_SetBlinkInterval
* @brief  : 设置 LED 闪烁周期
* @param  : @arg LED_LIST_t LED_Sel: 选择要设置的 LED
*           @arg uint16_t Interval: 设置的周期，单位 ms
* @retval : void
*******************************************************************************/
void LED_SetBlinkInterval(LED_LIST_t LED_Sel, uint16_t Interval, BLINK_MODE_t blinkMode)
{
    LedList[LED_Sel].blinkMode = blinkMode;

    if (LedList[LED_Sel].blinkMode == BLINK_MODE_AUTO) {
        LedList[LED_Sel].blinkInterval = Interval;
    } else {
        LL_GPIO_ResetOutputPin(LedList[LED_Sel].GPIOx, LedList[LED_Sel].GPIO_Pin);
    }
}

/*******************************************************************************
* @name   : LED_BlinkProcess
* @brief  : LED 闪烁翻转，放置于任务中
* @param  : void
* @retval : void
*******************************************************************************/
void LED_BlinkProcess(void)
{
    for (uint8_t Idx = 0; Idx < NUM_OF_LED; Idx++) {
        if (LedList[Idx].blinkMode == BLINK_MODE_AUTO) {
            if (LedList[Idx].blinkCount < LedList[Idx].blinkInterval) {
                LedList[Idx].blinkCount += OS_LED_DELAY_BASE;
            } else {
                LedList[Idx].blinkCount = 0;
                LL_GPIO_TogglePin(LedList[Idx].GPIOx, LedList[Idx].GPIO_Pin);
            }
        }
    }
}
