#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，试用24小时后删除								  
//////////////////////////////////////////////////////////////////////////////////   	 


//#define KEY0 PCin(5)   	
//#define KEY1 PAin(15)	 
//#define WK_UP  PEin(0)	 
 

#define KEY0  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)//读取按键2
#define KEY1  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)//读取按键
#define WK_UP   GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0)//读取按键3 
 

#define KEY0_PRES	1		//KEY0  
#define KEY1_PRES	2		//KEY1 
#define WKUP_PRES	3		//WK_UP  

void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8 mode);  	//按键扫描函数					    
#endif
