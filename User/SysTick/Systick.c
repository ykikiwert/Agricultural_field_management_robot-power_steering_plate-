#include "Systick.h"

void delay_us(uint32_t us)
{
	uint32_t i;
	SysTick_Config(72);
	
	for(i=0; i<us ;i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );
	}
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

void delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(72000);
	
	for(i=0; i<ms ;i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );
	}
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
//自己临时添加的  不精确的延时
void SOFT_Delay(__IO u32 nCount)
{
	for(; nCount != 0; nCount--);
} 
