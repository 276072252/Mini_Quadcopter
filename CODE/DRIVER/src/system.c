#include "main.h"

void System_Init(void)
{
	NvicConfig(); //系统中断优先级管理
	LED_Init();		//用户指示灯初始化
	Delay_Init(); //系统延时初始化
	USART_init(460800);	//调试串口初始化
	IIC_GPIO_Init(); //模拟IIC初始化
	TIM_Init();	//系统时基初始化
	Exit_Init(); //外部中断初始化
	SI24R1_Init(); //SI24R1(2.4G)初始化（红）
 	MPU6050_Init(); //MPU6050初始化（绿） 
//	FBM320_Init(); //FBM320初始化(气压计蓝) 
	MOTOR_Init(); //电机输出初始化
	BATT_Init(); //电池电压检测初始化
	PID_ReadFlash(); //Flash中的数据读取
	PidParameter_init(); //PID参数初始化
	RGB_LED_Off();	//初始化关闭所有RGB灯
	
	printf("System Init Finish\n");
}

void Task_Schedule(void)
{
	if(ANO_Scan) //500Hz
		{
			ANO_Scan = 0;
			ANO_DT_Data_Exchange(); //更新数据到上位机
		}
		if(IMU_Scan) //200Hz
		{
			IMU_Scan  = 0;
			Prepare_Data(); //获取姿态解算所需数据
			IMUupdate(&Gyr_rad,&Acc_filt,&Att_Angle); //四元数姿态解算
			Control(&Att_Angle,&Gyr_rad,&RC_Control,Airplane_Enable); //姿态控制
		}
		if(LED_Scan) //10Hz
		{
			LED_Scan = 0;
			LED_Run();
			if(!Airplane_Enable&&Run_flag)
			{
				RGB_LED_Runing(); //飞机上锁状态灯
			}
			BATT_Alarm_LED(); //电池低电压报警	  
		}
		if(IRQ_Scan) //5Hz
		{
			IRQ_Scan = 0;
			SI24R1_SingalCheck(); //2.4G通信检测
			SendToRemote(); //发送数据给遥控器
		}
		if(Batt_Scan) //2.5Hz
		{
			Batt_Scan = 0;
			SI24R1_GetAddr(); //分配2.4G地址
			LowVoltage_Alarm();	//低电量报警
		}
}


