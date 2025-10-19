/*
 * Tutaj robimy konfigurację LIS3MDL, czyli podłączamy bibliotekę czujnika do sprzętowego I2C w STM32.
 * Dzięki temu nie trzeba pisać HALa ręcznie. Jest też funkcja do odczytu X/Y/Z i wysyłania wyników przez UART1.
 */

#include <stdio.h>
#include "lis3mdl_conf.h"

LIS3MDL_Object_t lis3mdl;          // globalny obiekt czujnika
extern UART_HandleTypeDef huart1;  // UART1 z main.c

void LIS3MDL_Platform_Init(void)
{
    LIS3MDL_IO_t io_ctx;

    io_ctx.Init    = BSP_I2C2_Init;       // inicjalizacja I2C2
    io_ctx.DeInit  = BSP_I2C2_DeInit;
    io_ctx.BusType = LIS3MDL_I2C_BUS;     // wybór magistrali I2C
    io_ctx.Address = LIS3MDL_I2C_ADD_H;   // adres czujnika 0x3D
    io_ctx.WriteReg= BSP_I2C2_WriteReg;   // funkcje zapisu
    io_ctx.ReadReg = BSP_I2C2_ReadReg;    // funkcje odczytu
    io_ctx.GetTick = (LIS3MDL_GetTick_Func)HAL_GetTick; // licznik ms
    io_ctx.Delay   = HAL_Delay;            // prosty delay

    // zarejestruj połączenie z czujnikiem
    LIS3MDL_RegisterBusIO(&lis3mdl, &io_ctx);

    // uruchom czujnik i włącz pomiar pola magnetycznego
    LIS3MDL_Init(&lis3mdl);
    LIS3MDL_MAG_Enable(&lis3mdl);
}

void LIS3MDL_Read_Magnetic(void)
{
    LIS3MDL_Axes_t mag;
    if (LIS3MDL_MAG_GetAxes(&lis3mdl, &mag) == LIS3MDL_OK)
    {
        char msg[64];
        int len = snprintf(msg, sizeof(msg), "X: %ld  Y: %ld  Z: %ld\r\n", mag.x, mag.y, mag.z);
        HAL_UART_Transmit(&huart1, (uint8_t*)msg, len, HAL_MAX_DELAY);
    }
}
