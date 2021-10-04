#ifndef EEPROM_H_
#define EEPROM_H_


#include "gpio.h"
#include <avr/io.h>

void EEprom_Init();
void EEprom_Write(uint16 address, uint8 data);
uint8 EEprom_Read(uint8 address);
void EEprom_Write_Data(uint16 Address, uint8 data[]);
#endif
