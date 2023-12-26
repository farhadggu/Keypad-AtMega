/*
 * keypad.c
 *
 * Created: 26-04-2020 15:22:06
 * Author : Embedotronics
 */ 
#include <avr/io.h>
#include <util/delay.h>



unsigned char k[4][3]={{0xF9,0xA4,0xB0},{0x99,0x92,0x82},{0xF8,0x80,0x90},{0x88,0xc0,0xc0}};

int main()
{
	unsigned char c,r;
	DDRD = 0XFF;
	DDRC=0xf0;
	PORTC=0xff;
	while(1)
	{
		
		do
		{
			PORTC&=0x0f;
			r=PINC&0x0f;
		} while(r!=0x0f);
	

		do
		{
			_delay_ms(20);
			r=PINC&0x0f;
		}	  while(r==0x0f);
		
		while(1)
		{
			PORTC=0xef;     //0b11101111
			r=PINC&0x0f;
			if(r!=0x0f)
			{
				c=0;
				break;
			}
			PORTC=0xdf;     //0b11011111
			r=PINC&0x0f;
			if(r!=0x0f)
			{
				c=1;
				break;
			}
			PORTC=0xbf;     //0b10111111
			r=PINC&0x0f;
			if(r!=0x0f)
			{
				c=2;
				break;
			}

		}

		if(r==0x0e)
		PORTD=k[0][c];
		else if(r==0x0d)
		PORTD=k[1][c];
		else if(r==0x0b)
		PORTD=k[2][c];
		else
		PORTD=k[3][c];
	}
	return 0;
}