# STM32 IoT Project – HTS221, LIS3MDL, LSM6DSL, JSON, Bluetooth

Projekt pokazuje sposób obsługi trzech czujników mierzących parametry środowiskowe na płytce **B-L475E-IOT01A2**.  
Wszystkie czujniki komunikują się z mikrokontrolerem przez magistralę **I2C2**, a dane pomiarowe są wysyłane przez **UART1** w formacie tekstowym.

## Wykorzystane czujniki

- **HTS221** – mierzy temperaturę i wilgotność powietrza.  
- **LIS3MDL** – magnetometr służący do pomiaru pola magnetycznego.  
- **LSM6DSL** – czujnik inercyjny łączący akcelerometr i żyroskop, umożliwia pomiar przyspieszeń i prędkości kątowych.
- **SPBTLE-RF** - moduł bluetooth

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

### BLE_conf.c
<img width="811" height="359" alt="image" src="https://github.com/user-attachments/assets/4131df61-b3ab-4141-9a0a-9377e6541983" />

**Do każego z plików .c powstał odpowiedni plik nagłówkowy, każdy z plików .c ma funkcję pozwalającą na testy prawidłowej inicjalizacji sensorów oraz wyświetlenie pomiarów w terminalu.**

### Komunikacja bluetooth

MX_BlueNRG_MS_Init();- funkcja odpowiedzialna za inicjalizację stosu BLE, inicjalizację wartsy HCI, ustawienie adresu MAC oraz rozpoczyna advertising
MX_BlueNRG_MS_Process();- odpowiada za przetwarzanie zdarzeń BLE takich jak połączenia, rozłączenia, odczyty i zapisy charakterystyk oraz komunikację
BLE_SendMessage();- odpowiada za wysłanie wiadomości

**Do komunikacji z mikrokontrolerem wykorzystano aplikację nRF Connect.**

**Odbiór testowej informacji**

<img width="424" height="651" alt="image" src="https://github.com/user-attachments/assets/17bdcab9-95e8-4161-af5d-2771ff92fc27" />
