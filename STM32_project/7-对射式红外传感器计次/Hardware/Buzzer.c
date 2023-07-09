/*
 * @Author: zyx 1428431375@qq.com
 * @Date: 2023-06-27 15:37:59
 * @LastEditors: zyx 1428431375@qq.com
 * @LastEditTime: 2023-06-27 16:55:09
 * @FilePath: \5-光敏传感器控制蜂鸣器\Hardware\Buzzer.c
 * @Description: 光敏传感器控制蜂鸣器
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "stm32f10x.h"

/**
 * @description: 初始化蜂鸣器
 * @return {*}
 */
void Buzzer_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

/**
 * @description: 蜂鸣器打开
 * @return {*}
 */
void Buzzer_ON(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
}

/**
 * @description: 蜂鸣器关闭
 * @return {*}
 */
void Buzzer_OFF(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

/**
 * @description: 使能够使用一个按键对一个蜂鸣器进行打开和关闭
 * @return {*}
 */
void Buzzer_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12) == 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	}
}
