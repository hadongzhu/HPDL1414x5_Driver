/**
 ******************************************************************************
 * @file       utils_macro.h
 * @author     hadongzhu
 * @version    V1.0
 * @date       2022-05-31
 * @brief      macro utils.
 * @copyright  2021-2024 hadongzhu. All rights reserved.
 ******************************************************************************
 * @attention
 *
 * Powered by Hadongzhu.
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef UTILS_MACRO_H
#define UTILS_MACRO_H

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_PORT(PORT)  GPIO_PORT_(PORT)
#define GPIO_PORT_(PORT) GPIO##PORT

#define HAL_GPIO_PORT(PORT) GPIO_PORT(PORT)
#define LL_GPIO_PORT(PORT)  GPIO_PORT(PORT)

#define HAL_GPIO_PIN(PIN)  HAL_GPIO_PIN_(PIN)
#define HAL_GPIO_PIN_(PIN) GPIO_PIN_##PIN

#define LL_GPIO_PIN(PIN)  LL_GPIO_PIN_(PIN)
#define LL_GPIO_PIN_(PIN) LL_GPIO_PIN_##PIN

#define HAL_GPIO_CLOCK_ENABLE(PORT)  HAL_GPIO_CLOCK_ENABLE_(PORT)
#define HAL_GPIO_CLOCK_ENABLE_(PORT) __HAL_RCC_GPIO##PORT##_CLK_ENABLE()

#define LL_GPIO_CLOCK_ENABLE(PORT) LL_GPIO_CLOCK_ENABLE_(PORT)
#define LL_GPIO_CLOCK_ENABLE_(PORT)                                            \
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIO##PORT)

#define SPI_INSTANCE(ID)  SPI_INSTANCE_(ID)
#define SPI_INSTANCE_(ID) SPI##ID

#define LL_SPI(ID) SPI_INSTANCE(ID)

#define LL_SPI_CLOCK_ENABLE(ID)  LL_SPI_CLOCK_ENABLE_(ID)
#define LL_SPI_CLOCK_ENABLE_(ID) LL_SPI_CLOCK_ENABLE_##ID()

#define LL_SPI_CLOCK_ENABLE_1()                                                \
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1)
#define LL_SPI_CLOCK_ENABLE_2()                                                \
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2)
#define LL_SPI_CLOCK_ENABLE_3()                                                \
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI3)
#define LL_SPI_CLOCK_ENABLE_4()                                                \
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI4)
#define LL_SPI_CLOCK_ENABLE_5()                                                \
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI5)
#define LL_SPI_CLOCK_ENABLE_6()                                                \
    LL_APB4_GRP1_EnableClock(LL_APB4_GRP1_PERIPH_SPI6)

#define LL_SPI_AF(PORT, PIN, ID)  LL_SPI_AF_(PORT, PIN, ID)
#define LL_SPI_AF_(PORT, PIN, ID) LL_SPI_AF_##PORT##_##PIN##_SPI##ID

#define LL_SPI_AF_A_4_SPI1  LL_GPIO_AF_5
#define LL_SPI_AF_A_5_SPI1  LL_GPIO_AF_5
#define LL_SPI_AF_A_6_SPI1  LL_GPIO_AF_5
#define LL_SPI_AF_A_7_SPI1  LL_GPIO_AF_5
#define LL_SPI_AF_A_9_SPI2  LL_GPIO_AF_5
#define LL_SPI_AF_A_11_SPI2 LL_GPIO_AF_5
#define LL_SPI_AF_A_12_SPI2 LL_GPIO_AF_5
#define LL_SPI_AF_A_15_SPI1 LL_GPIO_AF_5
#define LL_SPI_AF_B_3_SPI1  LL_GPIO_AF_5
#define LL_SPI_AF_B_4_SPI1  LL_GPIO_AF_5
#define LL_SPI_AF_B_5_SPI1  LL_GPIO_AF_5
#define LL_SPI_AF_B_9_SPI2  LL_GPIO_AF_5
#define LL_SPI_AF_B_10_SPI2 LL_GPIO_AF_5
#define LL_SPI_AF_B_12_SPI2 LL_GPIO_AF_5
#define LL_SPI_AF_B_13_SPI2 LL_GPIO_AF_5
#define LL_SPI_AF_B_14_SPI2 LL_GPIO_AF_5
#define LL_SPI_AF_B_15_SPI2 LL_GPIO_AF_5
#define LL_SPI_AF_C_1_SPI2  LL_GPIO_AF_5
#define LL_SPI_AF_C_2_SPI2  LL_GPIO_AF_5
#define LL_SPI_AF_C_3_SPI2  LL_GPIO_AF_5
#define LL_SPI_AF_D_3_SPI2  LL_GPIO_AF_5
#define LL_SPI_AF_D_6_SPI3  LL_GPIO_AF_5
#define LL_SPI_AF_D_7_SPI1  LL_GPIO_AF_5
#define LL_SPI_AF_E_2_SPI4  LL_GPIO_AF_5
#define LL_SPI_AF_E_4_SPI4  LL_GPIO_AF_5
#define LL_SPI_AF_E_5_SPI4  LL_GPIO_AF_5
#define LL_SPI_AF_E_6_SPI4  LL_GPIO_AF_5
#define LL_SPI_AF_E_11_SPI4 LL_GPIO_AF_5
#define LL_SPI_AF_E_12_SPI4 LL_GPIO_AF_5
#define LL_SPI_AF_E_13_SPI4 LL_GPIO_AF_5
#define LL_SPI_AF_E_14_SPI4 LL_GPIO_AF_5
#define LL_SPI_AF_F_6_SPI5  LL_GPIO_AF_5
#define LL_SPI_AF_F_7_SPI5  LL_GPIO_AF_5
#define LL_SPI_AF_F_8_SPI5  LL_GPIO_AF_5
#define LL_SPI_AF_F_9_SPI5  LL_GPIO_AF_5
#define LL_SPI_AF_F_11_SPI5 LL_GPIO_AF_5
#define LL_SPI_AF_G_8_SPI6  LL_GPIO_AF_5
#define LL_SPI_AF_G_9_SPI1  LL_GPIO_AF_5
#define LL_SPI_AF_G_10_SPI1 LL_GPIO_AF_5
#define LL_SPI_AF_G_11_SPI1 LL_GPIO_AF_5
#define LL_SPI_AF_G_12_SPI6 LL_GPIO_AF_5
#define LL_SPI_AF_G_13_SPI6 LL_GPIO_AF_5
#define LL_SPI_AF_G_14_SPI6 LL_GPIO_AF_5
#define LL_SPI_AF_H_5_SPI5  LL_GPIO_AF_5
#define LL_SPI_AF_H_6_SPI5  LL_GPIO_AF_5
#define LL_SPI_AF_H_7_SPI5  LL_GPIO_AF_5
#define LL_SPI_AF_I_0_SPI2  LL_GPIO_AF_5
#define LL_SPI_AF_I_1_SPI2  LL_GPIO_AF_5
#define LL_SPI_AF_I_2_SPI2  LL_GPIO_AF_5
#define LL_SPI_AF_I_3_SPI2  LL_GPIO_AF_5
#define LL_SPI_AF_J_10_SPI5 LL_GPIO_AF_5
#define LL_SPI_AF_J_11_SPI5 LL_GPIO_AF_5
#define LL_SPI_AF_K_0_SPI5  LL_GPIO_AF_5
#define LL_SPI_AF_K_1_SPI5  LL_GPIO_AF_5

#define LL_SPI_AF_A_4_SPI3  LL_GPIO_AF_6
#define LL_SPI_AF_A_15_SPI3 LL_GPIO_AF_6
#define LL_SPI_AF_B_3_SPI3  LL_GPIO_AF_6
#define LL_SPI_AF_B_4_SPI3  LL_GPIO_AF_6
#define LL_SPI_AF_C_10_SPI3 LL_GPIO_AF_6
#define LL_SPI_AF_C_11_SPI3 LL_GPIO_AF_6
#define LL_SPI_AF_C_12_SPI3 LL_GPIO_AF_6

#define LL_SPI_AF_A_15_SPI6 LL_GPIO_AF_7
#define LL_SPI_AF_B_2_SPI3  LL_GPIO_AF_7
#define LL_SPI_AF_B_4_SPI2  LL_GPIO_AF_7
#define LL_SPI_AF_B_5_SPI3  LL_GPIO_AF_7

#define LL_SPI_AF_A_4_SPI6 LL_GPIO_AF_8
#define LL_SPI_AF_A_5_SPI6 LL_GPIO_AF_8
#define LL_SPI_AF_A_6_SPI6 LL_GPIO_AF_8
#define LL_SPI_AF_A_7_SPI6 LL_GPIO_AF_8
#define LL_SPI_AF_B_3_SPI6 LL_GPIO_AF_8
#define LL_SPI_AF_B_4_SPI6 LL_GPIO_AF_8
#define LL_SPI_AF_B_5_SPI6 LL_GPIO_AF_8

#ifdef __cplusplus
}
#endif

#endif /* BSP_H */
