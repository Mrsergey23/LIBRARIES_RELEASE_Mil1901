
#include "rst.h"


//������������� ������������ ��� ������
void frq_init(void)
{
	MDR_RST_CLK->HS_CONTROL = 0x1; // Enable HSE oscillator
/* wait while HSE startup */
	while (MDR_RST_CLK->CLOCK_STATUS == 0x00) __NOP();
	MDR_RST_CLK->CPU_CLOCK = 0x102; // switch to HSE (8 MHz)
	SystemCoreClockUpdate();
}




// ������������� ������� ������������ ��
void U_RST_Init(void)
{
  // �������� ������������ ����������� �����
  RST_CLK_PCLKcmd (RST_CLK_PCLK_BKP, ENABLE);

  // �������� ��������� �� ������� ������
  RST_CLK_HSEconfig (RST_CLK_HSE_ON); 
  while (RST_CLK_HSEstatus () != SUCCESS);

  // ��������� �������� � ����������� ��������� PLL (CPU_C1_SEL = HSE / 1 * 10 =  8��� / 1 * 10 = 80���)
  RST_CLK_CPU_PLLconfig (RST_CLK_CPU_PLLsrcHSEdiv1, RST_CLK_CPU_PLLmul10); 
 
  // �������� PLL, �� ��� �� ���������� � ���������
  RST_CLK_CPU_PLLcmd (ENABLE); 
  while (RST_CLK_CPU_PLLstatus () != SUCCESS);

  // �������� �3 ( CPU_C3_SEL = CPU_C2_SEL )
  RST_CLK_CPUclkPrescaler (RST_CLK_CPUclkDIV1); 
  
  // �� �2 ���� � PLL, � �� �������� � �1 (CPU_C2_SEL = PLL)
  RST_CLK_CPU_PLLuse (ENABLE); 
  
  // CPU ����� ������������ � ������ �3 (HCLK_SEL = CPU_C3_SEL = 80���)
  RST_CLK_CPUclkSelection (RST_CLK_CPUclkCPU_C3); 

}
