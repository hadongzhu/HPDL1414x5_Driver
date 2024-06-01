/**
 ******************************************************************************
 * @file    hpdl1414.h
 * @author  hadongzhu
 * @version V1.0.0
 * @date    2024-05-31
 * @brief   driver for hpdl1414x5 display module.
 ******************************************************************************
 * @attention
 *
 * Powered by Hadongzhu
 ******************************************************************************
 */

#ifndef __HPDL1414_H
#define __HPDL1414_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

void HPDL1414x5_Init(void);
void HPDL1414x5_Putc(uint8_t address, uint8_t ascii);
void HPDL1414x5_Clear(void);
void HPDL1414x5_Puts(const char *str);

#ifdef __cplusplus
}
#endif

#endif /* __HPDL1414_H */
