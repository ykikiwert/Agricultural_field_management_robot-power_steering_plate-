#include "usart.h"
#include "gpio.h"

int i;
uint8_t USART1_RX_BUF[USART1_RX_SIZE];
uint8_t USART3_RX_BUF[USART3_RX_SIZE];
uint8_t UART4_RX_BUF[UART4_RX_SIZE];

static void USART1_Config(uint32_t bound)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
  
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	
	NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(USART1, USART_IT_TC, DISABLE);
	USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
	USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);
	USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);
	USART_Cmd(USART1, ENABLE);
	
	DMA_DeInit(DMA1_Channel5);
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t) &USART1->DR;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART1_RX_BUF;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = USART1_RX_SIZE;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel5,&DMA_InitStructure);
	DMA_Cmd(DMA1_Channel5,ENABLE);

}


static void USART3_Config(uint32_t bound)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART3, &USART_InitStructure);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	
	NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(USART3, USART_IT_TC, DISABLE);
	USART_ITConfig(USART3, USART_IT_RXNE, DISABLE);
	USART_ITConfig(USART3, USART_IT_IDLE, ENABLE);
	USART_DMACmd(USART3, USART_DMAReq_Rx, ENABLE);
	USART_Cmd(USART3, ENABLE);
	
	DMA_DeInit(DMA1_Channel3);
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t) &USART3->DR;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART3_RX_BUF;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = USART3_RX_SIZE;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel3,&DMA_InitStructure);
	DMA_Cmd(DMA1_Channel3,ENABLE);

}


void USART_Config(void)
{
	USART1_Config(9600);
	USART3_Config(115200);
}


//发送1bit数据
void USART_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
	USART_SendData(pUSARTx,ch);
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	
}
//发送8bit数组
void USART_SendArray( USART_TypeDef * pUSARTx, uint8_t *array, uint16_t num)
{
  uint8_t i;
	for(i=0; i<num; i++)
  {
	    USART_SendByte(pUSARTx,array[i]);	
  }
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);
}
// 发送16位数组的函数  
void USART_SendArray16(USART_TypeDef *pUSARTx, uint16_t *array, uint16_t num)  
{  
    uint16_t i;  
    for(i = 0; i < num; i++)  
    {  
        // 先发送高位字节  
        USART_SendByte(pUSARTx, (uint8_t)(array[i] >> 8));  
        // 再发送低位字节  
        USART_SendByte(pUSARTx, (uint8_t)(array[i] & 0xFF));  
    }  
    while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);  
}

void USART_SendMixedData(USART_TypeDef* USARTx, uint8_t* data8, uint16_t data8_len, uint16_t* data16, uint16_t data16_len) {  
    // 先发送uint8_t数组  
    for (uint16_t i = 0; i < data8_len; i++) {  
        USART_SendByte(USARTx, data8[i]);  
    }  
      
    // 然后发送uint16_t数组，注意字节顺序（这里假设使用小端序）  
    for (uint16_t i = 0; i < data16_len; i++) { 
        USART_SendByte(USARTx, (uint8_t)((data16[i] >> 8) & 0xFF)); // 发送高字节		
        USART_SendByte(USARTx, (uint8_t)(data16[i] & 0xFF));       // 发送低字节  
          
    }  
}  
void USART_SendBits(USART_TypeDef * pUSARTx,char *Str,unsigned char Len)
{
    while(Len--)
    {
        USART_SendByte(pUSARTx,*Str++);
    }
}

//16位校验算法
void InvertUint16(unsigned short *DesBuf, unsigned short *SrcBuf)  
{  
	int i;  
	unsigned short temp = 0;    
	
	for(i = 0; i < 16; i++)  
	{  
			if(SrcBuf[0] & (1 << i))
			{          
					temp |= 1<<(15 - i);  
			}
	}  
	DesBuf[0] = temp;  
}

void InvertUint8(unsigned char *DesBuf, unsigned char *SrcBuf)
{
	int i;
	unsigned char temp = 0;
	
	for(i = 0; i < 8; i++)
	{
			if(SrcBuf[0] & (1 << i))
			{
					temp |= 1<<(7-i);
			}
	}
	DesBuf[0] = temp;
}

unsigned short CRC16_MODBUS(unsigned char *puchMsg, unsigned int usDataLen)  
{  
     unsigned short wCRCin = 0xFFFF;  
     unsigned short wCPoly = 0x8005;  
     unsigned char wChar = 0;  
     
     while (usDataLen--)     
     {  
         wChar = *(puchMsg++);  
         InvertUint8(&wChar, &wChar);  
         wCRCin ^= (wChar << 8); 
         
         for( i = 0; i < 8; i++)  
         {  
             if(wCRCin & 0x8000) 
             {
                 wCRCin = (wCRCin << 1) ^ wCPoly;  
             }
             else  
             {
                 wCRCin = wCRCin << 1; 
             }            
         }  
     }  
     InvertUint16(&wCRCin, &wCRCin);  
     return (wCRCin) ;  
}



