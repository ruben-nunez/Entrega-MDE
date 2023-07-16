#include <stdio.h>
#include "hardware.h"

typedef enum {
    BUTTON_STATE_SUELTO,
    BUTTON_STATE_PULSADO,
    BUTTON_STATE_MANTENIDO
} ButtonState;

int main() {
    // Inicializar el LED y el botón
    Inicializar_Led_LPCXpresso1769();
    Inicializar_Boton_LPCXpresso1769();

    ButtonState buttonState = BUTTON_STATE_SUELTO;
    uint32_t buttonHoldCounter = 0;

    while (1) {
        // Leer el estado del botón
        uint32_t currentButtonState = Leer_Estado_Boton_LPCXpresso1769();

        // Rutina de antirrebote
        switch (buttonState) {
            case BUTTON_STATE_SUELTO:
                if (currentButtonState == 1) {
                    buttonState = BUTTON_STATE_PULSADO;
                }
                break;
            case BUTTON_STATE_PULSADO:
                if (currentButtonState == 1) {
                    buttonHoldCounter++;
                    if (buttonHoldCounter >= 50) { // Aproximadamente 500ms (50 * 10ms)
                        buttonState = BUTTON_STATE_MANTENIDO;
                    }
                } else {
                    buttonState = BUTTON_STATE_SUELTO;
                    buttonHoldCounter = 0;
                }
                break;
            case BUTTON_STATE_MANTENIDO:
                if (currentButtonState == 0) {
                    buttonState = BUTTON_STATE_SUELTO;
                    buttonHoldCounter = 0;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
