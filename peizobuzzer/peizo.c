/*
 *
 *
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "peizo.h"

static volatile int buzy = 0;
volatile int tuneplaying[1000];
volatile int totaltunelength = 0;
volatile int attunelength = 0;
volatile int Tune = 0;
volatile int tuneplayed = 0;
volatile int a = 0;

volatile unsigned counterA = 0;
volatile unsigned counterB = 0;



void peizo_init(){
    TIMERA = 0;
    TIMERB |= (0 << CS02) | (1 << CS01) | (1 << CS00);
    TIMERMASK |= (1 << TOIE);

    PEIZODDR |= (1 << PEIZOPIN);
    PEIZOPORT &= ~(1 << PEIZOPIN);
    DDRB |= (1 << PB1);
    sei();
}

void playtune(int tune[], int tunelenght)
{

    if(buzy == 0){

        int i = 0;
        for(i = 0; i < tunelenght; i++){

            tuneplaying[i] = tune[i];
        }

        totaltunelength = tunelenght;
        attunelength = 0;
        counterA = 0;
        counterB = 0;
        buzy = 1;
    }
}

ISR(TIMEROVF){

    if(buzy == 1){
        if(976 <= counterA)
        {
            PORTB ^= (1 << PB1);
            if(attunelength < totaltunelength)
            {
                Tune = tuneplaying[attunelength];
                attunelength ++;
                a = 0;
                counterA = 0;
            }
            else
            {
                buzy = 0;
            }
        }

        if(Tune <= counterB)
        {
            if(a < 2){
                PEIZOPORT ^=(1<<PEIZOPIN);
                counterB = 0;
                a++;
            }
        }
        counterA ++;
        counterB ++;
    }
    else
    {
        PEIZOPORT &= ~(1 << PEIZOPIN);
    }



}

