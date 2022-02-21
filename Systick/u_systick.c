#include "u_systick.h"
#define CLKSOURCE (1<<2)
#define TCKINT 		(1<<1)
#define ENABLE 		(1<<0)
volatile uint32_t Delay_dec = 0;	

void Init_SysTick (void)                          //Прерывание раз в милли секунду. 
{
	SysTick->LOAD |= (8000000/1000)-1;              
	SysTick->CTRL |= CLKSOURCE|TCKINT|ENABLE;
}

void SysTick_Handler (void)
{
	if (Delay_dec) Delay_dec--;
}

void Sys_Delay_ms (uint32_t Delay_ms_Data)
{
	Delay_dec = Delay_ms_Data;
	while (Delay_dec) {};
}
