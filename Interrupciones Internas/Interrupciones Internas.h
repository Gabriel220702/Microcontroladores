#include <18F4550.h>
#device ADC=10

#FUSES NOWDT                 	//No Watch Dog Timer

#use delay(crystal=40MHz)
#use FIXED_IO( A_outputs=PIN_A1,PIN_A0 )

