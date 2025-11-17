#include <18F2550.h>
#fuses XT, NOWDT, NOPUT, NOLVP, NOPROTECT, BROWNOUT
#use delay(clock=4M)
#use standard_io(B)

// Contador para controlar las interrupciones de Timer1
int contador_timer1 = 0;

#INT_TIMER1
void timer1_interrupcion() {
   contador_timer1++; // Incrementar contador de Timer1
   output_toggle(PIN_B0); // Alternar estado del primer LED cada 1 segundo
   
   if (contador_timer1 % 2 == 0) {
      output_toggle(PIN_B1); // Alternar estado del segundo LED cada vez que se alcanzan 2 segundos
   }

   if (contador_timer1 >= 2) {
      contador_timer1 = 0; // Reiniciar contador de Timer1
   }
}

void main() {
  set_tris_b(0x00); // Configurar B0 y B1 como salidas

  // Configurar Timer1 para 1 segundo
  setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
  set_timer1(15536); // Carga para contar 1 segundo

  enable_interrupts(INT_TIMER1); // Habilitar interrupción de Timer1
  enable_interrupts(GLOBAL);    // Habilitar todas las interrupciones globales

  output_high(PIN_B0); // Encender PIN RB0 inicialmente

  while(true) {
    // El bucle principal está vacío; el parpadeo de los LEDs se maneja totalmente desde las interrupciones
  }
}

