#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
#include "MyDMA.h"

//代码思路：
//初始化DMA，并且开启了DMA，让DMA开始转运数据，然后又初始化了ADC，
//开启了转化的过程，设置、使能、使用软件触发，在转化的过程中会产生
//DMA信号到DMA中，然后DMA开始一步转化。也就是说，仅仅MyDMA_Init();时，
//DMA没有工作，因为缺乏触发源。我让他们一起工作之后，ADValue这个数
//组里就是四个传感器转化后的数值。

uint16_t ADValue[4];

int main(void)
{
	OLED_Init();
	MyDMA_Init();
	AD_Init();
	
	while (1)
	{
			
		OLED_ShowNum(1, 5, ADValue[0], 4);
		OLED_ShowNum(2, 5, ADValue[1], 4);
		OLED_ShowNum(3, 5, ADValue[2], 4);
		OLED_ShowNum(4, 5, ADValue[3], 4);

		Delay_ms(100);
		
		
	}
}
