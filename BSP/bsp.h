/**
  ******************************************************************************
  * @file       bsp.h
  * @author     hadongzhu
  * @version    V1.0
  * @date       2022-10-30
  * @brief      initialize basic hardware driver and configuration.
  * @copyright  2021-2022 hadongzhu. All rights reserved.
  ******************************************************************************
  * @attention
  *
  * Powered by Hadongzhu.
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef BSP_H
#define BSP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Stander C Lib */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"

/** @addtogroup BSP
  * @{
  */

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
void bsp_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* BSP_H */
