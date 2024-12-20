#include "IRAvoid.h"
#include "delay.h"
#include "motor.h"
#include "keysacn.h"
#include "stm32f10x.h"                  // Device header

int SR_2;    //右边红外避障传感器状态
int SL_2;    //左边红外壁障传感器状态
void IRAvoidInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA , ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = AVOID_RIGHT_PIN;//配置使能GPIO管脚 PB4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,输入上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//配置GPIO端口速度
	GPIO_Init(AVOID_RIGHT_PIN_GPIO , &GPIO_InitStructure); 
	
  GPIO_InitStructure.GPIO_Pin = AVOID_LEFT_PIN;//配置使能GPIO管脚 PB5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,输入上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//配置GPIO端口速度
	GPIO_Init(AVOID_LEFT_PIN_GPIO , &GPIO_InitStructure); 
}


void AVoidRun(void)
{
	SR_2 = AVOID_RIGHT_IO;
	SL_2 = AVOID_LEFT_IO;
	if(SL_2 == 1 && SR_2 == 1)
	{
		 HJduino_run(60,10); //前进
		 BEEP_SET;
     LED_D3_RESET;	//低电平 点亮L1 
     LED_D4_SET;		//高电平 关L2
	}
	else
	{
		 BEEP_RESET;  //FM发声音
     LED_D3_SET;	
		 LED_D4_RESET;	//低电平 点亮L2
		 HJduino_back(60,10);//后退
			
				
	}
	
}
