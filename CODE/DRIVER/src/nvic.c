#include "stm32f10x.h"

/*****************************************************************************
* ��  ����void NvicConfig(void)
* ��  �ܣ����ù����������жϵ����ȼ�
* ��  ������
* ����ֵ����
* ��  ע�������ȼ��жϲ�Ҫ������Ŷ
*****************************************************************************/
void NvicConfig(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;   //����NVIC�ṹ��
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�жϷ���2
	
	NVIC_InitStruct.NVIC_IRQChannel=TIM4_IRQn;   //TIM4�ж�ͨ��
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;   //��ռ���ȼ�0
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;   //�����ȼ�1
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;   //ʹ��TIM4�ж�ͨ��
	NVIC_Init(&NVIC_InitStruct);   //�ж����ȼ���ʼ������
	
	NVIC_InitStruct.NVIC_IRQChannel=USART2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;   //�����ⲿ�ж�ͨ��
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;   //������ռ���ȼ�Ϊ0
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;   //���������ȼ�Ϊ1
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;   //ʹ���ⲿ�ж�ͨ��
	NVIC_Init(&NVIC_InitStruct);   //�ж����ȼ���ʼ������
}

