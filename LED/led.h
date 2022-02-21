// ***********************************************************************************
// ���������������: 1986��92�
// ����������: ���������� ����� �1986��92QI
// ����: led.h 
// ����������: ���������� ������������      
// ����������:  Armcc 5.03.0.76 �� ��������� Keil uVision 4.72.1.0 
// ***********************************************************************************

#ifndef __U_LED
 #define __U_LED

//#include "common.h"
#include "MDR32F9Qx_port.h"
#include "MDR32F9Qx_rst_clk.h"

// ���� �����������
#define U_LED_PORT MDR_PORTB
#define U_LED_11 PORT_Pin_11
#define U_LED_12 PORT_Pin_12
#define U_LED_13 PORT_Pin_13
#define U_LED_14 PORT_Pin_14
#define U_LED_15 PORT_Pin_15
// ���������������� ����������
void U_LED_Init (void);

// �������� ��������� ����������
void U_LED_Off (uint32_t Pins);

// ������ ��������� ����������
void U_LED_On (uint32_t Pins);

// ����������� ��������� ����������
void U_LED_Toggle (uint32_t Pins);

// ������ �� ������� ����� ����������� 
void U_LED_Task_Function (void);

#endif 

