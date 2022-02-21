// ***********************************************************************************
// ���������������: 1986��92�
// ����������: ���������� ����� �1986��92QI
// ����: mlt_lcd.h 
// ����������:  ������ � ��� MT�12864J 
//              ��� ����������� �������� "��������" �145��10 (������ Samsung KS0108)
// ����������:  Armcc 5.03.0.76 �� ��������� Keil uVision 4.72.1.0 
// ***********************************************************************************

#include "mlt_lcd.h"
#include "MDR32F9Qx_rst_clk.h"
#include "MDR32F9Qx_port.h"
// ������, ��������� �� ��������� ��� �������������
static const char* init_string = "   \xC7\xC0\xCE\"\xCC\xE8\xEB\xE0\xED\xE4\xF0\"";  // ��� "�������"

// �����������, ��������� �� ��������� ��� ������������� (������� "��������")
static const uint8_t init_image[32] = 
{
	254, 254, 254, 254, 254, 126,  30,   6,
		6,  30, 126, 254, 254, 254, 254, 254,
	127,  95,  71,  65, 124, 120, 112,  96,
	 96, 112, 120, 124,  65,  71,  95, 127
};


// ������������� ���
void U_MLT_Init (void)
{
  // ��������� ������������ ��������� ������
  RST_CLK_PCLKcmd (RST_CLK_PCLK_PORTA | RST_CLK_PCLK_PORTE | RST_CLK_PCLK_PORTC, ENABLE);	
	
	// ���������������� ������ �� ��� ������ � ���
	U_MLT_Pin_Cfg ();
	
	// ���������������� ������� ��� 
	U_MLT_LCD_Init();
	
	// ��������� ���������� �������� � �������� 1
	while (U_MLT_Read_Status(1) & 0x80);
	// �������� ������� 1  
	U_MLT_Disp_On (1);
	
	// �������� ���������� �������� � �������� 2
	while (U_MLT_Read_Status(2) & 0x80);
	// �������� ������� 2 
	U_MLT_Disp_On (2);

	// �������� ������� 1 
	U_MLT_Clear_Chip (1);
	// �������� ������� 2
	U_MLT_Clear_Chip (2);	
	
	// ������� ��������� ��������� � �������
  U_MLT_Put_String (init_string, 1);	
	U_MLT_Put_Image (init_image, 0, 0, 1, 1);

}


// ������������� ������� �� ��� ������ � ���
void U_MLT_Pin_Cfg (void)
{
	// ��������� ������ ��� ������������� ������
	PORT_InitTypeDef PortInit;
	
		//---------   IN Pins -----------
	/* Fill PortInit structure*/
	PortInit.PORT_PULL_UP 			= PORT_PULL_UP_OFF;
	PortInit.PORT_PULL_DOWN 		= PORT_PULL_DOWN_OFF;
	PortInit.PORT_PD_SHM 				= PORT_PD_SHM_OFF;
	PortInit.PORT_PD 						= PORT_PD_DRIVER;
	PortInit.PORT_GFEN 					= PORT_GFEN_OFF;
	
	PortInit.PORT_FUNC  				= PORT_FUNC_PORT;
	PortInit.PORT_MODE  				= PORT_MODE_DIGITAL;
	PortInit.PORT_SPEED 				= PORT_SPEED_SLOW;
	/* Configure PORTA pins 0..7 for mlt inout data  */
	PortInit.PORT_OE    				= PORT_OE_IN;
		PortInit.PORT_Pin   			= (PORT_Pin_0| PORT_Pin_1 | \
												PORT_Pin_2 | PORT_Pin_3 | \
												PORT_Pin_4 | PORT_Pin_5 | \
												PORT_Pin_6 |PORT_Pin_7);
 	PORT_Init(MDR_PORTA, &PortInit);
	
	//---------   OUT Pins -----------
	PortInit.PORT_OE = PORT_OE_OUT;
	
	PortInit.PORT_Pin = (PORT_Pin_4 |PORT_Pin_5 | PORT_Pin_11 );
	PORT_Init(MDR_PORTE, &PortInit);
	
	PortInit.PORT_Pin = (PORT_Pin_9);
	PORT_Init(MDR_PORTD, &PortInit);
	
	PortInit.PORT_Pin = (PORT_Pin_2| PORT_Pin_7 );
	PORT_Init(MDR_PORTC, &PortInit);
}


