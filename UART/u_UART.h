
#ifndef __U_UART
 #define __U_UART
 
#include "MDR32F9Qx_port.h"
#include "MDR32F9Qx_uart.h"
#include "MDR32F9Qx_rst_clk.h"


void u_UART_Init (void);

// ������� (Event) ������������ �������
//#define EVENT_UART 0x0001
// ������ �� ������ ������, ������������ ����� UART 
//extern OS_TID U_UART_Task_ID;  // ���������� ��� �������� �������������� ������
//__task void U_UART_Task_Function (void);
#endif
