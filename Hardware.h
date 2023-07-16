#ifndef HARDWARE_H
#define HARDWARE_H

#include <stdint.h>

// Direcciones de memoria de los registros de configuración y lectura/escritura de los pines
extern volatile uint32_t *PINSEL_1;
extern volatile uint32_t *PINSEL_4;
extern volatile uint32_t *PINMODE_OD_0;
extern volatile uint32_t *PINMODE_OD_2;
extern volatile uint32_t *FIODIR_0;
extern volatile uint32_t *FIODIR_2;
extern volatile uint32_t *FIOPIN_0;
extern volatile uint32_t *FIOPIN_2;

// Constantes asociadas al manejo del LED
#define LED_PIN 22       // Número de pin para el LED (P0.22)
#define LED_ON 0         // Valor para encender el LED
#define LED_OFF 1        // Valor para apagar el LED

// Constantes asociadas a las frecuencias de activación del LED
#define FREQUENCY_100MS 100    // 100 ms
#define FREQUENCY_300MS 300    // 300 ms
#define FREQUENCY_500MS 500    // 500 ms
#define FREQUENCY_1S 1000      // 1 segundo

// Dirección de memoria del registro de lectura del botón
extern volatile uint32_t *FIO0PIN;

// Constantes asociadas al manejo del botón
#define BUTTON_PIN 4     // Número de pin para el botón (P2.10)
#define BUTTON_PRESSED 0 // Valor cuando el botón está presionado

// Inicializa el pin asociado al LED como salida
int32_t Inicializar_Led_LPCXpresso1769(void);
// Inicializa el pin asociado al botón como entrada
int32_t Inicializar_Boton_LPCXpresso1769(void);
// Enciende el LED
int32_t Encender_Led_LPCXpresso1769(void);
// Apaga el LED
int32_t Apagar_Led_LPCXpresso1769(void);
// Invierte el estado del LED
int32_t Invertir_Led_LPCXpresso1769(void);
// Lee el estado del pin asociado al LED
int32_t Leer_Estado_Pin_LPCXpresso1769(void);
// Lee el estado del botón
int32_t Leer_Estado_Boton_LPCXpresso1769(void);
#endif  /* HARDWARE_H */
