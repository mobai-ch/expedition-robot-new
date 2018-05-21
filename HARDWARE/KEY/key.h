#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h" 

#define ReadE5 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5)  //1
#define ReadE6 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6)  //2
#define ReadE7 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_7)  //3
void KEY_Init(void);	//IO≥ı ºªØ

int waitKey(void);

#endif

