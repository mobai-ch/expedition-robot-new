#include  "Gray.h"



//配置各个的IO口的输出输入 E1~4 前面的灰度  E5~8后面的灰度  E9~10光电开关  11碰撞开关


//配置各个的IO口的输出输入 E1~4 前面的灰度  E5~8后面的灰度  E9~10光电开关  11碰撞开关 

//碰撞模块未触碰高电平 1

//灰度白线上0 黑线上1

//光电没有障碍物高电平
void Gray_Init(void){
	GPIO_InitTypeDef  GPIO_InitStructure1;	
	GPIO_InitTypeDef  GPIO_InitStructure2;
	GPIO_InitTypeDef  GPIO_InitStructure3;
	GPIO_InitTypeDef  GPIO_InitStructure4;
    GPIO_InitTypeDef  GPIO_InitStructure5;
    GPIO_InitTypeDef  GPIO_InitStructure6;
	
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//GPIOE时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//GPIOF时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//GPIOA时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//GPIOB时钟
	
    GPIO_InitStructure6.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;
	
    GPIO_InitStructure6.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
    GPIO_InitStructure6.GPIO_Speed = GPIO_Speed_100MHz;//100M
    GPIO_InitStructure6.GPIO_PuPd = GPIO_PuPd_UP;//下拉
    GPIO_Init(GPIOA, &GPIO_InitStructure6);//初始化GPIOE2,3,4	
	
	
    GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10;//E1234 前面的灰度  5678后面的灰度 9 10光电 11碰撞
	
    GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
    GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_100MHz;//100M
    GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_UP;//下拉
    GPIO_Init(GPIOE, &GPIO_InitStructure1);//初始化GPIOE2,3,4
	
    GPIO_InitStructure2.GPIO_Pin = GPIO_Pin_11;	
    GPIO_InitStructure2.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
    GPIO_InitStructure2.GPIO_Speed = GPIO_Speed_100MHz;//100M
    GPIO_InitStructure2.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(GPIOE, &GPIO_InitStructure2);//初始化GPIOE2,3,4
	
    GPIO_InitStructure3.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
    GPIO_InitStructure3.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
    GPIO_InitStructure3.GPIO_Speed = GPIO_Speed_50MHz;//50M
    GPIO_InitStructure3.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOD, &GPIO_InitStructure3);
	
	
    GPIO_InitStructure4.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;
    GPIO_InitStructure4.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
    GPIO_InitStructure4.GPIO_Speed = GPIO_Speed_50MHz;//50M
    GPIO_InitStructure4.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOF, &GPIO_InitStructure4);
  
    GPIO_InitStructure5.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4| GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7;//LED0和LED1对应IO口
    GPIO_InitStructure5.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
    GPIO_InitStructure5.GPIO_OType = GPIO_OType_PP;//推挽输出
    GPIO_InitStructure5.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    GPIO_InitStructure5.GPIO_PuPd = GPIO_PuPd_DOWN;//上拉
    GPIO_Init(GPIOB, &GPIO_InitStructure5);//初始化GPIO
	
    //GPIO_SetBits(GPIOB,GPIO_Pin_3 | GPIO_Pin_4| GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7);//GPIOF9,F10设置高，灯灭
  

} 

