#include "DAC8568.h"
#include "Systick.h"
#include "stm32f10x.h"                  // Device header

/* 	оƬ�ֲ���ʾ���ڣ���1mV~��4mV��������ģ�鱾��4���Ŵ����Ϊ����4mV~��16mV
		������������ʹÿ��ͨ����ZeroCode = 0��ģ��ͨ��A���0V���������Ϊ-5mV������ZeroCode[0]��ֵΪ-5 */
int16_t ZeroCode[8] = {0, 0, 0, 0,0, 0, 0, 0};


/**
 * @brief       dac8568���ų�ʼ��
 * @param       ��
 * @retval      ��
 */
void dac8568_init(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(SPI_RCC, ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = SPI_CS_PIN | SPI_CLK_PIN | SPI_MOSI_PIN;
	GPIO_InitStruct.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(SPI_GPIOx, &GPIO_InitStruct);		
		
	GPIO_SetBits(SPI_GPIOx,SPI_CS_PIN);
	GPIO_ResetBits(SPI_GPIOx , SPI_CLK_PIN);

	delay_ms(100);
	dac8568_write_data(0x07000000);	/* ��λ */
	delay_ms(100);
	dac8568_write_data(0x040000FF);	/* ͨ��ȫ���ϵ� */
	dac8568_write_data(0x090A0000);	/* ʹ���ڲ��ο� */
}

/**
 * @brief       dac8568д����
 * @param       ��
 * @retval      ��
 */
void dac8568_write_data(uint32_t data)
{
	uint8_t i;
	uint32_t send_data = data;
	
	dac8568_sync_l;
	for(i=0;i<32;i++)
	{
		dac8568_sclk_h;
		if(send_data&0x80000000)
			dac8568_din_h;
		else
			dac8568_din_l;
		dac8568_sclk_l;
		send_data<<=1;
	}
	dac8568_sync_h;
}


/**
4-bit ǰ׺λ: DB31 ~ DB28 (���λ�������㣬����Don��t care)
4-bit����λ	: DB27 ~ DB24 (����DACģʽ)
4-bit ��ַλ��DB23~ DB20 (ѡ��DACͨ��)
16-bit����λ: DB19 ~ DB4 (����DAC DATA Buffer)
4-bit����λ	: DB3 ~ DB0
*/
/**
 * @brief       dac8568ͨ�����ݸ���
 * @param       ch��ͨ��   data��ͨ����������
 * @retval      ��
 */
void dac8568_write_channel(uint8_t ch, uint16_t data)
{
	uint32_t txdata = 0x03000000;
	txdata |= (uint32_t)(ch&0x0F)<<20;
	txdata |= (uint32_t)data<<4;
	
	dac8568_write_data(txdata);
}

/**
 * @brief       dac8568ͨ�����ݸ���
 * @param       data��ͨ����������
 * @retval      ��
 */
void dac8568_write_all_channel(uint16_t data)
{
	uint32_t txdata = 0x03F00000;
	
	txdata |= (uint32_t)data<<4;
	
	dac8568_write_data(txdata);
}
