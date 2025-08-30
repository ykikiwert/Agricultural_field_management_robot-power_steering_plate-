#ifndef __GPIO_H
#define __GPIO_H

#include "sys.h"
//BR    É²³µ  ºÚ°×
//RE    µ¹³µ  ×ØºÚ
#define BR1   PAout(7)
#define RE1   PAout(6)
#define BR2   PAout(5)
#define RE2   PAout(4)
#define BR3   PBout(1)
#define RE3   PBout(0)
#define BR4   PCout(5)
#define RE4   PCout(4)

#define PUL1   PBout(6)
#define DIR1   PBout(5)
#define  EN1   PBout(4)
#define PUL2   PBout(7)
#define DIR2   PBout(3)
#define  EN2   PDout(2)
#define PUL3   PBout(8)
#define DIR3   PCout(12)
#define  EN3   PCout(11)
#define PUL4   PBout(9)
#define DIR4   PCout(10)
#define  EN4   PAout(15)

#define STR1   PBout(15)
#define STR2   PBout(14)
#define STR3   PBout(13)
#define STR4   PBout(12)

#define LED2   PAout(1)

void Brush_GPIO_Init(void);

#endif


