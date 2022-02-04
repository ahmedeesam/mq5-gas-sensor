/*
 * adc.h
 *
 * Created: 25/11/2021 05:48:27 ص
 *  Author: ahmed essam
 */ 


#ifndef ADC_H_
#define ADC_H_

#define F_CPU 8000000UL // 8 MHz clock speed
#include <avr/io.h>
#include <util/delay.h>

void  adc_init();
int adc_read();



#endif /* ADC_H_ */