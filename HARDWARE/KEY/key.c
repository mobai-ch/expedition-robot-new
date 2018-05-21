#include "key.h"
#include "delay.h" 

void KEY_Init(void)
{
	
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//使能GPIOA,GPIOE时钟
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE2,3,4
	
} 

int waitKey()
	{
	u8 key1,key2,key3;
	
	while(1){
		key1 = ReadE5;
		key2 = ReadE6;
		key3 = ReadE7;
		
		//按键2 按下
		if(key2 == 0){
			delay_ms(10);
			key2 = ReadE6;
			if(key2 == 0){
				while(1){
					key2 = ReadE6;
					if(key2){
						delay_ms(10);
						key2 = ReadE6;
						if(key2)	return 2;
					}
				}
			}
		}
		
		//按键1 按下
		if(key1 == 0){
			delay_ms(10);
			key1 = ReadE5;
			if(key1 == 0){
				while(1){
					key1 = ReadE5;
					if(key1){
						delay_ms(10);
						key1 = ReadE5;
						if(key1)	return 1;
					}
				}
			}
		}
		
		//按键3 按下
		if(key3 == 0){
			delay_ms(10);
			key3 = ReadE7;
			if(key3 == 0){
				while(1){
					key3 = ReadE7;
					if(key3){
						delay_ms(10);
						key3 = ReadE7;
						if(key3)	return 3;
					}
				}
			}
		}
		
	}
	
	return 0;
}



