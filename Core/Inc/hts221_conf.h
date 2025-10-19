/*
 * Ten plik łączy bibliotekę czujnika HTS221 z kodem STM32.
 * Dzięki temu możemy łatwo zainicjalizować czujnik i odczytać temperaturę oraz wilgotność.
 */

#ifndef HTS221_CONF_H
#define HTS221_CONF_H

#include "hts221.h"
#include "b_l475e_iot01a2_bus.h"   // obsługa I2C z BSP

#ifdef __cplusplus
extern "C" {
#endif

extern HTS221_Object_t hts221;   // obiekt czujnika

void HTS221_Platform_Init(void); // inicjalizacja czujnika
void HTS221_Read_Data(void);     // odczyt i wysyłka danych po UART

#ifdef __cplusplus
}
#endif
#endif
