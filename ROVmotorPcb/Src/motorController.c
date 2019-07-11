#include "motorController.h"

#define MAX_CCR 105
#define MIN_CCR 45
#define DEAD_ZONE_OF_CCR 1

int Constrain( int value, int minValue, int maxValue )
{
	if( value > maxValue )
	{
		value = maxValue;
	}
	else if( value < minValue )
	{
		value = minValue;
	}
	return value;
	
}

void MotorsInit( TIM_HandleTypeDef *timHandle1, TIM_HandleTypeDef *timHandle2 ) 
{
	timHandle1->Instance->CCR1 = 75;
	timHandle1->Instance->CCR2 = 75;
	timHandle1->Instance->CCR3 = 75;
	timHandle1->Instance->CCR4 = 75;
	
	timHandle2->Instance->CCR2 = 75;
	timHandle2->Instance->CCR3 = 75;
	
	HAL_Delay(5000);
	
}
void SetMotorThrust( int Force, TIM_HandleTypeDef *timHandle, int timChanel )
{
	
	Force = Constrain( Force, -100, 100 );
	
	int ccr = 75 + (int)(Force/(200/(MAX_CCR-MIN_CCR)));
	
	ccr = Constrain( ccr, MIN_CCR, MAX_CCR );
	
	if ( ccr < 75 + DEAD_ZONE_OF_CCR && ccr >= 75 )
	{
		ccr = 75 + DEAD_ZONE_OF_CCR;
	}
	else if( ccr > 75 - DEAD_ZONE_OF_CCR && ccr < 75 )
	{
		ccr = 75 - DEAD_ZONE_OF_CCR;
	}
	
	switch ( timChanel )
	{
		
		case 1:
		timHandle->Instance->CCR1 = (int)ccr; break;		
		case 2:
		timHandle->Instance->CCR2 = (int)ccr; break;		
		case 3:
		timHandle->Instance->CCR3 = (int)ccr; break;	
		case 4:
		timHandle->Instance->CCR4 = (int)ccr; break;	
		default: break;
		
	}

}
