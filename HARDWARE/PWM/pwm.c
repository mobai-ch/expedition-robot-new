#include "pwm.h"




//四个电机的PWM 
 void TIM4CH_PWM_Init(u32 arr,u32 psc)
{
    GPIO_InitTypeDef GPIO_InitStructure12;
	GPIO_InitTypeDef GPIO_InitStructure13;
	GPIO_InitTypeDef GPIO_InitStructure14;
	GPIO_InitTypeDef GPIO_InitStructure15;
	
	  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	  TIM_OCInitTypeDef  TIM_OCInitStructure1;
	  TIM_OCInitTypeDef  TIM_OCInitStructure2;
	  TIM_OCInitTypeDef  TIM_OCInitStructure3;
	  TIM_OCInitTypeDef  TIM_OCInitStructure4;
	
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  	//TIM4时钟使能 
	
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 	//使能PORTD时钟	
	
	 

 //GPIOB6的初始化 

	GPIO_InitStructure12.GPIO_Pin = GPIO_Pin_12 ;      
	GPIO_InitStructure12.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure12.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure12.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure12.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOD,&GPIO_InitStructure12);              //初始化PD12
	
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource12,GPIO_AF_TIM4);	//复用设置
	
	 //GPIOB7的初始化 

	GPIO_InitStructure13.GPIO_Pin = GPIO_Pin_13 ;      
	GPIO_InitStructure13.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure13.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure13.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure13.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOD,&GPIO_InitStructure13);              //初始化PD13
	
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource13,GPIO_AF_TIM4);//复用设置
	
	 //GPIOB8的初始化 

	GPIO_InitStructure14.GPIO_Pin = GPIO_Pin_14 ;      
	GPIO_InitStructure14.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure14.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure14.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure14.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOD,&GPIO_InitStructure14);               //初始化PD14
	
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource14,GPIO_AF_TIM4);//复用设置
	
	 //GPIOB9的初始化 

	GPIO_InitStructure15.GPIO_Pin = GPIO_Pin_15 ;      
	GPIO_InitStructure15.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure15.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure15.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure15.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOD,&GPIO_InitStructure15);               //初始化PD15
	
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource15,GPIO_AF_TIM4);//复用设置
	
//初始化定时器4
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseStructure);//初始化定时器4
	
	
	//初始化TIM4 Channe1 PWM模式	 
	TIM_OCInitStructure1.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure1.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure1.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC1Init(TIM4,&TIM_OCInitStructure1);



//初始化TIM4 Channe2 PWM模式	
	TIM_OCInitStructure2.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure2.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure2.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC2Init(TIM4,&TIM_OCInitStructure2);
	
	
	//初始化TIM4 Channe3 PWM模式	
  TIM_OCInitStructure3.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure3.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure3.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC3Init(TIM4,&TIM_OCInitStructure3);
	
	
	//初始化TIM4 Channe4 PWM模式		
	TIM_OCInitStructure4.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure4.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure4.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC4Init(TIM4,&TIM_OCInitStructure4);
	

  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
 
  TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPE使能 
	
	TIM_Cmd(TIM4, ENABLE);  //使能TIM4
}




 



//舵机的驱动

 void TIM3CH_PWM_Init(u32 arr,u32 psc)
{
    GPIO_InitTypeDef GPIO_InitStructure6;
	  GPIO_InitTypeDef GPIO_InitStructure7;
	  GPIO_InitTypeDef GPIO_InitStructure8;
	  GPIO_InitTypeDef GPIO_InitStructure9;
	
	  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	  TIM_OCInitTypeDef  TIM_OCInitStructure1;
	  TIM_OCInitTypeDef  TIM_OCInitStructure2;
	  TIM_OCInitTypeDef  TIM_OCInitStructure3;
	  TIM_OCInitTypeDef  TIM_OCInitStructure4;
	
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  	//TIM3时钟使能 
	
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); 	//使能PORTC时钟	
	
	 

 //GPIOC6的初始化 

	GPIO_InitStructure6.GPIO_Pin = GPIO_Pin_6 ;      
	GPIO_InitStructure6.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure6.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure6.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure6.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOC,&GPIO_InitStructure6);              //初始化PC6
	
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource6,GPIO_AF_TIM3);	//复用设置
	
	 //GPIOC7的初始化 

	GPIO_InitStructure7.GPIO_Pin = GPIO_Pin_7 ;      
	GPIO_InitStructure7.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure7.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure7.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure7.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOC,&GPIO_InitStructure7);   
	//初始化PB6
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_TIM3);//复用设置
	
	 //GPIOC8的初始化 

	GPIO_InitStructure8.GPIO_Pin = GPIO_Pin_8 ;      
	GPIO_InitStructure8.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure8.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure8.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure8.GPIO_PuPd = GPIO_PuPd_DOWN;        //上拉
	GPIO_Init(GPIOC,&GPIO_InitStructure8);              //初始化PB6
	
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource8,GPIO_AF_TIM3);//复用设置
	
	 //GPIOC9的初始化 

	GPIO_InitStructure9.GPIO_Pin = GPIO_Pin_9 ;      
	GPIO_InitStructure9.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure9.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure9.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure9.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOC,&GPIO_InitStructure9);              //初始化PB6
	
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource9,GPIO_AF_TIM3);//复用设置
	
//初始化定时器4
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);//初始化定时器4
	
	
	//初始化TIM4 Channe1 PWM模式	 
	TIM_OCInitStructure1.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure1.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure1.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC1Init(TIM3,&TIM_OCInitStructure1);



//初始化TIM4 Channe2 PWM模式	
	TIM_OCInitStructure2.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure2.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure2.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC2Init(TIM3,&TIM_OCInitStructure2);
	
	
	//初始化TIM4 Channe3 PWM模式	
  TIM_OCInitStructure3.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure3.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure3.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC3Init(TIM3,&TIM_OCInitStructure3);
	
	
	//初始化TIM4 Channe4 PWM模式		
	TIM_OCInitStructure4.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure4.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure4.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC4Init(TIM3,&TIM_OCInitStructure4);
	

    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
 
    TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPE使能 
	
	TIM_Cmd(TIM3, ENABLE);  //使能TIM4
}

void Tim_Reset(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure1;
	

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//GPIOA时钟
 
  GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8;//E1234 前面的灰度  5678后面的灰度 9 10光电 11碰撞
	
  GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_UP;//下拉
  GPIO_Init(GPIOA, &GPIO_InitStructure1);//初始化GPIOE2,3,4



}


 
