/**********************************************************
*Anthony Webb
**********************************************************/

#include "cpu_clock.h"
#include "usart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define THRESHOLD 900

unsigned char read_byte;

//input the percent you want returns the 8 bit value of
//given percent
int percent_to_8bit(uint8_t percent){
    uint8_t duty;
    duty = percent * 2.55;
    return duty;
};


void delay_s(uint16_t s) {
        int ms  = s * 1000;
        while ( ms )
        {
                _delay_ms(1);
                ms--;
        }
}

/*usart interupt*******************************************/
ISR(USART0_RX_vect){
    read_byte = usart_read();
    
}

/*Main function*******************************************/
int main(void){
/*I/0*/
/*Init****************************************************/
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);

    //output setup
    DDRB |= (1<<PB3);
    DDRC |= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC6);
    DDRD |= (1<<PD7);
   
    //adc set up
    ADCSRA |= (1<<ADATE)|(1<<ADEN)|(1<<ADSC);
    ADMUX |= (1<<REFS1)|(1<<REFS0);
    //TURNING OFF adc pins 1-7
    DIDR0 |= ~(1<<PA0);
    
/*setup**************************************************/
    
    usart_init();
    sei();
    //enabling right and left motor turing on green light
    PORTC |= (1<< PC0)|(1<<PC1)|(1<<PC3);

    while(1){
 

        }
    }

}
