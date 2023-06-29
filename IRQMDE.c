#include <stdio.h>
#include "hardware.h"

// Estados de la máquina de estados
typedef enum {
    STATE_WAIT_PRESS,    // Esperando a que se presione el botón
    STATE_WAIT_RELEASE,  // Esperando a que se suelte el botón
    STATE_TOGGLE_LED     // Cambiar el estado del LED
} State;

int main() {
    // Inicializar el LED y el botón
    Inicializar_Led_LPCXpresso1769();
    Inicializar_Boton_LPCXpresso1769();

    // Configurar el estado inicial de la máquina de estados
    State currentState = STATE_WAIT_PRESS;
    int32_t ledState = LED_OFF; // Estado inicial del LED
    int32_t buttonState = 0;    // Estado inicial del botón

    while (1) {
        // Leer el estado del botón
        buttonState = Leer_Estado_Boton_LPCXpresso1769();

        switch (currentState) {
            case STATE_WAIT_PRESS:
                // Esperar a que se presione el botón
                if (buttonState == BUTTON_PRESSED) {
                    currentState = STATE_WAIT_RELEASE;
                }
                break;

            case STATE_WAIT_RELEASE:
                // Esperar a que se suelte el botón
                if (buttonState != BUTTON_PRESSED) {
                    currentState = STATE_TOGGLE_LED;
                }
                break;

            case STATE_TOGGLE_LED:
                // Cambiar el estado del LED
                if (ledState == LED_OFF) {
                    Encender_Led_LPCXpresso1769();
                    ledState = LED_ON;
                } else {
                    Apagar_Led_LPCXpresso1769();
                    ledState = LED_OFF;
                }

               
                // Aquí se puede ajustar el intervalo según sea necesario
                for (volatile int i = 0; i < INTERVAL_100MS; i++) {}

                currentState = STATE_WAIT_PRESS;
                break;

            default:
                break;
        }
    }

    return 0;
}

