/*
 *
 *
 */




#ifndef PEIZO_H_INCLUDED
#define PEIZO_H_INCLUDED

#define TIMERA TCCR0A
#define TIMERB TCCR0B
#define TCNT TCNT0
#define TIMERMASK TIMSK0
#define TOIE TOIE0
#define OCIEA OCIE0A

#define OCRA OCR0A

#define TIMEROVF TIMER0_OVF_vect
#define TIMER_COMPA TIMER0_COMPA_vect

#define PEIZODDR DDRB
#define PEIZOPORT PORTB
#define PEIZOPIN PB0




void peizo_init();
void playtune(int tune[], int tunelenght);

#endif // PEIZO_H_INCLUDED
