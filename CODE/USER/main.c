#include "main.h"
int main(void)
{


	System_Init(); //系统初始化
	
	while(1)
	{
		Task_Schedule(); //任务调度

	}

}
