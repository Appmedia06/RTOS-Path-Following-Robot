
#ifndef CONTROL_H_
#define CONTROL_H_



#define MOVE_READY 0 // Ready state
#define MOVE_PF    1 // Path Follow


#define 	SETBIT(REG,BIT)	(REG |= (_BV(BIT)))
#define 	CLRBIT(REG,BIT)	(REG &= ~(_BV(BIT)))
#define 	CHKBIT(REG,BIT)	((REG & (_BV(BIT)))==(_BV(BIT)))

extern uint8_t btn_status[2];


void move_control(void *arg);







#endif /* CONTROL_H_ */