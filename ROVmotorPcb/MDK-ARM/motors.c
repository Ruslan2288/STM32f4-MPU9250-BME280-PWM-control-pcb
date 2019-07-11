#include "motors.h"

void initAllMotors()
{
	TIM2->CCR1=125;
	TIM2->CCR2=125;
	TIM2->CCR3=125;
	TIM2->CCR4=125;
	
	TIM3->CCR1=125;
	TIM3->CCR2=125;
	TIM3->CCR3=125;
	TIM3->CCR4=125;
	
	/*TIM8->CCR1=125;
	TIM8->CCR2=125;
	TIM8->CCR2=125;
	TIM8->CCR2=125;*/
	
	HAL_Delay(2000);
	
	
}

void setMotorThrust( TIM_TypeDef *motorTimer, uint8_t motorChanel, uint8_t thrust )
{
	
}