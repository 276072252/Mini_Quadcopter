#include "stm32f10x.h"


#define Moto_PwmMax 1000
int16_t MOTO1_PWM = 0;
int16_t MOTO2_PWM = 0;
int16_t MOTO3_PWM = 0;
int16_t MOTO4_PWM = 0;


/******************************************************************************************
* ��  ����void MOTOR_Init(void)
* ��  �ܣ�������ų�ʼ�� �Լ�TIM3 �������PWM
* ��  ������
* ����ֵ����
* ��  ע��TIM1 CH4(PWM4) -> PA11
*         TIM1 CH3(PWM3) -> PA10
*         TIM1 CH2(PWM1) -> PA9
*         TIM1 CH1(PWM1) -> PA8

*******************************************************************************************/
void MOTOR_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;   //����GPIO�ṹ�����
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;   //���嶨ʱ���ṹ�����
	TIM_OCInitTypeDef TIM_OCInitStructure;   //��������ȽϽṹ�����
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_TIM1,ENABLE);   //GPIOA����ʱ�ӡ�TIM1ʱ��ʹ��

	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;   //����GPIO��8��9��10��11����
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;   	  //����GPIOΪ�����������
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;  	  //����GPIO����
	GPIO_Init(GPIOA,&GPIO_InitStruct);   //GPIO��ʼ������

	TIM_TimeBaseInitStruct.TIM_Period=1000-1;   	  //�����Զ���װ�ص�����ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler=100;   	  //����Ԥ��Ƶֵ
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;     //����ʱ�ӷָ�
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStruct);   		   //��ʱ����ʼ������
	
	TIM_OCInitStructure.TIM_Pulse = 0; 		//��װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  //TIM1�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//ʹ������Ƚ�״̬
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//ʹ������Ƚ�N״̬
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM1 ����Ƚϼ��Ը�
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 ����Ƚ�N���Ը�
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//�� MOE=0 ���� TIM1 ����ȽϿ���״̬
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//�� MOE=0 ���� TIM1 ����Ƚ� N ����״̬
	TIM_OC1Init(TIM1,&TIM_OCInitStructure);   					   //�Ƚ������ʼ������
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);   //����Ƚ�1Ԥװ�ؼĴ���ʹ��

	TIM_OCInitStructure.TIM_Pulse = 0; 		//��װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  //TIM1�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//ʹ������Ƚ�״̬
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//ʹ������Ƚ�N״̬
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM1 ����Ƚϼ��Ը�
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 ����Ƚ�N���Ը�
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//�� MOE=0 ���� TIM1 ����ȽϿ���״̬
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//�� MOE=0 ���� TIM1 ����Ƚ� N ����״̬
	TIM_OC2Init(TIM1,&TIM_OCInitStructure);   					   //�Ƚ������ʼ������
	TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);   //����Ƚ�1Ԥװ�ؼĴ���ʹ��

	TIM_OCInitStructure.TIM_Pulse = 0; 		//��װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  //TIM1�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//ʹ������Ƚ�״̬
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//ʹ������Ƚ�N״̬
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM1 ����Ƚϼ��Ը�
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 ����Ƚ�N���Ը�
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//�� MOE=0 ���� TIM1 ����ȽϿ���״̬
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//�� MOE=0 ���� TIM1 ����Ƚ� N ����״̬
	TIM_OC3Init(TIM1,&TIM_OCInitStructure);   					   //�Ƚ������ʼ������
	TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Enable);   //����Ƚ�1Ԥװ�ؼĴ���ʹ��

	TIM_OCInitStructure.TIM_Pulse = 0; 		//��װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  //TIM1�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//ʹ������Ƚ�״̬
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//ʹ������Ƚ�N״̬
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM1 ����Ƚϼ��Ը�
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 ����Ƚ�N���Ը�
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//�� MOE=0 ���� TIM1 ����ȽϿ���״̬
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//�� MOE=0 ���� TIM1 ����Ƚ� N ����״̬
	TIM_OC4Init(TIM1,&TIM_OCInitStructure);   					   //�Ƚ������ʼ������
	TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);   //����Ƚ�1Ԥװ�ؼĴ���ʹ��
	


	TIM_CtrlPWMOutputs(TIM1, ENABLE); 
  TIM_ARRPreloadConfig(TIM1,ENABLE);   
	TIM_Cmd(TIM1,ENABLE);   //TIM1ʹ��
}

/************************************************************************************************
* ��  ����void Moto_Pwm(int16_t MOTO1_PWM,int16_t MOTO2_PWM,int16_t MOTO3_PWM,int16_t MOTO4_PWM)
* ��  �ܣ����Ҫ�����ֵת����PWM�������
* ��  ����MOTO1_PWM ���1
*         MOTO2_PWM ���2
*         MOTO3_PWM ���3
*         MOTO3_PWM ���4
* ����ֵ���� 
* ��  ע����
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
