#include "stm32f10x.h"                  // Device header
#include <stdio.h>     

void Serial_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	
	USART_Init(USART1, &USART_InitStructure);

	USART_Cmd(USART1, ENABLE);

}


void Serial_SendData(uint8_t Byte)
{
	USART_SendData(USART1, Byte);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	
}



void Serial_SendString(char* string)
{
	while(*string != '\0')
	{
		Serial_SendData(*string);
		string++;
	
	}


}

void Serial_SendArray(uint8_t* array, uint8_t length)
{
	for(int8_t i = 0; i < length; i++)
	{
		Serial_SendData(*array);
		array++;
	
	}


}


uint32_t Serial_pow(uint8_t X, uint8_t Y)
{
	int result = 1;
	for(int8_t i = 0; i < Y; i++)
	{
		result *= X;
	
	}
	return result;
}


void Serial_SendNumber(uint32_t number, uint8_t length)
{
	
	for(int8_t i = length - 1; i >= 0; i--)
	{
		uint8_t mod_num;
		mod_num = (number / (Serial_pow(10, i))) % 10;
		Serial_SendData(mod_num + '0');

	}

}


int fputc(int ch, FILE *f)
{






}



