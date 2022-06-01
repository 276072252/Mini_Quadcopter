#include "stm32f10x.h"

/*****************************************************************************
* 函  数：void NvicConfig(void)
* 功  能：配置工程中所有中断的优先级
* 参  数：无
* 返回值：无
* 备  注：此优先级中断不要随便更改哦
*****************************************************************************/
void NvicConfig(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;   //定义NVIC结构体
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //中断分组2
	
	NVIC_InitStruct.NVIC_IRQChannel=TIM4_IRQn;   //TIM4中断通道
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;   //抢占优先级0
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;   //子优先级1
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;   //使能TIM4中断通道
	NVIC_Init(&NVIC_InitStruct);   //中断优先级初始化函数
	
	NVIC_InitStruct.NVIC_IRQChannel=USART2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;   //配置外部中断通道
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;   //设置抢占优先级为0
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;   //设置子优先级为1
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;   //使能外部中断通道
	NVIC_Init(&NVIC_InitStruct);   //中断优先级初始化函数
}

