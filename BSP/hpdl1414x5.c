/**
 ******************************************************************************
 * @file    hpdl1414.cpp
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

#include "hpdl1414x5.h"
#include "bsp_define.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_gpio.h"
#include "stm32h7xx_ll_spi.h"
#include "utils_macro.h"

#define CS_PORT   HPDL1414x5_CS_PORT
#define CS_PIN    HPDL1414x5_CS_PIN

#define MOSI_PORT HPDL1414x5_MOSI_PORT
#define MOSI_PIN  HPDL1414x5_MOSI_PIN

#define SCK_PORT  HPDL1414x5_SCK_PORT
#define SCK_PIN   HPDL1414x5_SCK_PIN

#define SPI       HPDL1414x5_SPI

void HPDL1414x5_Init(void)
{
    LL_GPIO_InitTypeDef GPIO_InitStruct;

    LL_GPIO_CLOCK_ENABLE(CS_PORT);
    LL_GPIO_CLOCK_ENABLE(MOSI_PORT);
    LL_GPIO_CLOCK_ENABLE(SCK_PORT);

    LL_GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;

    GPIO_InitStruct.Pin = LL_GPIO_PIN(CS_PIN);
    GPIO_InitStruct.Alternate = LL_SPI_AF(CS_PORT, CS_PIN, SPI);
    (void)LL_GPIO_Init(GPIO_PORT(CS_PORT), &GPIO_InitStruct);
    GPIO_InitStruct.Pin = LL_GPIO_PIN(MOSI_PIN);
    GPIO_InitStruct.Alternate = LL_SPI_AF(MOSI_PORT, MOSI_PIN, SPI);
    (void)LL_GPIO_Init(GPIO_PORT(MOSI_PORT), &GPIO_InitStruct);
    GPIO_InitStruct.Pin = LL_GPIO_PIN(SCK_PIN);
    GPIO_InitStruct.Alternate = LL_SPI_AF(SCK_PORT, SCK_PIN, SPI);
    (void)LL_GPIO_Init(GPIO_PORT(SCK_PORT), &GPIO_InitStruct);

    LL_SPI_CLOCK_ENABLE(SPI);

    LL_SPI_InitTypeDef SPI_InitStruct;
    LL_SPI_StructInit(&SPI_InitStruct);
    SPI_InitStruct.TransferDirection = LL_SPI_SIMPLEX_TX;
    SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
    SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
    SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
    SPI_InitStruct.NSS = LL_SPI_NSS_HARD_OUTPUT;
    SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV4;
    SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
    SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
    SPI_InitStruct.CRCPoly = 0x00UL;
    LL_SPI_Init(LL_SPI(SPI), &SPI_InitStruct);

    // LL_SPI_Enable(LL_SPI(SPI));
}

void HPDL1414x5_Putc(uint8_t address, uint8_t ascii)
{
    LL_SPI_SetTransferSize(LL_SPI(SPI), 2);
    LL_SPI_Enable(LL_SPI(SPI));
    LL_I2S_StartTransfer(LL_SPI(SPI));
    while (!LL_SPI_IsActiveFlag_TXP(LL_SPI(SPI)))
        ;
    LL_SPI_TransmitData8(LL_SPI(SPI), address);
    while (!LL_SPI_IsActiveFlag_TXP(LL_SPI(SPI)))
        ;
    LL_SPI_TransmitData8(LL_SPI(SPI), ascii);
    while (!LL_SPI_IsActiveFlag_EOT(LL_SPI(SPI)))
        ;
    LL_SPI_ClearFlag_EOT(LL_SPI(SPI));
    LL_SPI_ClearFlag_TXTF(LL_SPI(SPI));
    LL_SPI_Disable(LL_SPI(SPI));

    LL_SPI_SetTransferSize(LL_SPI(SPI), 2);
    LL_SPI_Enable(LL_SPI(SPI));
    LL_I2S_StartTransfer(LL_SPI(SPI));
    while (!LL_SPI_IsActiveFlag_TXP(LL_SPI(SPI)))
        ;
    LL_SPI_TransmitData8(LL_SPI(SPI), 0xFC);
    while (!LL_SPI_IsActiveFlag_TXP(LL_SPI(SPI)))
        ;
    LL_SPI_TransmitData8(LL_SPI(SPI), ascii);
    while (!LL_SPI_IsActiveFlag_EOT(LL_SPI(SPI)))
        ;
    LL_SPI_ClearFlag_EOT(LL_SPI(SPI));
    LL_SPI_ClearFlag_TXTF(LL_SPI(SPI));
    LL_SPI_Disable(LL_SPI(SPI));
}

void HPDL1414x5_Clear(void)
{
    for (uint8_t i = 0; i < 20; i++)
    {
        HPDL1414x5_Putc(i, ' ');
    }
}

void HPDL1414x5_Puts(const char *str)
{
    for (uint8_t i = 0; i < 20; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        HPDL1414x5_Putc(20 - 1 - i, str[i]);
    }
}