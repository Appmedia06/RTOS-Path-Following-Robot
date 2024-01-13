#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "control.h"
#include "kernel.h"
#include "path_follow.h"
#include "timer.h"

#define BTM_DEBUNCE_TIME 2 // 2 ms
uint16_t last_btn_INT_time = 0;

uint8_t move_state = MOVE_READY; 


uint8_t btn_status[2] = {0, 0}; // botton status 0: not be pressed; 1: be pressed
uint8_t first_start_pf = 0;


void move_control(void *arg)
{
    uint8_t lcd_reset  = 1;
    while(1)
    {
        if(move_state == MOVE_READY) // Ready state
        {
            if(lcd_reset) // 顯示LCD
            {
                lcd_reset = 0;
                LCD_CLR();
                LCD_Set_Cursor(0, 0);
                putsLCD("Ready");
                LCD_Set_Cursor(1, 0);
                putsLCD("Enter INT0");
            }

            if(btn_status[0]) // if botton 0 is pressed => start path following
            {
                btn_status[0] = 0;
                move_state = MOVE_PF;
                lcd_reset = 1;
                first_start_pf = 1;
            }
        }

        else if(move_state == MOVE_PF) // Path following state
        {
            if(lcd_reset)
            {
                lcd_reset = 0;
                LCD_CLR();
                LCD_Set_Cursor(0, 0);
                putsLCD("Starting");
                // LCD_Set_Cursor(1, 0);
                // putsLCD("INT1 End");
            }
            
            if(first_start_pf)
            {
                first_start_pf = 0;
                stop_path_follow = 0;
                startTask(path_follow, 0 , MAXIMUM_PRIORITY , MAXIMUM_STACK_SIZE); // task7
            }

            if(btn_status[1]) // if botton 1 is pressed => End path following and back to Ready state
            {
                btn_status[1] = 0;
                stop_path_follow = 1;
                move_state = MOVE_READY;
                lcd_reset = 1;
            }
        }
    }
}

/* Start Path Following */
ISR(INT0_vect)
{
    if(sys_time -  last_btn_INT_time > BTM_DEBUNCE_TIME)
    {
        btn_status[0] = 1;
    }
    EIFR |= 0xFF;
}

/* End Path Following */
ISR(INT1_vect)
{
    if(sys_time -  last_btn_INT_time > BTM_DEBUNCE_TIME)
    {
        btn_status[1] = 1;
    }
	EIFR |= 0xFF;
}



