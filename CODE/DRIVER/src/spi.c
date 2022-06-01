#include "stm32f10x.h"
/*****************************************************************************
* 函  数：void SPI_GPIO_Init(void)
* 功  能：配置SI24R1的 SCK、MISO、MOSI引脚，以及SPI1初始化
* 参  数：无
* 返回值：无
* 备  注：调试SPI通信时一定要分清主机从机模式
*         主机从机模式的 空闲状态 电平
*		  2.4G模块通信时，SPI速率一般不大于10Mbps
*****************************************************************************/
void SPI_GPIO_Init(void)
{
	SPI_InitTypeDef   SPI_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);

	//配置SPI的SCK，MISO和MOSI引脚为复用推挽模式
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	 
	SPI_InitStructure.SPI_Mode=SPI_Mode_Master;	//配置为主机模式
	SPI_InitStructure.SPI_NSS=SPI_NSS_Soft;		//NSS软件管理
	SPI_InitStructure.SPI_CPHA=SPI_CPHA_1Edge;	//第一个时钟沿捕获
	SPI_InitStructure.SPI_CPOL=SPI_CPOL_Low;	//空闲状态为低电平
	SPI_InitStructure.SPI_DataSize=SPI_DataSize_8b;						//8位数据帧
	SPI_InitStructure.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_16; 	//SPI波特率16分频 	72/16=4.5M
	SPI_InitStructure.SPI_Direction=SPI_Direction_2Lines_FullDuplex;	//全双工模式
	SPI_InitStructure.SPI_FirstBit=SPI_FirstBit_MSB;					//数据高位先行
	SPI_InitStructure.SPI_CRCPolynomial=7;								//CRC计算多项式
	SPI_Init(SPI1,&SPI_InitStructure);
	
	SPI_Cmd(SPI1,ENABLE);	//SPI1使能
}





/*****************************************************************************
* 函  数：uint8_t SPI2_WriteReadByte(uint8_t data)
* 功  能：SPI1读写一个字节
* 参  数：无
* 返回值：无
* 备  注：无
*****************************************************************************/
uint8_t SPI1_WriteReadByte(uint8_t data)
{
	 while(!SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE));
	 SPI_I2S_SendData(SPI1, data);
	
	 while(!SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE));
	 return SPI_I2S_ReceiveData(SPI1);
}