// ������������� �������� ���
void U_MLT_LCD_Init(void)
{
	uint8_t s1,s2;
	// ������������ ������ RESET
	U_MLT_Clr_Res_Pin;
	U_MLT_Delay(200);
	
	U_MLT_Set_Res_Pin;
	U_MLT_Delay(5);

	// ��������� ��������� �������������
	do
	{
		s1 = U_MLT_Read_Status(1) & 0x90;
		s2 = U_MLT_Read_Status(2) & 0x90;
	}
	while (s1 != 0x00 && s2 != 0x00);
}

// ��������� ������ �� ���� ������
void U_MLT_Set_Data_Bits (uint8_t value)
{
	MDR_PORTA->RXTX &= 0xFF00;
	MDR_PORTA->RXTX |= value; 
}

// �������� 
void U_MLT_Delay (uint32_t value)
{
	volatile uint32_t x = value;
	
	while ((x--) != 0);
}

// �������� ������ ��������
uint8_t U_MLT_Read_Status (uint8_t Chip)
{
  uint8_t data;

	// ��������� ���� ������ �� ����� ������
	U_MLT_Data_Dir_Input_PA;
	
	
	// ���� ������ ������� 1, �� ���������� ����� �1 (������� 1 ������)
	if (Chip == 1) 
	{
    U_MLT_Set_E1_Pin;
  }
	// ���� ������ ������� 2, �� ���������� ����� �2 (������� 2 ������)
	else 
  {
    U_MLT_Set_E2_Pin;
  }

	// �������� ����� �0
	U_MLT_Clr_A0_Pin;

	// ���������� ����� RW (����� ������)
  U_MLT_Set_RW_Pin;
	U_MLT_Delay(5);
	
	// ���������� ����� E
	U_MLT_Set_Stb_Pin;
	U_MLT_Delay(5);
	
	// ��������� ������
	data = U_MLT_Output_Data;
	U_MLT_Delay(5);
	
	// �������� ����� E
	U_MLT_Clr_Stb_Pin;
	U_MLT_Delay(5);
	
	// �������� ����� A0
	U_MLT_Clr_A0_Pin;

	// �������� ����� RW
	U_MLT_Clr_RW_Pin;

	// ���� ������ ������� 1, �� �������� ����� �1 (������� 1 �� ������)
	if (Chip == 1) 
	{
    U_MLT_Clr_E1_Pin;
  }
	// ���� ������ ������� 2, �� �������� ����� �2 (������� 1 �� ������)
	else 
  {
    U_MLT_Clr_E2_Pin;
  }

	return data;
}

// �������� �������
void U_MLT_Disp_On (uint8_t Chip)
{
	// ���� ������ ������� 1, �� ���������� ����� �1 (������� 1 ������)
	if (Chip == 1) 
	{
    U_MLT_Set_E1_Pin;
  }
	// ���� ������ ������� 2, �� ���������� ����� �2 (������� 2 ������)
	else 
  {
    U_MLT_Set_E2_Pin;
  }

	// �������� ����� �0
	U_MLT_Clr_A0_Pin;

	// �������� ����� RW (�������� ������)
	U_MLT_Clr_RW_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Data_Dir_Output_PA;
	
	
	// ������ ������ �� ����
	U_MLT_Set_Data_Bits (0x3F);
	U_MLT_Delay(5);

	U_MLT_Set_Stb_Pin;
	U_MLT_Delay(5);

	U_MLT_Clr_Stb_Pin;
	U_MLT_Delay(5);

  U_MLT_Clr_A0_Pin;

	U_MLT_Clr_RW_Pin;


	U_MLT_Data_Dir_Input_PA;
	 

	// ���� ������ ������� 1, �� �������� ����� �1 (������� 1 �� ������)
	if (Chip == 1) 
	{
    U_MLT_Clr_E1_Pin;
  }
	// ���� ������ ������� 2, �� �������� ����� �2 (������� 1 �� ������)
	else 
  {
    U_MLT_Clr_E2_Pin;
  }
}

