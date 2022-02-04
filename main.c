/*
 * ADC.c
 *
 * Created: 25/11/2021 05:45:08 ص
 * Author : ahmed essam
 */ 
#include <avr/io.h>
#include "lcd.h"
#include "adc.h"
#include "Gas.h"
#include <util/delay.h>
#include <stdlib.h>




int main(void)
{
	char buffer[15];
	int Rdata;
	float ro;
	lcd_init();
	adc_init();
	lcd_clear();
	lcd_send_command(LCD_CMD_DISPLAY_NO_CURSOR);
	lcd_goto_xy(0,0);
	lcd_write_word("Calibrating...");
	ro = SensorCalibration();                       //Please make sure the sensor is in clean air
	Rdata = (int)ro;
	itoa(Rdata,buffer,10);	/* Integer to string conversion */
	//when you perform the calibration
	lcd_clear();
	lcd_goto_xy(0,0);
	lcd_write_word("Calibration is done...");
	lcd_goto_xy(1,0);
	lcd_write_word(buffer);
	_delay_ms(100);
	lcd_clear();

    while (1) 
    {
		lcd_goto_xy(0,0);
		lcd_write_word("LPG:");
		lcd_goto_xy(1,0);
		
		Rdata = GetGasPercentage(ReadSensor()/ro,0);
		itoa(Rdata,buffer,10);	/* Integer to string conversion */
		
		lcd_write_word(buffer);
		lcd_goto_xy(0,6);
		
		lcd_write_word("SMOKE:");
		lcd_goto_xy(1,6);
		
		Rdata = GetGasPercentage(ReadSensor()/ro,1);
		itoa(Rdata,buffer,10);	/* Integer to string conversion */
		
		lcd_write_word(buffer);
		_delay_ms(500);
    }
}

