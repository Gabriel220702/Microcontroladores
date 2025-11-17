#include <18F2550.h>            // Incluye el archivo de cabecera del microcontrolador PIC 18F2550
#device ADC=10                 // Configura la resolución del conversor analógico a digital (ADC) a 10 bits

#FUSES NOWDT                    // Configura el bit de No Watch Dog Timer
#FUSES NOBROWNOUT               // Configura el bit de No Brownout
#FUSES NOLVP                    // Configura el bit de No Low-Voltage Programming
#FUSES NOXINST                  // Configura el bit de No Extended Instruction Set
#FUSES PLL1                     // Configura el PLL en 1x

#use delay(crystal=20000000)    // Configura la frecuencia del oscilador de cristal en 20 MHz
#use FIXED_IO( B_outputs=PIN_B7,PIN_B6,PIN_B5,PIN_B4,PIN_B3,PIN_B2,PIN_B1,PIN_B0 )  // Configura los pines B0-B7 como salidas fijas

#define dir_izq         PIN_B0   // Define el pin B0 como dir_izq (dirección del motor izquierdo)
#define en_izq          PIN_B1   // Define el pin B1 como en_izq (activación del motor izquierdo)
#define dir_der         PIN_B2   // Define el pin B2 como dir_der (dirección del motor derecho)
#define en_der          PIN_B3   // Define el pin B3 como en_der (activación del motor derecho)
#define izquierda_pin   PIN_B4   // Define el pin B4 como izquierda_pin (botón virtual para girar a la izquierda)
#define derecha_pin     PIN_B5   // Define el pin B5 como derecha_pin (botón virtual para girar a la derecha)
#define retroceso_pin   PIN_B6   // Define el pin B6 como retroceso_pin (botón virtual para retroceder)
#define adelante_pin    PIN_B7   // Define el pin B7 como adelante_pin (botón virtual para avanzar hacia adelante)

void stop() {
   output_low(en_izq);          // Apaga el motor izquierdo
   output_low(en_der);          // Apaga el motor derecho
}

void avanzar() {
   output_low(dir_izq);         // Configura la dirección del motor izquierdo hacia adelante
   output_high(en_izq);         // Enciende el motor izquierdo
   output_low(dir_der);         // Configura la dirección del motor derecho hacia adelante
   output_high(en_der);         // Enciende el motor derecho
}

void retroceder() {
   output_high(dir_izq);        // Configura la dirección del motor izquierdo hacia atrás
   output_high(en_izq);         // Enciende el motor izquierdo
   output_high(dir_der);        // Configura la dirección del motor derecho hacia atrás
   output_high(en_der);         // Enciende el motor derecho
}

void girar_izquierda() {
   output_high(dir_izq);        // Configura la dirección del motor izquierdo hacia atrás
   output_high(en_izq);         // Enciende el motor izquierdo
   output_low(dir_der);         // Configura la dirección del motor derecho hacia adelante
   output_high(en_der);         // Enciende el motor derecho
}

void girar_derecha() {
   output_low(dir_izq);         // Configura la dirección del motor izquierdo hacia adelante
   output_high(en_izq);         // Enciende el motor izquierdo
   output_high(dir_der);        // Configura la dirección del motor derecho hacia atrás
   output_high(en_der);         // Enciende el motor derecho
}

void main() {
   while(TRUE) {                            // Bucle principal
      if (input(adelante_pin)) {            // Verifica si el botón de avanzar está presionado
         avanzar();                         // Llama a la función para avanzar
      } else if (input(retroceso_pin)) {    // Verifica si el botón de retroceder está presionado
         retroceder();                      // Llama a la función para retroceder
      } else if (input(izquierda_pin)) {    // Verifica si el botón de girar a la izquierda está presionado
         girar_izquierda();                 // Llama a la función para girar a la izquierda
      } else if (input(derecha_pin)) {      // Verifica si el botón de girar a la derecha está presionado
         girar_derecha();                   // Llama a la función para girar a la derecha
      } else {
         stop();                            // Si no se presiona ningún botón, detiene el robot
      }
   }
}

