#include <18F4550.h>
#fuses HS, NOWDT, NOPROTECT, NOLVP
#use delay(clock=4000000)

#define BOTON PIN_A0
#define LED   PIN_A1

void main() {
    set_tris_a(0x01); // Configura RA0 como entrada
    output_low(LED);  // Asegura que el LED esté apagado al iniciar

    while(TRUE) {
        if (input(BOTON) == 0) {
            output_high(LED); // Si el botón está presionado, enciende el LED
        } else {
            output_low(LED);  // Si el botón no está presionado, apaga el LED
        }
    }
}


