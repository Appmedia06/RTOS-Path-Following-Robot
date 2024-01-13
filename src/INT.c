#include "INT.h"


/* Interrupt Initialize */
void INT_Init(void)
{
    EIMSK = (1<<INT7)|(1<<INT6)|(1<<INT5)|(1<<INT1)|(1<<INT0);
	//ISCn1 ISCn0
	// 00 - low level
	// 01 -
	// 10 - negedge
	// 11 - posedge


	// enable INT  0 1 4 6 7 negedge
	EICRA = (1<<ISC01) | (1<<ISC11);
	EICRB = (1<<ISC51) | (1<<ISC61) | (1<<ISC71);

	EIMSK = (1<<INT7)|(1<<INT6)|(1<<INT5)|(1<<INT1)|(1<<INT0);


	DDRD &= ~((1<<DDD1)|(1<<DDD0));
	DDRE &= ~((1<<DDE7)|(1<<DDE6)|(1<<DDE5));

	PORTD |= (1<<PORTD1)|(1<<PORTD0);
	PORTE |= (1<<PORTE7)|(1<<PORTE6)|(1<<PORTE5);

	EIFR |= 0xFF;

}



