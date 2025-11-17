#include <16F877.h>
#FUSES HS, NOWDT, NOPROTECT, NOLVP
#USE delay(clock=4000000)

void main()
{
   set_tris_a(0b111111);
   set_tris_b(0b00000000);
   set_tris_d(0b00000000);
   output_b(0x00);
   output_d(0x00);
   
   int display[10]={0b00111111,
                    0b00000110,
                    0b01011011,
                    0b01001111,
                    0b01100110,
                    0b01101101,
                    0b01111101,
                    0b00000111,
                    0b01111111,
                    0b01101111};
   
   int8 entrada;
   int8 num1, num2;
   
   while (TRUE)
   {
      for (int i = 0; i < 100; i++) {
         entrada = i;
         num1 = entrada / 10;
         num2 = entrada % 10;
         output_b(display[num1]);
         output_d(display[num2]);
         delay_ms(200);
      }
   }
}
