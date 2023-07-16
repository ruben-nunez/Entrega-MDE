#include "hardware.h"

int32_t Inicializar_Led_LPCXpresso1769(void) {
    // Configurar el pin del LED como GPIO
    *PINSEL_1 &= ~(3 << 12); // Poner bits 12 y 13 en 00

    // Configurar el modo eléctrico del pin como modo normal (sin resistencias de pull-up/pull-down ni modo abierto drenado)
    *PINMODE_OD_0 &= ~(1 << LED_PIN);

    // Configurar el pin del LED como salida
    *FIODIR_0 |= (1 << LED_PIN); // Poner bit 22 en 1 para salida

    return 0; // Éxito
}

int32_t Inicializar_Boton_LPCXpresso1769(void) {
    // Configurar el pin asociado al botón como entrada
    *PINSEL_4 &= ~(0x03 << 20);  // P2.10 como GPIO
    *FIODIR_2 &= ~(1 << BUTTON_PIN); // Configurar el pin como entrada

    return 0; // Éxito
}

int32_t Encender_Led_LPCXpresso1769(void) {
    *FIOPIN_0 &= ~(1 << LED_PIN); // Poner el bit 22 en 0 para encender el LED

    return 0; // Éxito
}

int32_t Apagar_Led_LPCXpresso1769(void) {
    *FIOPIN_0 |= (1 << LED_PIN); // Poner el bit 22 en 1 para apagar el LED

    return 0; // Éxito
}

int32_t Invertir_Led_LPCXpresso1769(void) {
    *FIOPIN_0 ^= (1 << LED_PIN); // Invertir el estado del LED

    return 0; // Éxito
}

int32_t Leer_Estado_Pin_LPCXpresso1769(void) {
    // Leer el estado actual del pin
    uint32_t pinState = (*FIOPIN_0 >> LED_PIN) & 1;

    return pinState;
}

int32_t Leer_Estado_Boton_LPCXpresso1769(void) {
    // Leer el estado actual del botón
    uint32_t buttonState = (*FIO0PIN >> BUTTON_PIN) & 1;

    return buttonState;
}


