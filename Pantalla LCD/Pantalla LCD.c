#include <16F877.h>

#FUSES XT, NOWDT, NOPROTECT, PUT, NOLVP, NOBROWNOUT
#USE DELAY (clock=4000000)
#include <lcd.c>

#USE standard_io(D)
#USE standard_io(B)

void main ()
{
   disable_interrupts(GLOBAL);
   lcd_init();
   for( ; ; )
   {
      lcd_putc("\fSw 1:");
      if(input(pin_b0))
         lcd_putc("ON");
      else
         lcd_putc("OFF");
         lcd_putc(" 2:");
      if(input(pin_b1))
         lcd_putc("ON");
      else
         lcd_putc("OFF");
         delay_ms(100);
   }
}

