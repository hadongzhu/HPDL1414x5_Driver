/**
 ******************************************************************************
 * @file    bsp_define.h
 * @author  hadongzhu
 * @version V1.0.0
 * @date    2023-10-26
 * @brief   board pin defination.
 ******************************************************************************
 * @attention
 *
 * Powered by Hadongzhu
 ******************************************************************************
 */

#ifndef __BSP_DEFINE_H
#define __BSP_DEFINE_H

#define HARDWARE_VERSION 20240531

#define FIRMWARE_VERSION 20240531

#if HARDWARE_VERSION == 20240531
    /* HPDL-1414x5 Display module */
    #define HPDL1414x5_CS_PORT   B
    #define HPDL1414x5_CS_PIN    12

    #define HPDL1414x5_MOSI_PORT B
    #define HPDL1414x5_MOSI_PIN  15

    #define HPDL1414x5_SCK_PORT  A
    #define HPDL1414x5_SCK_PIN   9

    #define HPDL1414x5_SPI       2

#else
    #error "this hardware version is not supported!"
#endif

#endif // __BSP_DEFINE_H
