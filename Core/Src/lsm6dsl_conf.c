/*
   Implementacja konfiguracji czujnika LSM6DSL
   Ustawienia i odczyt danych z akcelerometru i żyroskopu.
   Wykorzystuje I2C2 (na płytce B-L475E-IOT01A2).
*/

#include "lsm6dsl_conf.h"

extern UART_HandleTypeDef huart1;

LSM6DSL_Object_t lsm6dsl;

void LSM6DSL_Platform_Init(void)
{
    LSM6DSL_IO_t io_ctx;

    io_ctx.BusType  = LSM6DSL_I2C_BUS;
    io_ctx.Address  = LSM6DSL_I2C_ADD_L;
    io_ctx.Init     = BSP_I2C2_Init;
    io_ctx.DeInit   = BSP_I2C2_DeInit;
    io_ctx.ReadReg  = BSP_I2C2_ReadReg;
    io_ctx.WriteReg = BSP_I2C2_WriteReg;
    io_ctx.GetTick     = (LSM6DSL_GetTick_Func)HAL_GetTick;

    if (LSM6DSL_RegisterBusIO(&lsm6dsl, &io_ctx) != LSM6DSL_OK)
        return;
    if (LSM6DSL_Init(&lsm6dsl) != LSM6DSL_OK)
        return;

    LSM6DSL_ACC_Enable(&lsm6dsl);
    LSM6DSL_GYRO_Enable(&lsm6dsl);
}

void LSM6DSL_Read_Data(void)
{
    LSM6DSL_Axes_t acc;
    LSM6DSL_Axes_t gyro;
    char msg[100];

    if (LSM6DSL_ACC_GetAxes(&lsm6dsl, &acc) == LSM6DSL_OK && LSM6DSL_GYRO_GetAxes(&lsm6dsl, &gyro) == LSM6DSL_OK)
    {
        int len = snprintf(msg, sizeof(msg), "ACC: X=%ld Y=%ld Z=%ld\r\nGYRO: X=%ld Y=%ld Z=%ld\r\n", acc.x, acc.y, acc.z, gyro.x, gyro.y, gyro.z);
        HAL_UART_Transmit(&huart1, (uint8_t*)msg, len, HAL_MAX_DELAY);
    }
}
