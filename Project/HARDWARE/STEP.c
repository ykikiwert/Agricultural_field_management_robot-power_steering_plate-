#include "STEP.h"               
#include "Systick.h"
#include "gpio.h"
void STEP_Run(uint16_t dir, uint16_t num, uint16_t speed)
{
	if(dir == 1)                //��ת
	{
		DIR1=0;DIR2=0;DIR3=0;DIR4=0;
		for(uint32_t i=0;i<=(num*800/360);i++)//ϸ��Ϊ1600/Ȧ����ƽ��ת����Ϊһ�����壬һȦ��Ҫ3200
	{
		delay_us(speed);//�ߵ�ƽ�ڼ����ʱ�䣬����Ƶ��
		//GPIOA->ODR^=GPIO_Pin_3;//��תPA3�ĵ�ƽ
		PUL1=~PUL1;
		PUL2=~PUL2;
		PUL3=~PUL3;
		PUL4=~PUL4;
	}
	}
	if(dir == 2)                //��ת
	{
		DIR1=1;DIR2=1;DIR3=1;DIR4=1;
		for(uint32_t i=0;i<=(num*800/360);i++)//ϸ��Ϊ1600/Ȧ����ƽ��ת����Ϊһ�����壬һȦ��Ҫ3200
	{
		delay_us(speed);//�ߵ�ƽ�ڼ����ʱ�䣬����Ƶ��
		//GPIOA->ODR^=GPIO_Pin_3;//��תPA3�ĵ�ƽ
		PUL1=~PUL1;
		PUL2=~PUL2;
		PUL3=~PUL3;
		PUL4=~PUL4;
	}
	}
	if(dir == 3)               //���ӿ�
	{
		DIR1=0;DIR2=0;DIR3=1;DIR4=1;
		for(uint32_t i=0;i<=(num*800/360);i++)//ϸ��Ϊ1600/Ȧ����ƽ��ת����Ϊһ�����壬һȦ��Ҫ3200
	{
		delay_us(speed);//�ߵ�ƽ�ڼ����ʱ�䣬����Ƶ��
		//GPIOA->ODR^=GPIO_Pin_3;//��תPA3�ĵ�ƽ
		PUL1=~PUL1;
		PUL2=~PUL2;
		PUL3=~PUL3;
		PUL4=~PUL4;
	}
	}
	if(dir == 4)               //������
	{
		DIR1=0;DIR2=0;DIR3=1;DIR4=1;
		for(uint32_t i=0;i<=(num*800/360);i++)//ϸ��Ϊ1600/Ȧ����ƽ��ת����Ϊһ�����壬һȦ��Ҫ3200
	{
		delay_us(speed);//�ߵ�ƽ�ڼ����ʱ�䣬����Ƶ��
		//GPIOA->ODR^=GPIO_Pin_3;//��תPA3�ĵ�ƽ
		PUL1=~PUL1;
		PUL2=~PUL2;
		PUL3=~PUL3;
		PUL4=~PUL4;
	}
	}
	
}
