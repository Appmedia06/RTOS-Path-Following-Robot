#include "motor.h"
#include "control.h"


/* Timer3 PWM Ininialize */
void Timer3_PWM_Init(void)
{
	// 10 bit fast pwm TOP= 0x03FF , 0-1023
	TCCR3A=(1<<COM3A1)|(1<<COM3B1)|(1<<WGM31)|(1<<WGM30);
	TCCR3B=(1<<WGM32)|(1<<CS32); // clk/256
	// TCCR3C=(1<<FOC3A)|(1<<FOC3B); //
	OCR3A = 0;	//PE3(OC3A)(MOTOR_L)
	OCR3B = 0;	//PE4(OC3B)(MOTOR_R)

	DDRB = 0x0F;
	// DDRE = 0x1F;
	DDRE |= (1<<PE3)|(1<<PE4);
	// PORTB &= ~0b1111;
}

/* Direction */
void set_motor_dir(uint8_t dir)
{
	if(dir == FORWARD)
	{
		CLRBIT(PORTB, PB0);
		SETBIT(PORTB, PB1);
		CLRBIT(PORTB, PB2);
		SETBIT(PORTB, PB3);
	}
	else if(dir == TURN_LEFT)
	{
		CLRBIT(PORTB, PB0);
		SETBIT(PORTB, PB1);
		CLRBIT(PORTB, PB3);
		SETBIT(PORTB, PB2);
	}
	else if(dir == TURN_RIGHT)
	{
		CLRBIT(PORTB, PB1);
		SETBIT(PORTB, PB0);
		CLRBIT(PORTB, PB2);
		SETBIT(PORTB, PB3);
	}
}

/* Speed */
void set_motor_Speed(uint16_t speed_L, uint16_t speed_R)
{
	OCR3A = speed_L;
	OCR3B = speed_R;
}


/* motion choice */
void motion_Forward(void)
{
	set_motor_dir(FORWARD);
	set_motor_Speed(set_speed, set_speed);
}

void motion_Turn_Left(void)
{
	set_motor_dir(FORWARD);
	set_motor_Speed(set_speed, set_speed + 28);
}

void motion_Turn_Right(void)
{
	set_motor_dir(FORWARD);
	set_motor_Speed(set_speed + 28, set_speed);
}

void motion_Stop(void)
{
	set_motor_dir(FORWARD);
	set_motor_Speed(0, 0);
}
