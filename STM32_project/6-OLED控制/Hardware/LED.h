/*
 * @Author: zyx 1428431375@qq.com
 * @Date: 2023-06-27 10:53:23
 * @LastEditors: zyx 1428431375@qq.com
 * @LastEditTime: 2023-06-27 15:25:44
 * @FilePath: \4-按键控制LED\Hardware\LED.h
 * @Description: 对外提供封装的函数或者变量
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __LED_H
#define __LED_H

void LED_Init(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED2_ON(void);
void LED2_OFF(void);
void LED1_Turn(void);
void LED2_Turn(void);

#endif
