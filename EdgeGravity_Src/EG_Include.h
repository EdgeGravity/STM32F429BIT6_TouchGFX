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
 * @ 名称: EG_Include.h
 * @ 描述: 全局通用头文件引用，针对不同 .c 源文件经常需要引用共同的头文件的情况，请直接引用本头文件即可。
 * @ 作者: SummerFalls
 * @ 日期: 2020年8月16日
 * @ 版本: V1.0
 * @ 历史: V1.0 2020年8月16日 Summary
 *
 * Copyright (c) 2020 SummerFalls. All rights reserved.
 */

#ifndef EDGEGRAVITY_SRC_EG_INCLUDE_H_
#define EDGEGRAVITY_SRC_EG_INCLUDE_H_

#ifdef __cplusplus
extern "C" {
#endif

/* @NOTE:
 * ****************************************编译器相关说明****************************************
 *
 * @ 在 Keil 环境下，本工程使用不同编译器所需要的 FreeRTOS port 相关文件不同
 * @ 默认从 STM32CubeMX 生成的 FreeRTOS 工程无法使用 ARMCLANG(ARM Compiler V6) 编译
 * @ 解决方法为：从 FreeRTOS 官网下载最新的源码，将 FreeRTOS/Source/portable/GCC/ARM_CM4F 目录
 * @ 复制到工程目录下，如：./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F
 *
 * C/C++ -> Include Paths：
 * ARMCC(ARM Compiler V5)      ../Middlewares/Third_Party/FreeRTOS/Source/portable/RVDS/ARM_CM4F
 * ARMCLANG(ARM Compiler V6)   ../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F
 *
 * Middlewares/FreeRTOS 使用文件：
 * ARMCC(ARM Compiler V5)      ../Middlewares/Third_Party/FreeRTOS/Source/portable/RVDS/ARM_CM4F/port.c
 * ARMCLANG(ARM Compiler V6)   ../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
 */

/* 通过注释或取消注释本宏，可快捷地觉得是否使用 UART printf 打印输出功能 */
#define USE_PRINTF

#ifdef USE_PRINTF
#define PRINTF App_Printf
#else
#define PRINTF(...)
#endif

/* ------------------------------------------ 工程信息 ------------------------------------------ */
#define TXT_COPYRIGHT_SEG_1_CH "2020 边缘重力."
#define TXT_COPYRIGHT_SEG_1_EN "2020 SummerFalls."

/* 用于 USART 打印 */
#define FIRMWARE_NAME           "Edge Gravity Custom Mechanical Keyboard GUI"
#define FIRMWARE_AUTHOR         "SummerFalls"
#define FIRMWARE_VERSION        "0.0.2"
#define FIRMWARE_DESCRIPTION    "边缘重力客制化机械键盘界面原型验证程序"
#define FIRMWARE_COPYRIGHT      "Copyright (c) " TXT_COPYRIGHT_SEG_1_EN " All rights reserved."

#if   defined (__CC_ARM)
#define FIRMWARE_COMPILER       "ARMCC"
#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#define FIRMWARE_COMPILER       "ARMCLANG"
#elif defined ( __GNUC__ )
#define FIRMWARE_COMPILER       "GCC"
#endif

/* ------------------------------------------ 工程信息 ------------------------------------------ */

/* ------- 标准库头文件引用 ------- */
#include <stdint.h> /* 数据类型 */

#include <stdio.h>  /* 输入输出 */
#include <stdlib.h> /* 常用实用函数 */
#include <stddef.h> /* 常用定义 */
#include <string.h> /* 字符串处理 */
#include <stdarg.h> /* 不定参数 */
#include <ctype.h>  /* 字符处理 */

#include <locale.h> /* 本地化 */
#include <time.h>   /* 日期和时间 */

#include <limits.h> /* 整型特性 */
#include <float.h>  /* 浮点数特性 */
#include <math.h>   /* 数学计算 */

//#include <assert.h> /* 诊断 */
//#include <errno.h>  /* 错误监测 */

//#include <setjmp.h> /* 非本地跳转 */
//#include <signal.h> /* 信号处理 */


/* ----- 芯片原厂库头文件引用 ----- */
#include "main.h"
//#include "crc.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"
#include "tim.h"

/* ----- 操作系统头文件引用 ----- */
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* ------ 用户库头文件引用 ------ */
#include "EG_OSTask.h"
#include "EG_UART.h"
#include "EG_KEY.h"
#include "EG_LED.h"
//#include "EG_Malloc.h"
//#include "EG_Delay.h"

/* ----- 界面库相关头文件引用 ----- */
#include "app_touchgfx.h"

/* 4 字节对齐 */
/* Macro to get variable aligned on 4-bytes, for __ICCARM__ the directive "#pragma data_alignment=4" must be used instead */
#if defined ( __GNUC__ ) && !defined (__CC_ARM) /* GNU Compiler */
  #ifndef __ALIGN_END
#define __ALIGN_END    __attribute__ ((aligned (4)))
  #endif /* __ALIGN_END */
  #ifndef __ALIGN_BEGIN
    #define __ALIGN_BEGIN
  #endif /* __ALIGN_BEGIN */
#else
  #ifndef __ALIGN_END
    #define __ALIGN_END
  #endif /* __ALIGN_END */
  #ifndef __ALIGN_BEGIN
    #if defined   (__CC_ARM)      /* ARM Compiler */
#define __ALIGN_BEGIN    __align(4)
    #elif defined (__ICCARM__)    /* IAR Compiler */
      #define __ALIGN_BEGIN
    #endif /* __CC_ARM */
  #endif /* __ALIGN_BEGIN */
#endif /* __GNUC__ */

#ifdef __cplusplus
}
#endif

#endif /* EDGEGRAVITY_SRC_EG_INCLUDE_H_ */