// �������� � ��������� �������
void U_MLT_Disp_Off (uint8_t Chip)
{
	// ���� ������ ������� 1, �� ���������� ����� �1 (������� 1 ������)
	if (Chip == 1) 
	{
    U_MLT_Set_E1_Pin;
  }
	// ���� ������ ������� 2, �� ���������� ����� �2 (������� 2 ������)
	else 
  {
    U_MLT_Set_E2_Pin;
  }

	U_MLT_Clr_A0_Pin;

	U_MLT_Clr_RW_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Data_Dir_Output_PA;
	 
	
	U_MLT_Set_Data_Bits (0x3E);
	U_MLT_Delay(5);
	
	U_MLT_Set_Stb_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Clr_Stb_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Clr_A0_Pin;

	U_MLT_Clr_RW_Pin;

	U_MLT_Data_Dir_Input_PA;

	
	// ���� ������ ������� 1, �� �������� ����� �1 (������� 1 �� ������)
	if (Chip == 1) 
	{
    U_MLT_Clr_E1_Pin;
  }
	// ���� ������ ������� 2, �� �������� ����� �2 (������� 1 �� ������)
	else 
  {
    U_MLT_Clr_E2_Pin;
  }
}

// ������ ������� ��������
void U_MLT_Set_Page (uint8_t Chip, uint8_t page)
{
	// ���� ������ ������� 1, �� ���������� ����� �1 (������� 1 ������)
	if (Chip == 1) 
	{
    U_MLT_Set_E1_Pin;
  }
	// ���� ������ ������� 2, �� ���������� ����� �2 (������� 2 ������)
	else 
  {
    U_MLT_Set_E2_Pin;
  }

	U_MLT_Clr_A0_Pin;

	U_MLT_Clr_RW_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Data_Dir_Output_PA;
	 
	
	U_MLT_Set_Data_Bits (0xB8 | page);
	U_MLT_Delay(5);
	
	U_MLT_Set_Stb_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Clr_Stb_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Data_Dir_Input_PA;

	U_MLT_Clr_A0_Pin;

	U_MLT_Clr_RW_Pin;

	// ���� ������ ������� 1, �� �������� ����� �1 (������� 1 �� ������)
	if (Chip == 1) 
	{
    U_MLT_Clr_E1_Pin;
  }
	// ���� ������ ������� 2, �� �������� ����� �2 (������� 1 �� ������)
	else 
  {
    U_MLT_Clr_E2_Pin;
  }
}

// ������ ������� �����
void U_MLT_Set_Address (uint8_t Chip, uint8_t address)
{
	// ���� ������ ������� 1, �� ���������� ����� �1 (������� 1 ������)
	if (Chip == 1) 
	{
    U_MLT_Set_E1_Pin;
  }
	// ���� ������ ������� 2, �� ���������� ����� �2 (������� 2 ������)
	else 
  {
    U_MLT_Set_E2_Pin;
  }

	U_MLT_Clr_A0_Pin;

	U_MLT_Clr_RW_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Data_Dir_Output_PA;
	 
	
	U_MLT_Set_Data_Bits (0x40 | address);
	U_MLT_Delay(5);
	
	U_MLT_Set_Stb_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Clr_Stb_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Data_Dir_Input_PA;
	 

	U_MLT_Clr_A0_Pin;

	U_MLT_Clr_RW_Pin;

	// ���� ������ ������� 1, �� �������� ����� �1 (������� 1 �� ������)
	if (Chip == 1) 
	{
    U_MLT_Clr_E1_Pin;
  }
	// ���� ������ ������� 2, �� �������� ����� �2 (������� 1 �� ������)
	else 
  {
    U_MLT_Clr_E2_Pin;
  }
}

