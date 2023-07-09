/*
 * @Author: zyx 1428431375@qq.com
 * @Date: 2023-07-03 15:16:01
 * @LastEditors: zyx 1428431375@qq.com
 * @LastEditTime: 2023-07-03 15:33:58
 * @FilePath: \6-OLED控制\User\main.c
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */

#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "CountSensor.h"


int main(void){

	OLED_Init();
	CountSensor_Init();
	OLED_ShowString(1, 1, "Count:");

	while (1)
	{
		OLED_ShowNum(1, 7, CountSensor_Get(), 5);
	}
	
}
