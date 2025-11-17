#include <16f877a.h>
#fuses XT, NOWDT, PUT, NOPROTECT, BROWNOUT, NOCPD, NOWRT, NODEBUG
#use delay(clock=4Mhz)
#define use_portd_lcd true
#define use_portb_kbd true
#include <lcd.c>
#include <kbd.c>
#include <stdio.h>

void main(){
    char k;
    lcd_init();       // Inicializa el LCD
    kbd_init();       // Inicializa el teclado matricial
    port_b_pullups(true);  // Habilita resistencias pull-up en el puerto B

    lcd_putc("\f Leyendo Teclado\n"); // Limpia la pantalla del LCD y muestra el mensaje inicial

    while(1){  // Bucle infinito
        k = kbd_getc();  // Lee la tecla del teclado matricial

        if(k != 0){  // Verifica si se ha presionado una tecla
            if(k == '*' || k == '#')
                printf(lcd_putc, "\f Tecla signo= %c\n", k); // Si es '*' o '#', muestra un mensaje especial
            else
                printf(lcd_putc, "\f Tecla No= %c\n", k); // Si es cualquier otra tecla, muestra un mensaje general
            delay_ms(500);  // Espera para evitar rebotes y múltiples lecturas
            lcd_putc("\f Leyendo Teclado\n"); // Muestra el mensaje de lectura nuevamente
        }
    }
}

