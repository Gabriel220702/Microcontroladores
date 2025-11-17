#include <18F2550.h>
#device ADC=10
#FUSES NOWDT, NOPROTECT, NOLVP, NODEBUG, XT                    //No Watch Dog Timer
#use delay(crystal=4000000)
#include <lcd.c>
#include <math.h>

#define LED_SOBRECALOR PIN_C0
#define LED_BAJATEMP PIN_C1

void main()
{
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(ALL_ANALOG);
   
   int16 a;
   int8 temp;
   lcd_init();
   
   output_low(LED_SOBRECALOR);
   output_low(LED_BAJATEMP);
   
   while(TRUE)
   {
      set_adc_channel(0);
      delay_us(20);
      a=read_adc();
      temp=(a*500)/1023;
      printf(lcd_putc,"\fLa Temperatura \nes:%u",temp);
      
      if(temp > 35){
         output_high(LED_SOBRECALOR);
      }
      else{
         output_low(LED_SOBRECALOR);
      }
      
      if(temp<5){
         output_high(LED_BAJATEMP);
      }
      else{
         output_low(LED_BAJATEMP);
      }
      
      delay_ms(500);
     
      //TODO: User Code
   }

}
