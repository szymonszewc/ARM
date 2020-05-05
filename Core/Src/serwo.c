/*
 * serwo.c
 *
 *  Created on: 03.05.2020
 *      Author: User
 */

#include "serwo.h"
void Servo_set_angle(TIM_HandleTypeDef *htim, uint32_t Channel,uint32_t angle)
{
	if(angle<0)
	{
		angle=0;
	}
	if(angle>180)
	{
		angle=180;
	}
	uint16_t val=angle*step;
	__HAL_TIM_SET_COMPARE(htim, Channel, val);
}
