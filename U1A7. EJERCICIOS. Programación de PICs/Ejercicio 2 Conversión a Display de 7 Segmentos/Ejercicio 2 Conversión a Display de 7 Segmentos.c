#INCLUDE <16F877.h>
#FUSES HS, NOWDT, NOPROTECT, NOLVP
#USE delay(clock = 4000000)

// Define la matriz para los números del 0 al 9 en el display de 7 segmentos
int display[10] = {0b00111111, // 0
                   0b00000110, // 1
                   0b01011011, // 2
                   0b01001111, // 3
                   0b01100110, // 4
                   0b01101101, // 5
                   0b01111101, // 6
                   0b00000111, // 7
                   0b01111111, // 8
                   0b01101111  // 9
                  };

void main() {
    // Configura PORTA para leer los interruptores
    set_tris_a(0b00111111); // RA0-RA5 como entradas
    set_tris_b(0x00);       // PORTB como salida para el display de las unidades
    set_tris_d(0x00);       // PORTD como salida para el display de las decenas

    while (TRUE) {
        int valor = input_a() & 0x3F; // Lee los 6 bits de entrada (RA0-RA5)

        int decena = valor / 10; // Calcula la decena
        int unidad = valor % 10; // Calcula la unidad

        // Muestra la decena en un display y la unidad en otro
        output_b(display[unidad]); // Muestra las unidades en PORTB
        output_d(display[decena]); // Muestra las decenas en PORTD

        delay_ms(250); // Pequeño retardo para evitar parpadeos rápidos
    }
}

