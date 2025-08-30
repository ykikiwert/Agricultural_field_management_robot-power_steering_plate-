#ifndef __INCLUDES_H
#define __INCLUDES_H

#include "stm32f10x.h"
#include "gpio.h"
#include "usart.h"
#include "Systick.h"
#include <stdbool.h>

extern uint8_t USART1_RX_BUF[USART1_RX_SIZE];
extern uint8_t USART2_RX_BUF[USART2_RX_SIZE];
extern uint8_t USART3_RX_BUF[USART3_RX_SIZE];
extern uint8_t UART4_RX_BUF[UART4_RX_SIZE];

#endif



