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
	// 开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	/**
	 * GPIO_Mode_AIN（模拟输入模式）：
	 * 用于将GPIO引脚配置为模拟输入模式，适用于连接模拟传感器或其他模拟输入设备。
	 * 
	 * GPIO_Mode_IN_FLOATING（浮空输入模式）：
	 * 用于将GPIO引脚配置为浮空输入模式，即未连接到任何外部设备时，引脚处于高阻态。
	 * 适用于连接开关、按键等需要检测高低电平的输入设备。
     * 
	 * GPIO_Mode_IPD（上拉输入模式）：
	 * 用于将GPIO引脚配置为上拉输入模式，即在未连接到外部设备时，引脚上拉至高电平。
	 * 适用于连接开关、按键等需要检测低电平的输入设备。
     * 
	 * GPIO_Mode_IPU（下拉输入模式）：
	 * 用于将GPIO引脚配置为下拉输入模式，即在未连接到外部设备时，引脚下拉至低电平。
	 * 适用于连接开关、按键等需要检测高电平的输入设备。
	 * 
	 * GPIO_Mode_Out_OD（开漏输出模式）：
	 * 用于将GPIO引脚配置为开漏输出模式，即引脚在输出低电平时为低电平，输出高电平时为高阻态。
	 * 适用于连接需要共享总线的设备，如I2C总线。
	 * 
	 * GPIO_Mode_Out_PP（推挽输出模式）：
	 * 用于将GPIO引脚配置为推挽输出模式，即引脚在输出低电平时为低电平，输出高电平时为高电平。
	 * 适用于连接需要提供较大电流驱动能力的设备。
	 * 
	 * GPIO_Mode_AF_OD（复用功能开漏输出模式）：
	 * 用于将GPIO引脚配置为复用功能开漏输出模式，即引脚同时具有GPIO和其他功能，且在输出时为开漏输出。
	 * 适用于连接需要共享总线的设备，如I2C总线。
	 * 
	 * GPIO_Mode_AF_PP（复用功能推挽输出模式）：
	 * 用于将GPIO引脚配置为复用功能推挽输出模式，即引脚同时具有GPIO和其他功能，且在输出时为推挽输出。
	 * 适用于连接需要提供较大电流驱动能力的设备
	*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	/**
	 * GPIO_Pin是指通用输入/输出引脚，也被称为GPIO引脚。
	 * 在嵌入式系统中，GPIO引脚可以被配置为输入或输出模式，用于连接外部设备或与其他芯片进行通信。
	 * 每个GPIO引脚都有一个唯一的标识符，通常使用数字来表示。
	 * 通过读取或写入GPIO引脚的电平状态，可以实现与外部设备的交互。
	 * 例如，将GPIO引脚配置为输出模式，可以通过设置高电平或低电平来控制外部设备的开关。
	 * 同样，将GPIO引脚配置为输入模式，可以读取外部设备的电平状态。
	 * GPIO引脚的功能和配置方法可能因芯片和开发平台而异。
	*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	/**
	 * 2MHz、10MHz、50MHz
	*/
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// 初始化GPIO接口
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	// GPIO_SetBits函数用于将指定的GPIO引脚设置为高电平，即置1的操作
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

/**
 * @description: 蜂鸣器打开
 * @return {*}
 */
void Buzzer_ON(void)
{
	// GPIO_ResetBits函数用于将指定的GPIO引脚设置为低电平，即置0的操作
	// GPIO_WriteBit(GPIOB, GPIO_Pin_12, BIT_SET);支持BIT_SET/BIT_RESET，写1或写0
	// GPIO_Write(GPIOB, 0XFFFF); 直接对某一组的引脚写值
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
