// ***********************************************************************************
// Микроконтроллер: 1986ВЕ92У
// Устройство: Отладочная плата К1986ВЕ92QI
// Файл: led.h 
// Назначение: Управление светодиодами      
// Компилятор:  Armcc 5.03.0.76 из комплекта Keil uVision 4.72.1.0 
// ***********************************************************************************

#ifndef __U_LED
 #define __U_LED

//#include "common.h"
#include "MDR32F9Qx_port.h"
#include "MDR32F9Qx_rst_clk.h"

// Порт светодиодов
#define U_LED_PORT MDR_PORTB
#define U_LED_11 PORT_Pin_11
#define U_LED_12 PORT_Pin_12
#define U_LED_13 PORT_Pin_13
#define U_LED_14 PORT_Pin_14
#define U_LED_15 PORT_Pin_15
// Инициализировать светодиоды
void U_LED_Init (void);

// Потушить указанные светодиоды
void U_LED_Off (uint32_t Pins);

// Зажечь указанные светодиоды
void U_LED_On (uint32_t Pins);

// Переключить указанные светодиоды
void U_LED_Toggle (uint32_t Pins);

// Задача по миганию синим светодиодом 
void U_LED_Task_Function (void);

#endif 

