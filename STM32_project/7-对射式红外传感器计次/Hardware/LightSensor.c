/*
 * @Author: zyx 1428431375@qq.com
 * @Date: 2023-06-27 17:00:20
 * @LastEditors: zyx 1428431375@qq.com
 * @LastEditTime: 2023-06-27 17:08:26
 * @FilePath: \5-光敏传感器控制蜂鸣器\Hardware\LightSensor.c
 * @Description: 光敏传感器
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "stm32f10x.h"

/**
 * @description: 初始化蜂鸣器
 * @return {*}
 */
void LightSensor_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

}

/**
 * @description: 
 * @return {*}
 */
uint8_t LightSensor_Get(void) {
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
}
