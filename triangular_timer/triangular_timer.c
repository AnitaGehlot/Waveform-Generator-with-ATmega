/* port_test6.c
 * This program first increases the ON period of pin 0 of port B and then decreases it.
 * Compare with port_test5.c in which the ON period increases from 0% to 100% slowly but
 * jumps from 100% to 0% and then rises again.
 */

#include <avr/io.h> //standard include for ATMega16
#define sbi(x,y) x |= _BV(y) //set bit
#define cbi(x,y) x &= ~(_BV(y)) //clear bit
#define tbi(x,y) x ^= _BV(y) //toggle bit
#define is_high(x,y) ((x & _BV(y)) == _BV(y))


int main(void)
{
	unsigned char i,j;
	unsigned int k;
	DDRB=0xff; //PORTB as OUTPUT
	PORTB=0x00;
	DDRD=0x00;//PORTD as INPUT
	PORTD=0xff;

	while(1==1) //Infinite loop
	{
		for(j=0;j<100;j++)
		{
			for(k=0;k<255;k++)
			{
				for(i=0;i<100;i++)
				{
					if(i<j) sbi(PORTB,PB0);
					else cbi(PORTB,PB0);

				}
			}
		}

		for(j=0;j<100;j++)
		{
			for(k=0;k<255;k++)
			{
				for(i=100;i>0;i--)
				{
					if(i>j) sbi(PORTB,PB0);
					else cbi(PORTB,PB0);

				}
			}
		}
	}
	return 0;

}
