/*
 * Car Door Light (using swtiches).c
 *
 * Created: 6/02/2020 2:17:00 PM
 * Author : bulle
 */ 


#define F_CPU 8000000UL // Clock SpeedThis is a macro that will be used by the compiler to calculate delay loops, and states it to be 8MHz, without this line the program defaults to some other value (1000000) and all the timing would be wrong.
#include <util/delay.h> // included to use delay function
#include <avr/io.h> // include the chip



int main(void)
{
  DDRC=0xFF; // Setting PORTC as outputs(LED)
  DDRA =0x00;// Setting PORTA as inputs (Switches)

PORTC-0x00;// initial Value turned off
	
#define CARDOOR_OPEN PORTC=0x14;

#define ALLDOORSCLOSED PORTC=0x00;
 
#define DOOR1 PINA&(1<<7) // Define DOOR1 as testing bit 7 however don t need to put semicolon
#define DOOR2 PINA&(1<<6)//  Define DOOR2 as testing bit 6 as the switches are connected on A6 

    while (1) 
    {
		if((DOOR1) || (DOOR2)) // checking for bit 7 and 6 and testing it if its high(1) then 8seg display should be 14 
		{
			_delay_ms(100);
			CARDOOR_OPEN;
		}
		
		else 
		{
			ALLDOORSCLOSED;
		}
		

    }
}
/* Ways to test PINS 
To test if a bit is on (logical 1), the two following statements can be used. 
These functions perform a logical AND with both the PIN register and the bit 
(represented as an 8-bit number).
 If the result is zero, the if statement will not be executed because 
 if statements only execute when the condition is non-zero. 


if ( PINB & (0b00000001))
or
if ( PINB & (1 << n)) where n = bit under test (0 - 7)
Testing for a logical 0 is easily done by using the negation operator before the main test (!)

if ( !(PINB & (0b00000001)) )
or
if ( !(PINB & (1 << n)) ) where n = bit under test (0 – 7)
*/ 


