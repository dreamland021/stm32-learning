#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include <stdio.h>


uint8_t RxData;

int main(void)
{
	OLED_Init();
	
//	OLED_ShowChar(1, 1, 'A');
//	OLED_ShowString(1, 3, "HelloWT!");
//	OLED_ShowNum(2, 1, 12345, 5);
//	OLED_ShowSignedNum(2, 7, -66, 2);
//	OLED_ShowHexNum(3, 1, 0xAA55, 4);
//	OLED_ShowBinNum(4, 1, 0xAA55, 16);
	Serial_Init();
	Serial_SendData(0x41);
	Serial_SendNumber(12233, 5);
	char string[10];
	sprintf(string, "你好，世界 = %d\r\n", 666);
	Serial_SendString(string);
	
	
	while (1)
	{
		if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET)
		{
			RxData = USART_ReceiveData(USART1);
			OLED_ShowHexNum(1, 1, RxData, 4);
			
		}
				
		
	}
}
