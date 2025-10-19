/*
 * W tym pliku podpinamy HTS221 do magistrali I2C2 i tworzymy proste funkcje do odczytu temperatury i wilgotności.
 * Dane są wysyłane przez UART1 w formacie tekstowym.
 */

#include <stdio.h>
#include "hts221_conf.h"

HTS221_Object_t hts221;          // globalny obiekt czujnika
extern UART_HandleTypeDef huart1; // UART1 z main.c

void HTS221_Platform_Init(void)
{
    HTS221_IO_t io_ctx;

    io_ctx.Init    = BSP_I2C2_Init;       // inicjalizacja I2C2
    io_ctx.DeInit  = BSP_I2C2_DeInit;
    io_ctx.BusType = HTS221_I2C_BUS;      // magistrala I2C
    io_ctx.Address = HTS221_I2C_ADDRESS;  // adres czujnika 0xBE
    io_ctx.WriteReg= BSP_I2C2_WriteReg;
    io_ctx.ReadReg = BSP_I2C2_ReadReg;
    io_ctx.GetTick = (HTS221_GetTick_Func)HAL_GetTick;

    HTS221_RegisterBusIO(&hts221, &io_ctx);
    HTS221_Init(&hts221);
    HTS221_HUM_Enable(&hts221);   // włącz pomiar wilgotności
    HTS221_TEMP_Enable(&hts221);   // włącz pomiar temperatury
}

void HTS221_Read_Data(void)
{
    float humidity = 0;
    float temperature = 0;

    if (HTS221_HUM_GetHumidity(&hts221, &humidity) == HTS221_OK && HTS221_TEMP_GetTemperature(&hts221, &temperature) == HTS221_OK)
    {
        char msg[64];
        int len = snprintf(msg, sizeof(msg), "T: %.2f C  H: %.2f %%\r\n", temperature, humidity);
        HAL_UART_Transmit(&huart1, (uint8_t*)msg, len, HAL_MAX_DELAY);
    }
}
