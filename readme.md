### HPDL1414x5显示模块驱动

关于此模块的更多说明请参考[这里](https://hadongzhu.com/archives/711)，硬件设计在[这里](https://oshwhub.com/hadongzhu/hpdl1414)。本仓库包含HPDL1414x5显示模块驱动和一个以STM32H750B为主控的示例MDK工程。

#### 连接说明

样例工程使用了以下引脚：
```
CS --- PB12
SCK --- PA9
MOSI --- PB15
```
使用硬件SPI时，SPI使用SPI2。以上定义在`./BSP/bsp_define.h`中。

#### 工程说明
驱动使用LL库编写，驱动文件为`./BSP/hpdl1414.c`、`./BSP/hpdl1414.h`，并且依赖于`./BSP/utils_macro.h`下的部分宏定义。提供的函数请参考`./BSP/hpdl1414.h`。驱动支持硬件SPI或者GPIO驱动，通过`./BSP/hpdl1414.c`的宏定义`HPDL1414x5_HARD`和`HPDL1414x5_SOFT`来分别选择硬件SPI或GPIO驱动。
