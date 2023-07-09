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


int main(void){

	OLED_Init();
	OLED_ShowChar(1, 1, 'A');
	OLED_ShowString(1, 3, "HelloWorld");
	OLED_ShowNum(2, 1, 12345, 5);
	OLED_ShowSignedNum(2, 7, 12345, 5); // 带符号的数值
	OLED_ShowHexNum(3, 1, 0xAA55, 4);
	OLED_ShowBinNum(4, 1, 0xAA55, 16);


	while (1)
	{
	}
	
}
