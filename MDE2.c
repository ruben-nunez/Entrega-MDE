#include <stdint.h>
#include "hardware.h"

#define ANTIRREBOTE_DELAY_MS 50  // Tiempo de antirrebote en milisegundos
#define MANTENIDO_DELAY_MS 1000  // Tiempo de mantenimiento en milisegundos

enum EstadoBoton {
    PULSADO,
    SUELTO,
    MANTENIDO
};

enum EstadoBoton estadoBoton = SUELTO;  // Estado inicial del botón
uint32_t contadorMantenimiento = 0;     // Contador para el tiempo de mantenimiento

void Rutina_Antirrebote(void) {
    // Leer el estado actual del pin del botón
    int32_t estadoPin = Leer_Estado_Pin_LPCXpresso1769();

    switch (estadoBoton) {
        case PULSADO:
            if (estadoPin == LED_OFF) {
                // Cambiar al estado "SUELTO" si el botón se ha soltado
                estadoBoton = SUELTO;
                contadorMantenimiento = 0;  // Reiniciar el contador de mantenimiento
            } else if (contadorMantenimiento >= MANTENIDO_DELAY_MS) {
                // Cambiar al estado "MANTENIDO" si el botón se ha mantenido presionado durante el tiempo establecido
                estadoBoton = MANTENIDO;
            } else {
                contadorMantenimiento++;  // Incrementar el contador de mantenimiento
            }
            break;

        case SUELTO:
            if (estadoPin == LED_ON) {
                // Esperar un tiempo de antirrebote
                for (volatile uint32_t i = 0; i < ANTIRREBOTE_DELAY_MS * 1000; ++i) {
                    // Esperar
                }

                // Verificar nuevamente el estado del pin después del antirrebote
                estadoPin = Leer_Estado_Pin_LPCXpresso1769();

                if (estadoPin == LED_ON) {
                    // Cambiar al estado "PULSADO" si el botón sigue presionado después del antirrebote
                    estadoBoton = PULSADO;
                    contadorMantenimiento = 0;  // Reiniciar el contador de mantenimiento
                }
            }
            break;

        case MANTENIDO:
            if (estadoPin == LED_OFF) {
                // Cambiar al estado "SUELTO" si el botón se ha soltado
                estadoBoton = SUELTO;
                contadorMantenimiento = 0;  // Reiniciar el contador de mantenimiento
            }
            break;
    }
}
