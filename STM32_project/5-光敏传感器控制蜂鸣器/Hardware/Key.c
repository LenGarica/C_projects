#include "stm32f10x.h"
#include "Delay.h"

/*
 * @Author: zyx 1428431375@qq.com
 * @Date: 2023-06-27 11:12:14
 * @LastEditors: zyx 1428431375@qq.com
 * @LastEditTime: 2023-06-27 15:26:45
 * @FilePath: \4-按键控制LED\Hardware\Key.c
 * @Description: LED控制按键
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */


void Key_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_SetBits(GPIOB, GPIO_Pin_1 | GPIO_Pin_2);
}

uint8_t Key_GetNum(void){
    uint8_t KeyNum = 0;
	// 当按下键盘，会因为弹簧问题，需要进行消抖
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0){
		// 延迟20ms进行消抖
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0);
		Delay_ms(20);
		// 松手后，赋值为1
		KeyNum = 1;
	}
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0){
		// 延迟20ms进行消抖
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0);
		Delay_ms(20);
		// 松手后，赋值为1
		KeyNum = 2;
	}
    return KeyNum;
}
