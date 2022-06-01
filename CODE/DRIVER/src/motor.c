#include "stm32f10x.h"


#define Moto_PwmMax 1000
int16_t MOTO1_PWM = 0;
int16_t MOTO2_PWM = 0;
int16_t MOTO3_PWM = 0;
int16_t MOTO4_PWM = 0;


/******************************************************************************************
* 函  数：void MOTOR_Init(void)
* 功  能：电机引脚初始化 以及TIM3 配置输出PWM
* 参  数：无
* 返回值：无
* 备  注：TIM1 CH4(PWM4) -> PA11
*         TIM1 CH3(PWM3) -> PA10
*         TIM1 CH2(PWM1) -> PA9
*         TIM1 CH1(PWM1) -> PA8

*******************************************************************************************/
void MOTOR_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;   //定义GPIO结构体变量
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;   //定义定时器结构体变量
	TIM_OCInitTypeDef TIM_OCInitStructure;   //定义输出比较结构体变量
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_TIM1,ENABLE);   //GPIOA复用时钟、TIM1时钟使能

	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;   //配置GPIO第8、9、10、11引脚
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;   	  //配置GPIO为复用推挽输出
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;  	  //配置GPIO速率
	GPIO_Init(GPIOA,&GPIO_InitStruct);   //GPIO初始化函数

	TIM_TimeBaseInitStruct.TIM_Period=1000-1;   	  //设置自动重装载的周期值
	TIM_TimeBaseInitStruct.TIM_Prescaler=100;   	  //设置预分频值
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;     //设置时钟分割
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStruct);   		   //定时器初始化函数
	
	TIM_OCInitStructure.TIM_Pulse = 0; 		//待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  //TIM1脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//使能输出比较状态
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//使能输出比较N状态
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM1 输出比较极性高
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 输出比较N极性高
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较空闲状态
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较 N 空闲状态
	TIM_OC1Init(TIM1,&TIM_OCInitStructure);   					   //比较输出初始化函数
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);   //输出比较1预装载寄存器使能

	TIM_OCInitStructure.TIM_Pulse = 0; 		//待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  //TIM1脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//使能输出比较状态
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//使能输出比较N状态
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM1 输出比较极性高
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 输出比较N极性高
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较空闲状态
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较 N 空闲状态
	TIM_OC2Init(TIM1,&TIM_OCInitStructure);   					   //比较输出初始化函数
	TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);   //输出比较1预装载寄存器使能

	TIM_OCInitStructure.TIM_Pulse = 0; 		//待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  //TIM1脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//使能输出比较状态
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//使能输出比较N状态
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM1 输出比较极性高
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 输出比较N极性高
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较空闲状态
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较 N 空闲状态
	TIM_OC3Init(TIM1,&TIM_OCInitStructure);   					   //比较输出初始化函数
	TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Enable);   //输出比较1预装载寄存器使能

	TIM_OCInitStructure.TIM_Pulse = 0; 		//待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  //TIM1脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//使能输出比较状态
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//使能输出比较N状态
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM1 输出比较极性高
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 输出比较N极性高
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较空闲状态
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较 N 空闲状态
	TIM_OC4Init(TIM1,&TIM_OCInitStructure);   					   //比较输出初始化函数
	TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);   //输出比较1预装载寄存器使能
	


	TIM_CtrlPWMOutputs(TIM1, ENABLE); 
  TIM_ARRPreloadConfig(TIM1,ENABLE);   
	TIM_Cmd(TIM1,ENABLE);   //TIM1使能
}

/************************************************************************************************
* 函  数：void Moto_Pwm(int16_t MOTO1_PWM,int16_t MOTO2_PWM,int16_t MOTO3_PWM,int16_t MOTO4_PWM)
* 功  能：电机要输出数值转换成PWM波形输出
* 参  数：MOTO1_PWM 电机1
*         MOTO2_PWM 电机2
*         MOTO3_PWM 电机3
*         MOTO3_PWM 电机4
* 返回值：无 
* 备  注：无
************************************************************************************************/
void Moto_Pwm(int16_t MOTO1_PWM,int16_t MOTO2_PWM,int16_t MOTO3_PWM,int16_t MOTO4_PWM)
{		
	if(MOTO1_PWM>Moto_PwmMax)	MOTO1_PWM = Moto_PwmMax;
	if(MOTO2_PWM>Moto_PwmMax)	MOTO2_PWM = Moto_PwmMax;
	if(MOTO3_PWM>Moto_PwmMax)	MOTO3_PWM = Moto_PwmMax;
	if(MOTO4_PWM>Moto_PwmMax)	MOTO4_PWM = Moto_PwmMax;
	if(MOTO1_PWM<0)	MOTO1_PWM = 0;
	if(MOTO2_PWM<0)	MOTO2_PWM = 0;
	if(MOTO3_PWM<0)	MOTO3_PWM = 0;
	if(MOTO4_PWM<0)	MOTO4_PWM = 0;
	
	TIM1->CCR2 = MOTO1_PWM;
	TIM1->CCR1 = MOTO2_PWM;
	TIM1->CCR4 = MOTO3_PWM;
	TIM1->CCR3 = MOTO4_PWM;
}
