#include "stm32f10x.h"
#include "stdio.h"


/*****************************************************************************
* ��  ����void USART_init(uint32_t baudrate)
* ��  �ܣ�Usart2��ʼ��Ϊ˫��ģʽ
* ��  ����baudrate ������
* ����ֵ����
* ��  ע����������������֡�Ľ��� �����ж�������ж�����ܽ���������⣬
          ������շ�ʽ��stm32f1x_it.c �еĴ����жϴ���;
*****************************************************************************/
void USART_init(uint32_t baudrate)
{
	GPIO_InitTypeDef GPIO_InitStruct;   //����GPIO�ṹ�����
	USART_InitTypeDef USART_InitStruct;   //���崮�ڽṹ�����
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);   //ʹ��GPIOA��USART2��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_2;   //����TX����
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;   //����PA2Ϊ�����������
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;   //����PA2����
	GPIO_Init(GPIOA,&GPIO_InitStruct);   //GPIO��ʼ������
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_3;   //����RX����
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;   //����PA3Ϊ��������
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;   //����PA3����
	GPIO_Init(GPIOA,&GPIO_InitStruct);   //GPIO��ʼ������
	
	
	USART_InitStruct.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;   //���ͽ���ģʽ
	USART_InitStruct.USART_Parity=USART_Parity_No;   //����żУ��
	USART_InitStruct.USART_BaudRate=baudrate;   //������
	USART_InitStruct.USART_StopBits=USART_StopBits_1;   //ֹͣλ1λ
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;   //�ֳ�8λ
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;   //��Ӳ������������
	USART_Init(USART2,&USART_InitStruct);   //���ڳ�ʼ������
	
	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);		//���ڽ����ж�
	USART_ITConfig(USART2,USART_IT_IDLE,ENABLE);		//���ڿ����ж�
	
	USART_Cmd(USART2,ENABLE);   //ʹ��USART2
}

/*****************************************************************************
* ��  ����int fputc(int ch, FILE *f)
* ��  �ܣ��ض��� printf()����
* ��  ����ch Ҫ���͵�����
* ����ֵ����
* ��  ע����
*****************************************************************************/
int fputc(int ch,FILE *f)   //printf�ض�����
{
	USART_SendData(USART2,(uint8_t)ch);   //����һ�ֽ�����
	while(USART_GetFlagStatus(USART2,USART_FLAG_TXE) == RESET);   //�ȴ��������
	return ch;
}

/*****************************************************************************
* ��  ����void usart_send(uint8_t *data,uint8_t len)
* ��  �ܣ�Usart����ָ����������
* ��  ����*data Ҫ�������ݵĵ�ַ
*         len   Ҫ�������ݵĳ���
* ����ֵ����
* ��  ע����
*****************************************************************************/
void usart_send(uint8_t *data,uint8_t len)
{
	uint8_t i;
	
	for(i=0;i<len;i++)
	{
		USART_SendData(USART2,*(data+i));
		while(USART_GetFlagStatus(USART2,USART_FLAG_TC) == RESET);
	}
}


