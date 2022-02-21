// ***********************************************************************************
// ���������������: 1986��92�
// ����������: ���������� ����� �1986��92QI
// ����: led.c 
// ����������: ���������� ������������      
// ����������:  Armcc 5.03.0.76 �� ��������� Keil uVision 4.72.1.0 
// ***********************************************************************************
#include "led.h"


// ���������������� ����������
void U_LED_Init (void)
{
	// ��������� ��� ������������� ������
	PORT_InitTypeDef PortInitStructure;	

  // ��������� ������������ ��������� ������������ ���������
  RST_CLK_PCLKcmd (RST_CLK_PCLK_PORTB, ENABLE);	
	
  // ������� �������� �����, � ������� ���������� ����������
  PORT_StructInit (&PortInitStructure);	
  PortInitStructure.PORT_Pin   = U_LED_11 | U_LED_12 | U_LED_13 | U_LED_14|U_LED_15;
  PortInitStructure.PORT_MODE  = PORT_MODE_DIGITAL;
  PortInitStructure.PORT_FUNC  = PORT_FUNC_PORT;
  PortInitStructure.PORT_OE    = PORT_OE_OUT;
	PortInitStructure.PORT_SPEED = PORT_SPEED_SLOW;
  PORT_Init (U_LED_PORT, &PortInitStructure);	

	// �������� ��� ����������
	U_LED_Off (U_LED_11 | U_LED_12 | U_LED_13 | U_LED_14|U_LED_15);
}

// �������� ��������� ����������
void U_LED_Off (uint32_t Pins)
{
	PORT_ResetBits (U_LED_PORT, Pins);
}

// ������ ��������� ����������
void U_LED_On (uint32_t Pins)
{
	PORT_SetBits (U_LED_PORT, Pins);
}

// ����������� ��������� ����������
void U_LED_Toggle (uint32_t Pins)
{
	uint32_t data;
	
	data	= PORT_ReadInputData (U_LED_PORT);
	PORT_Write (U_LED_PORT, data ^= Pins);
}



