#ifndef __SERIAL_H
#define __SERIAL_H



void Serial_Init();

void Serial_SendData(uint8_t Byte);
void Serial_SendNumber(uint32_t number, uint8_t length);
uint32_t Serial_pow(uint8_t X, uint8_t Y);
void Serial_SendArray(uint8_t* array, uint8_t length);
void Serial_SendString(char* string);
void Serial_SendData(uint8_t Byte);


#endif



