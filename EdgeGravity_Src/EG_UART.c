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
 * @ 名称: EG_UART.c
 * @ 描述:
 * @ 作者: SummerFalls
 * @ 日期: 2020年8月16日
 * @ 版本: V1.0
 * @ 历史: V1.0 2020年8月16日 Summary
 *
 * Copyright (c) 2020 SummerFalls. All rights reserved.
 */

#include "EG_Include.h"

#ifdef __GNUC__
/* @ 若需打印浮点数 则需要在
 * @ 工程属性->C/C++ Build->Settings->C Linker->Miscellaneous->Other options中添加 -u _printf_float
 * @ 以使能浮点打印功能，此外，使能浮点打印功能，编译后会明显增加RAM和FLASH占用
 */
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

#ifndef __MICROLIB
/* 加入以下代码，支持printf函数，而不需要选择use MicroLIB */
#pragma import(__use_no_semihosting)

/* 标准库需要的支持函数 */
struct __FILE {
    int handle;
};

/* FILE 定义在 stdio.h */
FILE __stdout;

/* 定义_sys_exit()以避免使用半主机模式 */
void _sys_exit(int x)
{
    x = x;
}
#endif
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE {
    while (LL_USART_IsActiveFlag_TXE(USART1) == RESET);

    LL_USART_TransmitData8(USART1, ch);

    while (LL_USART_IsActiveFlag_TC(USART1) == RESET);
    return ch;
}

#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
/* 屏蔽在 Arm Compiler V6 编译器下，因字符串中有中文字符而造成的警告 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-source-encoding"
#endif
/*******************************************************************************
* @name   : UART_PrintPrjInfo
* @brief  : 打印输出工程相关信息
* @param  : void
* @retval : void
*******************************************************************************/
void UART_PrintPrjInfo(char *pcWriteBuffer)
{
    osVersion_t osv;
    osStatus_t status;
    uint32_t ChipUniqueID[3];

    PRINTF("/*\r\n");
    PRINTF("*      ___          _____          ___           ___                    ___           ___           ___\r\n");
    PRINTF("*     /  /\\        /  /::\\        /  /\\         /  /\\                  /  /\\         /  /\\         /  /\\          ___        ___           ___         ___\r\n");
    PRINTF("*    /  /:/_      /  /:/\\:\\      /  /:/_       /  /:/_                /  /:/_       /  /::\\       /  /::\\        /__/\\      /  /\\         /  /\\       /__/|\r\n");
    PRINTF("*   /  /:/ /\\    /  /:/  \\:\\    /  /:/ /\\     /  /:/ /\\              /  /:/ /\\     /  /:/\\:\\     /  /:/\\:\\       \\  \\:\\    /  /:/        /  /:/      |  |:|\r\n");
    PRINTF("*  /  /:/ /:/_  /__/:/ \\__\\:|  /  /:/_/::\\   /  /:/ /:/_            /  /:/_/::\\   /  /:/~/:/    /  /:/~/::\\       \\  \\:\\  /__/::\\       /  /:/       |  |:|\r\n");
    PRINTF("* /__/:/ /:/ /\\ \\  \\:\\ /  /:/ /__/:/__\\/\\:\\ /__/:/ /:/ /\\          /__/:/__\\/\\:\\ /__/:/ /:/___ /__/:/ /:/\\:\\  ___  \\__\\:\\ \\__\\/\\:\\__   /  /::\\     __|__|:|\r\n");
    PRINTF("* \\  \\:\\/:/ /:/  \\  \\:\\  /:/  \\  \\:\\ /~~/:/ \\  \\:\\/:/ /:/          \\  \\:\\ /~~/:/ \\  \\:\\/:::::/ \\  \\:\\/:/__\\/ /__/\\ |  |:|    \\  \\:\\/\\ /__/:/\\:\\   /__/::::\\\r\n");
    PRINTF("*  \\  \\::/ /:/    \\  \\:\\/:/    \\  \\:\\  /:/   \\  \\::/ /:/            \\  \\:\\  /:/   \\  \\::/~~~~   \\  \\::/      \\  \\:\\|  |:|     \\__\\::/ \\__\\/  \\:\\     ~\\~~\\:\\\r\n");
    PRINTF("*   \\  \\:\\/:/      \\  \\::/      \\  \\:\\/:/     \\  \\:\\/:/              \\  \\:\\/:/     \\  \\:\\        \\  \\:\\       \\  \\:\\__|:|     /__/:/       \\  \\:\\      \\  \\:\\\r\n");
    PRINTF("*    \\  \\::/        \\__\\/        \\  \\::/       \\  \\::/                \\  \\::/       \\  \\:\\        \\  \\:\\       \\__\\::::/      \\__\\/         \\__\\/       \\__\\/\r\n");
    PRINTF("*     \\__\\/                       \\__\\/         \\__\\/                  \\__\\/         \\__\\/         \\__\\/           ~~~~\r\n");
    PRINTF("*\r\n");
    PRINTF("*\r\n");
    PRINTF("* @ 工程名称：%s\r\n", FIRMWARE_NAME);
    PRINTF("* @ 作者：%s\r\n", FIRMWARE_AUTHOR);
    PRINTF("* @ 编译器：%s\r\n", FIRMWARE_COMPILER);
    PRINTF("* @ 日期：%s %s\r\n", __DATE__, __TIME__);
    PRINTF("* @ 版本：Ver. %s\r\n", FIRMWARE_VERSION);
    PRINTF("* @ 描述：%s\r\n", FIRMWARE_DESCRIPTION);
    PRINTF("*\r\n");
    PRINTF("* %s\r\n", FIRMWARE_COPYRIGHT);
    PRINTF("*/\r\n\r\n");

    ChipUniqueID[0] = HAL_GetUIDw0();
    ChipUniqueID[1] = HAL_GetUIDw1();
    ChipUniqueID[2] = HAL_GetUIDw2();
    PRINTF("芯片 UID：\t%08X-%08X-%08X\r\n", ChipUniqueID[0], ChipUniqueID[1], ChipUniqueID[2]);
    PRINTF("HAL库版本：\t0x%02X\r\n", HAL_GetHalVersion());
    PRINTF("DEV_ID：\t0x%02X\r\n", HAL_GetDEVID());
    PRINTF("REV_ID：\t0x%02X\r\n", HAL_GetREVID());

    status = osKernelGetInfo(&osv, pcWriteBuffer, strlen(pcWriteBuffer));
    if(status == osOK) {
        PRINTF("内核信息：%s\r\n", pcWriteBuffer);
        PRINTF("内核版本：%ld\r\n", osv.kernel);
        PRINTF("内核API版本：%ld\r\n", osv.api);
    }
}

#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic pop
#endif
