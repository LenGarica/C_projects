#include "stm32f10x.h"
/*
 * @Author: zyx 1428431375@qq.com
 * @Date: 2023-06-27 10:52:46
 * @LastEditors: zyx 1428431375@qq.com
 * @LastEditTime: 2023-06-27 15:24:56
 * @FilePath: \4-按键控制LED\Hardware\LED.c
 * @Description: 封装LED驱动程序
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */


/**
 * @description: 初始化LED等
 * @return {*}
 */
void LED_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);

}

/**
 * @description: 使能够使用一个按键对一个LED1进行打开和关闭
 * @return {*}
 */
void LED1_Turn(void){
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0) {
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	}else{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
}

/**
 * @description: 使能够使用一个按键对一个LED2进行打开和关闭
 * @return {*}
 */
void LED2_Turn(void){
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0) {
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	}else{
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}
}

/**
 * @description: LED1打开
 * @return {*}
 */
void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

/**
 * @description: LED1关闭
 * @return {*}
 */
void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

/**
 * @description: LED2打开
 * @return {*}
 */
void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

/**
 * @description: LED2关闭
 * @return {*}
 */
void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}
