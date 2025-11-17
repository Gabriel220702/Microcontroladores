#include <18f4550.h>
#fuses XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP,WRT
#device adc=10
#use delay(clock=4000000,crystal)

#define SW PIN_D0
#define MOTOR_PIN_A_1 PIN_B0
#define MOTOR_PIN_B_1 PIN_B1
#define MOTOR_PIN_A_2 PIN_B2
#define MOTOR_PIN_B_2 PIN_B3

void main() {
    setup_adc_ports(NO_ANALOGS);
    set_tris_d(0b00000001);  // Configura el pin del botón como entrada
    set_tris_b(0b00000000);  // Configura los pines del motor como salida
    output_b(0x00);           // Apaga ambos motores inicialmente
    
    int boton_estado_anterior = 0;
    int boton_estado_actual;
    int direccion_1 = 1;  // Variable para almacenar la dirección del giro del motor 1 (1 o -1)
    int direccion_2 = 1;  // Variable para almacenar la dirección del giro del motor 2 (1 o -1)

    while (true) {
        // Lee el estado actual del botón
        boton_estado_actual = input(SW);

        // Verifica si el botón ha sido presionado
        if (boton_estado_actual && !boton_estado_anterior) {
            // Cambia la dirección del giro de ambos motores
            direccion_1 = -direccion_1;  // Cambia la dirección del giro del motor 1
            direccion_2 = -direccion_2;  // Cambia la dirección del giro del motor 2

            // Determina la dirección del giro del motor 1
            if (direccion_1 == 1) {
                output_high(MOTOR_PIN_A_1);
                output_low(MOTOR_PIN_B_1);
            } else {
                output_low(MOTOR_PIN_A_1);
                output_high(MOTOR_PIN_B_1);
            }

            // Determina la dirección del giro del motor 2
            if (direccion_2 == 1) {
                output_high(MOTOR_PIN_A_2);
                output_low(MOTOR_PIN_B_2);
            } else {
                output_low(MOTOR_PIN_A_2);
                output_high(MOTOR_PIN_B_2);
            }
        }

        // Actualiza el estado anterior del botón
        boton_estado_anterior = boton_estado_actual;
   }
}