// �������� ������ � ���
void U_MLT_Write_Data (uint8_t Chip, uint8_t data)
{
	// ���� ������ ������� 1, �� ���������� ����� �1 (������� 1 ������)
	if (Chip == 1) 
	{
    U_MLT_Set_E1_Pin;
  }
	// ���� ������ ������� 2, �� ���������� ����� �2 (������� 2 ������)
	else 
  {
    U_MLT_Set_E2_Pin;
  }

	U_MLT_Set_A0_Pin;

	U_MLT_Clr_RW_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Data_Dir_Output_PA;
	 
	
	U_MLT_Set_Data_Bits (data);
	U_MLT_Delay(5);
	
	U_MLT_Set_Stb_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Clr_Stb_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Data_Dir_Input_PA;
	 

	U_MLT_Clr_A0_Pin;

	U_MLT_Clr_RW_Pin;

	// ���� ������ ������� 1, �� �������� ����� �1 (������� 1 �� ������)
	if (Chip == 1) 
	{
    U_MLT_Clr_E1_Pin;
  }
	// ���� ������ ������� 2, �� �������� ����� �2 (������� 1 �� ������)
	else 
  {
    U_MLT_Clr_E2_Pin;
  }
}

// ��������� ������ � ���
uint8_t U_MLT_Read_Data (uint8_t Chip)
{
  uint8_t data = 0;

	// ���� ������ ������� 1, �� ���������� ����� �1 (������� 1 ������)
	if (Chip == 1) 
	{
    U_MLT_Set_E1_Pin;
  }
	// ���� ������ ������� 2, �� ���������� ����� �2 (������� 2 ������)
	else 
  {
    U_MLT_Set_E2_Pin;
  }

	U_MLT_Set_A0_Pin;

	U_MLT_Set_RW_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Data_Dir_Input_PA;
	 
	
	U_MLT_Set_Data_Bits (data);
	U_MLT_Delay(5);
	
	U_MLT_Set_Stb_Pin;
	U_MLT_Delay(5);
	
	data = U_MLT_Output_Data;
	U_MLT_Delay(5);
	
	U_MLT_Clr_Stb_Pin;
	U_MLT_Delay(5);
	
	U_MLT_Clr_A0_Pin;

	U_MLT_Clr_RW_Pin;

	// ���� ������ ������� 1, �� �������� ����� �1 (������� 1 �� ������)
	if (Chip == 1) 
	{
    U_MLT_Clr_E1_Pin;
  }
	// ���� ������ ������� 2, �� �������� ����� �2 (������� 1 �� ������)
	else 
  {
    U_MLT_Clr_E2_Pin;
  }

	return (data);
}

// �������� ��������
void U_MLT_Clear_Page (uint8_t Chip, uint8_t Page)
{
  int32_t i;

	U_MLT_Set_Page (Chip, Page);

	U_MLT_Set_Address (Chip, 0x00);

	for (i = 0; i < 64; i++)
	{	
		while (U_MLT_Read_Status (Chip) & 0x80);
		
		U_MLT_Write_Data (Chip, 0x00);
	}
}

// �������� �������
void U_MLT_Clear_Chip (uint8_t Chip)
{
  int32_t i;

	for (i = 0; i < 8; i++)
		U_MLT_Clear_Page (Chip, i);
}

