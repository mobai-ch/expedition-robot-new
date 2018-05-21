#ifndef __PWM__
#define __PWM__
#include "sys.h"


void TIM4CH_PWM_Init(u32 arr,u32 psc);


void TIM3CH_PWM_Init(u32 arr,u32 psc);

void Tim_Reset(void);


#endif
