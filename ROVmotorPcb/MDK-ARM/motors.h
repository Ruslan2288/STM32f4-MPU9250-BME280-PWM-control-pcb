#include "main.h"

#ifndef _MOTORS_H_
#define _MOTORS_H_



void initAllMotors();
void setMotorThrust( TIM_TypeDef *motorTimer, uint8_t motorChanel, uint8_t thrust );



#endif