// ������� ������
void U_MLT_Put_Char (uint8_t symbol, int32_t X, int32_t Y)
{
  int32_t chp, page, adr;
  int32_t i;
	int32_t symbol_image_index;  // ������ �������� � ������� ������, � �������� ���������� ����������� ������� �������.

	chp  = (int32_t)(X / 8) + 1;
	page = Y;
	adr  = (int32_t)((X % 8) * 8);	

	U_MLT_Set_Page (chp, page);
	U_MLT_Set_Address (chp, adr);
	
	// ���������, ����� ������ �� ������� �� ��������, ������������ � ������.
	if (symbol >= MLT_FONT_MIN_CODE && symbol <= MLT_FONT_MAX_CODE)
	{
	  symbol_image_index = (((uint32_t) symbol) - MLT_FONT_MIN_CODE) * 8;
	}
	// ������ ��� ���������
	else
	{
	  symbol_image_index = 0;  // ������� ����� ������ ������, ��� �������,- ������.
  }
	
	for (i = symbol_image_index; i < symbol_image_index + 8; i++)
	{	
		while (U_MLT_Read_Status (chp) & 0x80);
		
		U_MLT_Write_Data (chp, MLT_Font[i]);
	}

}

// ������� ������
void U_MLT_Put_String (const char* str, int32_t Y)
{
  int32_t i;

	for (i = 0; i < U_MLT_SCREEN_WIDTH_SYMBOLS; i++)
	{
	  // ��������� ����� ������
		if (!str[i])
      break;

    U_MLT_Put_Char (str[i], i, Y); // ������� ������
  }
	
	for (; i < U_MLT_SCREEN_WIDTH_SYMBOLS; i++)
	{
 	  U_MLT_Put_Char (32, i, Y);  // ������� ������
  }
}

// ���������� ������ �� cnt ����� � ������� ��
void U_MLT_Scroll_String (const char* str, int32_t Y, int32_t cnt)
{
  int32_t i, j, L;
	char c;
	char s[U_MLT_SCREEN_WIDTH_SYMBOLS + 1]; // ������ �������� � ���, ������� ������� � ���������� ���������.
  
	L = strlen(str); // ����� �������� ������
	s[U_MLT_SCREEN_WIDTH_SYMBOLS] = 0;      // ���������� ������ ���� ������� �������� �����
	
	// ���� �������� ������ ������ 
	if (!L)
		return; 

  // ���� �������� ��������� ��� ������ ������ ����� :-)	
	cnt %= U_MLT_SCREEN_WIDTH_SYMBOLS;

	// ���� �������� ������ ������ ������
	if (L < U_MLT_SCREEN_WIDTH_SYMBOLS)
		for (i = 0; i < U_MLT_SCREEN_WIDTH_SYMBOLS; i++)
		{
			j = i + cnt;

			if (j >= U_MLT_SCREEN_WIDTH_SYMBOLS)
				j %= U_MLT_SCREEN_WIDTH_SYMBOLS;
			
			// ���� �������� ������ ��� �� ���������
			if (j < L)  			
				c = str[j];
			// ���� �������� ������ ��� ���������
			else
				c = 32; // ������
			
			s[i] = c;
		}
	// ���� �������� ������ ������� ������
	else
		for (i = 0; i < U_MLT_SCREEN_WIDTH_SYMBOLS; i++)
		{
			j = i + cnt;

			if (j >= L)
				j %= L;
			
      s[i] = str[j];
		}
	
	// ������� ������������ ������ �� ���	
	U_MLT_Put_String (s, Y);
}


// ������� �����������
void U_MLT_Put_Image (const uint8_t* image, int32_t top, int32_t left, int32_t bottom, int32_t right)
{
	int32_t i, j, y;
	int32_t chp, page, adr;
	int32_t cnt = 0;	

	for	(i = top; i <= bottom; i++)
		for (j = left; j <= right; j++)
		{
			chp  = (int32_t)(j / 8) + 1;
			page = i;
			adr  = (int32_t)((j % 8) * 8);

			U_MLT_Set_Page (chp, page);
			U_MLT_Set_Address (chp, adr);
			
			for (y = 0; y < 8; y++)
			{
  		  while (U_MLT_Read_Status (chp) & 0x80);

				U_MLT_Write_Data (chp, image[cnt + y]);
			}
			cnt += 8;
		}	
	
}


