#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define STOP 		0
#define FORWARD 	1
#define TURN_LEFT 	2
#define BACKWARD	3
#define TURN_RIGHT 	4

void Timer3_PWM_Init(void);


#define MOTOR_DIR_FF    0b1010
#define MOTOR_DIR_FB    0b0110
#define MOTOR_DIR_FS    0b0010
#define MOTOR_DIR_BF    0b1001
#define MOTOR_DIR_BB    0b0101
#define MOTOR_DIR_BS    0b0001
#define MOTOR_DIR_SF    0b1000
#define MOTOR_DIR_SB    0b0100
#define MOTOR_DIR_SS    0b0000

#define set_speed 75 // normal speed (adjust)

void set_motor_dir(uint8_t dir);
void set_motor_Speed(uint16_t speed_L, uint16_t speed_R);

void motion_Forward(void);
void motion_Turn_Left(void);
void motion_Turn_Right(void);
void motion_Stop(void);

#endif /* MOTOR_H_ */