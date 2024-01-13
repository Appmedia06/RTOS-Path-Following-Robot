#include "adc.h"
#include "motor.h"
#include "4B_LCD.h"
#include "kernel.h"

uint8_t stop_path_follow; // stop flag

uint16_t Line_L;
uint16_t Line_M;
uint16_t Line_R;

uint16_t left_speed = 65;
uint16_t right_speed = 65;

uint16_t last_L;
uint16_t last_R;

void path_follow(void *arg)
{
    motion_Forward();

    while(!stop_path_follow)
    {
        // get ADC value
        Line_L = get_adc_L_avg();
        Line_M = get_adc_M_avg();
        Line_R = get_adc_R_avg();

        LCD_Set_Cursor(1, 0);
        putsi(Line_L, 3);
        LCD_Set_Cursor(1, 4);
        putsi(Line_M, 3);
        LCD_Set_Cursor(1, 8);
        putsi(Line_R, 3);

        // detect and move
        if(Line_L < 700)
        {
            motion_Turn_Left();
        }
        else if(Line_R < 700)
        {
            motion_Turn_Right();
        }
        else
        {
            motion_Forward();
        }
    }

    motion_Stop();

    return;

}