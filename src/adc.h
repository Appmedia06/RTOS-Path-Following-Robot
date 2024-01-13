#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>





#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// ADC ch
#define ADC_L   1
#define ADC_M   2
#define ADC_R   3
#define ADC_BAT 0

#define ADC_CH_CNT 4

#define ADC_L_BUFFER_SIZE 1
#define ADC_M_BUFFER_SIZE 1
#define ADC_R_BUFFER_SIZE 1
#define ADC_BAT_BUFFER_SIZE 8

extern volatile uint8_t ADC_L_buffer_index ;
extern volatile uint8_t ADC_M_buffer_index;
extern volatile uint8_t ADC_R_buffer_index;
extern volatile uint8_t ADC_BAT_buffer_index;

extern volatile uint16_t ADC_L_buffer[];
extern volatile uint16_t ADC_M_buffer[];
extern volatile uint16_t ADC_R_buffer[];
extern volatile uint16_t ADC_BAT_buffer[];


extern volatile uint8_t ADC_now_ch;

void ADC_Init();

uint16_t get_ADC_L_avg(void);
uint16_t get_ADC_M_avg(void);
uint16_t get_ADC_R_avg(void);
uint16_t adc_BAT_get_avg();
uint16_t adc_BAT_to_volt(uint16_t adc_val);


#endif /* ADC_H_ */