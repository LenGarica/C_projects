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
#include "Encode.h"

int16_t Num;


int main(void){

	OLED_Init();
	Encode_Init();
	OLED_ShowString(1, 1, "Num:");

	while (1)
	{
		Num += Encode_Get();
		OLED_ShowSignedNum(1, 5, Num, 5);
	}
	
}
