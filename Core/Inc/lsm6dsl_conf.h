/*
   Plik konfiguracyjny dla czujnika LSM6DSL
   Ułatwia inicjalizację i odczyt danych z akcelerometru i żyroskopu.
   Bazuje na HAL i bibliotece BSP dla płytki B-L475E-IOT01A2.
*/

#ifndef LSM6DSL_CONF_H
#define LSM6DSL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "b_l475e_iot01a2_bus.h"   // Dostęp do I2C
#include "lsm6dsl.h"                // Główny driver czujnika
#include <stdio.h>

extern LSM6DSL_Object_t lsm6dsl;

// Funkcje inicjalizacji i odczytu
void LSM6DSL_Platform_Init(void);
void LSM6DSL_Read_Data(void);

#ifdef __cplusplus
}
#endif

#endif // LSM6DSL_CONF_H
