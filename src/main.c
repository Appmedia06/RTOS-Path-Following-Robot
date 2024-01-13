#include <avr/io.h>
#include <util/delay.h>

#include "4B_LCD.h"
#include "timer.h"
#include "adc.h"
#include "motor.h"
#include "INT.h"
#include "control.h"
#include "kernel.h"
#include "led.h"


int main(void)
{
 	OpenLCD(); // LCD Init


    ADC_Init(); // ADC Init
    Timer3_PWM_Init(); // Timer3 PWM Init
    INT_Init(); // Interrupt Init
    led_Init(); // LED Init


    initKernel(); // kernel Init
    Timer1_Init(); //ticks1 for kernel 1 shot 1ms (ticks1)

    startTask( led_0 , 0, MAXIMUM_PRIORITY, MINIMUM_STACK_SIZE ); // task1
    startTask( led_1 , 0, MAXIMUM_PRIORITY, MINIMUM_STACK_SIZE ); // task2
    startTask( led_2 , 0, MAXIMUM_PRIORITY, MINIMUM_STACK_SIZE ); // task3
    startTask( led_3 , 0, MAXIMUM_PRIORITY, MINIMUM_STACK_SIZE ); // task4
    startTask( led_4 , 0, MAXIMUM_PRIORITY, MINIMUM_STACK_SIZE ); // task5

    startTask( move_control , 0 , MEDIUM_PRIORITY , MEDIUM_STACK_SIZE ); // task6

    sei();
    while(1){}
}