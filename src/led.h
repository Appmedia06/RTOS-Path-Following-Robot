#ifndef LED_H_
#define LED_H_


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "4B_LCD.h"



// #define 	SETBIT(REG,BIT)	(REG |= (_BV(BIT)))
// #define 	CLRBIT(REG,BIT)	(REG &= ~(_BV(BIT)))
// #define 	CHKBIT(REG,BIT)	((REG & (_BV(BIT)))==(_BV(BIT)))


#define LED0    PG0
#define LED1    PG1
#define LED2    PG2
#define LED3    PG3
#define LED4    PG4


// low active
// write_led 1 will turn on
#define write_led0(x)   (!x ? (PORTG |= (1<<LED0)) : (PORTG &= ~(1<<LED0)))
#define write_led1(x)   (!x ? (PORTG |= (1<<LED1)) : (PORTG &= ~(1<<LED1)))
#define write_led2(x)   (!x ? (PORTG |= (1<<LED2)) : (PORTG &= ~(1<<LED2)))
#define write_led3(x)   (!x ? (PORTG |= (1<<LED3)) : (PORTG &= ~(1<<LED3)))
#define write_led4(x)   (!x ? (PORTG |= (1<<LED4)) : (PORTG &= ~(1<<LED4)))


/* LED Init */
void led_Init(void)
{
	DDRG |= (1<<LED0) | (1<<LED1) | (1<<LED2) | (1<<LED3) | (1<<LED4);
	PORTG |= (1<<LED0) | (1<<LED1) | (1<<LED2) | (1<<LED3) | (1<<LED4); // turn all off led
}


/* LED Blink */
void led_0(void *arg)
{
	while(1)
    {
		write_led0(1);
		sleep(1000);
		write_led0(0);
		sleep(1000);
	}
}

void led_1(void *arg)
{
	while(1)
    {
		write_led1(1);
		sleep(1000);
		write_led1(0);
		sleep(1000);
	}
}

void led_2(void *arg)
{
	while(1)
    {
		write_led2(1);
		sleep(1000);
		write_led2(0);
		sleep(1000);
	}
}

void led_3(void *arg)
{
	while(1)
    {
		write_led3(1);
		sleep(1000);
		write_led3(0);
		sleep(1000);
	}
}

void led_4(void *arg)
{
	while(1)
    {
		write_led4(1);
		sleep(1000);
		write_led4(0);
		sleep(1000);
	}
}


#endif /* LED_H_ */