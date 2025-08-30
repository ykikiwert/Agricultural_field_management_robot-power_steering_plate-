#include "DAC8568.h"
#include "Systick.h"
#include "stm32f10x.h"                  // Device header

/* 	芯片手册显示存在：±1mV~±4mV的零码误差，模块本身4倍放大，误差为：±4mV~±16mV
		零码误差测量，使每个通道的ZeroCode = 0，模块通道A输出0V，如果测量为-5mV，即将ZeroCode[0]幅值为-5 */
int16_t ZeroCode[8] = {0, 0, 0, 0,0, 0, 0, 0};


/**
 * @brief       dac8568引脚初始化
 * @param       无
 * @retval      无
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
	dac8568_write_data(0x07000000);	/* 复位 */
	delay_ms(100);
	dac8568_write_data(0x040000FF);	/* 通道全部上电 */
	dac8568_write_data(0x090A0000);	/* 使用内部参考 */
}

/**
 * @brief       dac8568写数据
 * @param       无
 * @retval      无
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
4-bit 前缀位: DB31 ~ DB28 (最高位必须置零，余下Don’t care)
4-bit控制位	: DB27 ~ DB24 (控制DAC模式)
4-bit 地址位：DB23~ DB20 (选择DAC通道)
16-bit数据位: DB19 ~ DB4 (送入DAC DATA Buffer)
4-bit特征位	: DB3 ~ DB0
*/
/**
 * @brief       dac8568通道数据更新
 * @param       ch：通道   data：通道的数字量
 * @retval      无
 */
void dac8568_write_channel(uint8_t ch, uint16_t data)
{
	uint32_t txdata = 0x03000000;
	txdata |= (uint32_t)(ch&0x0F)<<20;
	txdata |= (uint32_t)data<<4;
	
	dac8568_write_data(txdata);
}

/**
 * @brief       dac8568通道数据更新
 * @param       data：通道的数字量
 * @retval      无
 */
void dac8568_write_all_channel(uint16_t data)
{
	uint32_t txdata = 0x03F00000;
	
	txdata |= (uint32_t)data<<4;
	
	dac8568_write_data(txdata);
}
