# STM32 IoT Project – HTS221, LIS3MDL, LSM6DSL, JSON, Bluetooth

Projekt pokazuje sposób obsługi trzech czujników mierzących parametry środowiskowe na płytce **B-L475E-IOT01A2**.  
Wszystkie czujniki komunikują się z mikrokontrolerem przez magistralę **I2C2**, a dane pomiarowe są wysyłane przez **UART1** w formacie tekstowym.

## Wykorzystane czujniki

- **HTS221** – mierzy temperaturę i wilgotność powietrza.  
- **LIS3MDL** – magnetometr służący do pomiaru pola magnetycznego.  
- **LSM6DSL** – czujnik inercyjny łączący akcelerometr i żyroskop, umożliwia pomiar przyspieszeń i prędkości kątowych.

## Działanie programu

Po uruchomieniu mikrokontrolera każdy czujnik jest inicjalizowany. Użyktkownicy za pomocą funkcji w plikach konfiguracyjnych (xxx_conf.c) mogą przetestować prawidłową inicjalizację czujników:
- temperatura i wilgotność z HTS221
- wektor pola magnetycznego z LIS3MDL
- przyspieszenie i prędkość kątowa z LSM6DSL

## Opis plików źródłowych

### hts221_conf.c
<img width="915" height="250" alt="Zrzut ekranu 2025-11-5 o 15 16 58" src="https://github.com/user-attachments/assets/60ebad96-e0c1-4f2f-b504-41fa3f2a3a08" />

### lis3mdl_conf.c
<img width="843" height="287" alt="Zrzut ekranu 2025-11-5 o 15 17 41" src="https://github.com/user-attachments/assets/4fc413f4-73d7-4188-9369-7fe11e540cc6" />

### lsm6dsl_conf.c
<img width="780" height="342" alt="Zrzut ekranu 2025-11-5 o 15 18 15" src="https://github.com/user-attachments/assets/504d670b-cc70-498a-a9e7-70b1cb972dac" />

**Do każego z plików .c powstał odpowiedni plik nagłówkowy, każdy z plików .c ma funkcję pozwalającą na testy prawidłowej inicjalizacji sensorów oraz wyświetlenie pomiarów w terminalu.**
