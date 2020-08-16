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
 * @ 名称: EG_KEY.c
 * @ 描述:
 * @ 作者: SummerFalls
 * @ 日期: 2020年8月16日
 * @ 版本: V1.0
 * @ 历史: V1.0 2020年8月16日 Summary
 *
 * Copyright (c) 2020 SummerFalls. All rights reserved.
 */

#include "EG_Include.h"

KEY_PORT_PIN_TypeDef KeyList[NUM_OF_KEYS] = {
    {KEY_S1_GPIO_Port, KEY_S1_Pin},
    {KEY_S2_GPIO_Port, KEY_S2_Pin},
    {KEY_S3_GPIO_Port, KEY_S3_Pin},
};

/*******************************************************************************
* @name   : KEY_Scan
* @brief  : 按键扫描
* @param  : @arg KEY_LIST_TypeDef KeySel: 选择要检测第几个按键
* @retval : KEY_STATE_TypeDef KEY_ON  - 按键按下
*           KEY_STATE_TypeDef KEY_OFF - 按键放开
* @note   : 尽量不要在中断中使用，防止打断主线程重要函数的执行
*******************************************************************************/
KEY_STATE_TypeDef KEY_Scan(KEY_LIST_TypeDef KeySel)
{
    /* 检测按键是否被按下 */
    if (LL_GPIO_IsInputPinSet(KeyList[KeySel].GPIOx, KeyList[KeySel].GPIO_Pin) == RESET) {
        /* 延时消抖 */
        osDelay(10);

        /* 再次检测是否为低电平 */
        if (LL_GPIO_IsInputPinSet(KeyList[KeySel].GPIOx, KeyList[KeySel].GPIO_Pin) == RESET) {
            /* 等待按键放开 */
            while (LL_GPIO_IsInputPinSet(KeyList[KeySel].GPIOx, KeyList[KeySel].GPIO_Pin) == RESET) {
                osDelay(10);
                /* 返回按键按下标志 */
                return KEY_ON;
            }
        }
    }

    /* 返回按键放开标志 */
    return KEY_OFF;
}
