#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define USART1_RX_SIZE 5000
#define USART2_RX_SIZE 5000
#define USART3_RX_SIZE 5000
#define UART4_RX_SIZE 5000

void USART_Config(void);
void USART_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void USART_SendArray( USART_TypeDef * pUSARTx, uint8_t *array, uint16_t num);
void USART_SendBits(USART_TypeDef * pUSARTx,char *Str,unsigned char Len);
void InvertUint16(unsigned short *DesBuf, unsigned short *SrcBuf);
void InvertUint8(unsigned char *DesBuf, unsigned char *SrcBuf);
unsigned short CRC16_MODBUS(unsigned char *puchMsg, unsigned int usDataLen);
void USART_SendArray16(USART_TypeDef *pUSARTx, uint16_t *array, uint16_t num);
void USART_SendMixedData(USART_TypeDef* USARTx, uint8_t* data8, uint16_t data8_len, uint16_t* data16, uint16_t data16_len);
#endif



