/*
 * serwo.h
 *
 *  Created on: 03.05.2020
 *      Author: User
 */

#ifndef INC_SERWO_H_
#define INC_SERWO_H_

#include "tim.h"
#define ANGLE_MIN 0
#define ANGLE_MAX 180
/* zakres PWM */
#define PWM_MIN 400
#define PWM_MAX 2500
#define step (PWM_MAX/ANGLE_MAX)+PWM_MIN

void Servo_set_angle(TIM_HandleTypeDef *htim, uint32_t Channel,uint32_t angle);

#endif /* INC_SERWO_H_ */
