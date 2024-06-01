#include "bsp.h"
#include "hpdl1414x5.h"
#include "stm32h7xx_ll_utils.h"

int32_t main(void)
{
    bsp_Init();
    while(1)
    {
        HPDL1414x5_Puts("----HELLO WORLD!----");
        LL_mDelay(1000);
        HPDL1414x5_Puts("-----HADONGZHU------");
        LL_mDelay(1000);
        HPDL1414x5_Clear();
        LL_mDelay(1000);
    }
}
