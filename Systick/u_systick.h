#ifndef 	__U_SYSTICK_H
 #define 	__U_SYSTICK_H
 


 #include "MDR32F9Qx_port.h"
 #include "MDR32F9Qx_rst_clk.h"
void Init_SysTick (void);
void SysTick_Handler (void);
void Sys_Delay_ms  (uint32_t Delay_ms_Data);

 
#endif 		__U_SYSTICK_H  //
