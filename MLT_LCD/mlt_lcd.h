// ***********************************************************************************
// ���������������: 1986��92�
// ����������: ���������� ����� �1986��92QI
// ����: mlt_lcd.h 
// ����������:  ������ � ��� MT�12864J 
//              ��� ����������� �������� "��������" �145��10 (������ Samsung KS0108)
// ����������:  Armcc 5.03.0.76 �� ��������� Keil uVision 4.72.1.0 
// ***********************************************************************************

#ifndef __MLT_LCD_H
  #define __MLT_LCD_H
	


#include "string.h"
#include "mlt_fonts.h"
#include "stdint.h"
// ������ ������ � ��������
#define	U_MLT_SCREEN_WIDTH_SYMBOLS	16
// ������ ������ � ��������
#define	U_MLT_SCREEN_HEIGHT_SYMBOLS	4

// ���������� � �������� ����� Reset
#define	U_MLT_Set_Res_Pin		PORT_SetBits   (MDR_PORTD, PORT_Pin_9);
#define	U_MLT_Clr_Res_Pin		PORT_ResetBits (MDR_PORTD, PORT_Pin_9);

// ���������� � �������� ����� E
#define	U_MLT_Set_Stb_Pin		PORT_SetBits   (MDR_PORTC, PORT_Pin_7);
#define	U_MLT_Clr_Stb_Pin		PORT_ResetBits (MDR_PORTC, PORT_Pin_7);

// ���������� � �������� ����� RW
#define	U_MLT_Set_RW_Pin		PORT_SetBits   (MDR_PORTC, PORT_Pin_2);
#define	U_MLT_Clr_RW_Pin		PORT_ResetBits (MDR_PORTC, PORT_Pin_2);

// ���������� � �������� ����� A0
#define	U_MLT_Set_A0_Pin		PORT_SetBits   (MDR_PORTE, PORT_Pin_11);
#define	U_MLT_Clr_A0_Pin		PORT_ResetBits (MDR_PORTE, PORT_Pin_11);

// ���������� � �������� ����� E1
#define	U_MLT_Set_E1_Pin		PORT_SetBits   (MDR_PORTE, PORT_Pin_4);
#define	U_MLT_Clr_E1_Pin		PORT_ResetBits (MDR_PORTE, PORT_Pin_4);

// ���������� � �������� ����� E2
#define	U_MLT_Set_E2_Pin		PORT_SetBits   (MDR_PORTE, PORT_Pin_5);
#define	U_MLT_Clr_E2_Pin		PORT_ResetBits (MDR_PORTE, PORT_Pin_5);

// ���������� ����������� ������ ������ ��� ����� �� ����� A
#define U_MLT_Data_Dir_Input_PA  MDR_PORTA->OE &= 0xFF00;
// ���������� ����������� �������� ������ ��� ����� �� ����� A
#define U_MLT_Data_Dir_Output_PA MDR_PORTA->OE |= 0x00FF;


// ������������ ������ 
#define U_MLT_Output_Data		(uint8_t)MDR_PORTA->RXTX;

// ������������� ���
void U_MLT_Init (void);

// ������������� ������� �� ��� ������ � ���
void U_MLT_Pin_Cfg (void);
// ������������� �������� ���
void U_MLT_LCD_Init(void);

// ��������� ������ �� ���� ������
void U_MLT_Set_Data_Bits (uint8_t value);
// ��������
void U_MLT_Delay (uint32_t value);
// �������� ������ ��������
uint8_t U_MLT_Read_Status (uint8_t Chip);

// �������� � ��������� �������
void U_MLT_Disp_On (uint8_t Chip);
void U_MLT_Disp_Off (uint8_t Chip);

// ������ ������� ��������
void U_MLT_Set_Page (uint8_t Chip, uint8_t page);
// ������ ������� �����
void U_MLT_Set_Address (uint8_t Chip, uint8_t address);
// �������� ������ � ���
void U_MLT_Write_Data (uint8_t Chip, uint8_t data);
// ��������� ������ � ���
uint8_t U_MLT_Read_Data (uint8_t Chip);

// �������� ��������
void U_MLT_Clear_Page (uint8_t Chip, uint8_t Page);
// �������� �������
void U_MLT_Clear_Chip (uint8_t Chip);
// ������� ������
void U_MLT_Put_Char (uint8_t symbol, int32_t X, int32_t Y);
// ������� ������
void U_MLT_Put_String (const char* str, int32_t Y);
// ���������� ������ �� cnt ����� � ������� ��
void U_MLT_Scroll_String (const char* str, int32_t Y, int32_t cnt);
// ������� �����������
void U_MLT_Put_Image (const uint8_t* image, int32_t top, int32_t left, int32_t bottom, int32_t right);

#endif 
