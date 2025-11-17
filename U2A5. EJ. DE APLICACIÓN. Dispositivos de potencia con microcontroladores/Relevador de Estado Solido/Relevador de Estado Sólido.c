#include <18f4550.h>
#fuses XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#use delay(internal=4MHz)

// Definiciones de pines
#define Rele PIN_A0
#define Boton PIN_B0

void main() {
   boolean start = 0;

   set_tris_a(0b11111110);  // Configura RA0 como salida (para el relé)
   set_tris_b(0b00000001);  // Configura RB0 como entrada (para el botón)
   output_low(Rele);        // Inicialmente, apaga el relé

   while(TRUE) {
      // Pregunta por el botón
      if(input(Boton)) {
         delay_ms(200);  // Anti-Debounce
         
         // Instrucción para contabilizar una pulsación del botón
         while(input(Boton)) {
            delay_ms(200);  // Anti-Debounce
         }
         
         start = !start;  // Cambia el estado lógico de start

         // Si se presiona el botón, envía pulsos intermitentes
         while(start) {
            output_high(Rele);  // Activa el relé (RA0)
            delay_ms(1000);      // Espera 1 segundo
            output_low(Rele);   // Desactiva el relé (RA0)
            delay_ms(1000);      // Espera 1 segundo
         }
      }
   }
}

