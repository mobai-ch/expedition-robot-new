#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"         
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//ADC 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/6
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

#define ADCx                     ADC1
#define ADC_CHANNEL              ADC_Channel_8
#define ADCx_CLK                 RCC_APB2Periph_ADC1
#define ADCx_CHANNEL_GPIO_CLK    RCC_AHB1Periph_GPIOB
#define GPIO_PIN                 GPIO_Pin_0
#define GPIO_PORT                GPIOB
#define DMA_CHANNELx             DMA_Channel_0
#define DMA_STREAMx              DMA2_Stream0
#define ADCx_DR_ADDRESS          ((uint32_t)&ADC1->DR)

void ADC_Config(void);
#endif 







