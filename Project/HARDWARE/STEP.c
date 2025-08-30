#include "STEP.h"               
#include "Systick.h"
#include "gpio.h"
void STEP_Run(uint16_t dir, uint16_t num, uint16_t speed)
{
	if(dir == 1)                //左转
	{
		DIR1=0;DIR2=0;DIR3=0;DIR4=0;
		for(uint32_t i=0;i<=(num*800/360);i++)//细分为1600/圈，电平翻转两次为一个脉冲，一圈需要3200
	{
		delay_us(speed);//高电平期间持续时间，脉冲频率
		//GPIOA->ODR^=GPIO_Pin_3;//翻转PA3的电平
		PUL1=~PUL1;
		PUL2=~PUL2;
		PUL3=~PUL3;
		PUL4=~PUL4;
	}
	}
	if(dir == 2)                //右转
	{
		DIR1=1;DIR2=1;DIR3=1;DIR4=1;
		for(uint32_t i=0;i<=(num*800/360);i++)//细分为1600/圈，电平翻转两次为一个脉冲，一圈需要3200
	{
		delay_us(speed);//高电平期间持续时间，脉冲频率
		//GPIOA->ODR^=GPIO_Pin_3;//翻转PA3的电平
		PUL1=~PUL1;
		PUL2=~PUL2;
		PUL3=~PUL3;
		PUL4=~PUL4;
	}
	}
	if(dir == 3)               //轮子开
	{
		DIR1=0;DIR2=0;DIR3=1;DIR4=1;
		for(uint32_t i=0;i<=(num*800/360);i++)//细分为1600/圈，电平翻转两次为一个脉冲，一圈需要3200
	{
		delay_us(speed);//高电平期间持续时间，脉冲频率
		//GPIOA->ODR^=GPIO_Pin_3;//翻转PA3的电平
		PUL1=~PUL1;
		PUL2=~PUL2;
		PUL3=~PUL3;
		PUL4=~PUL4;
	}
	}
	if(dir == 4)               //轮子收
	{
		DIR1=0;DIR2=0;DIR3=1;DIR4=1;
		for(uint32_t i=0;i<=(num*800/360);i++)//细分为1600/圈，电平翻转两次为一个脉冲，一圈需要3200
	{
		delay_us(speed);//高电平期间持续时间，脉冲频率
		//GPIOA->ODR^=GPIO_Pin_3;//翻转PA3的电平
		PUL1=~PUL1;
		PUL2=~PUL2;
		PUL3=~PUL3;
		PUL4=~PUL4;
	}
	}
	
}
