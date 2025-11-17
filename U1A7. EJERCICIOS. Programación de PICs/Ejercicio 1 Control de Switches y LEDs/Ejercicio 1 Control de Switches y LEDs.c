#include <16f877a.h>
#fuses XT, NOWDT, NOPROTECT, NOLVP
#use delay(clock = 4000000)
#byte TRISB = 0x86
#byte PORTB = 0x06
#byte OPTION_REG = 0x81

void main()
{
   bit_clear(OPTION_REG, 7);   // Desactiva el pull-up en RB0-RB3
   bit_set(TRISB, 0);          // Configura RB0 como entrada
   bit_set(TRISB, 1);          // Configura RB1 como entrada
   bit_set(TRISB, 2);          // Configura RB2 como entrada
   bit_set(TRISB, 3);          // Configura RB3 como entrada
   bit_clear(TRISB, 4);        // Configura RB4 como salida
   bit_clear(TRISB, 5);        // Configura RB5 como salida
   bit_clear(TRISB, 6);        // Configura RB6 como salida
   bit_clear(TRISB, 7);        // Configura RB7 como salida

   while (1)
   {
      // Control para el LED conectado a RB4 (botón conectado a RB0)
      if (bit_test(PORTB, 0) == 1)
         bit_clear(PORTB, 4);
      else
         bit_set(PORTB, 4);

      // Control para el LED conectado a RB5 (botón conectado a RB1)
      if (bit_test(PORTB, 1) == 1)
         bit_clear(PORTB, 5);
      else
         bit_set(PORTB, 5);

      // Control para el LED conectado a RB6 (botón conectado a RB2)
      if (bit_test(PORTB, 2) == 1)
         bit_clear(PORTB, 6);
      else
         bit_set(PORTB, 6);

      // Control para el LED conectado a RB7 (botón conectado a RB3)
      if (bit_test(PORTB, 3) == 1)
         bit_clear(PORTB, 7);
      else
         bit_set(PORTB, 7);
   }
}

