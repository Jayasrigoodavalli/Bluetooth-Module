/*
 * GccApplication2.c
 *
 * Created: 16-May-19 11:24:05 AM
 * Author : JAYASREE
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#define LED PORTB
char buffer[10];
void USARTInit(uint16_t ubrr_value)
{
	//set baud rate
	UBRRL=ubrr_value;
	UBRRH=(ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	//Enable the RECEIVER & TRANSMITTER
	UCSRB=(1<<RXEN)|(1<<TXEN);
}
char USARTReadChar()
{
	
	//Wait until a data is available
	while(!(UCSRA&(1<<RXC)))
	{
		
		//Do nothing
	}
	return UDR;
	
}
void USARTWriteChar(char data)
{
   while(!(UCSRA&(1<<UDRE)))
   {
	   //Do nothing
   }	
   UDR=data;
}

int main(void)
{
	USARTInit(77);
	DDRB=0XFF;//PORTB as o/p
	char data;
	LED=0;
	/* Replace with your application code */
    while (1) 
    {
	
		data=USARTReadChar();
		if(data=='1')
		{
			LED|=0XFF;/*Turn ON LED*/
			//USART_SendString("LED_ON");/*send status of LED i.e LED ON
		}
		else if(data=='2')
		{
			LED=0X00;/*Turn OFF LED*/
			//USART_SendString("LED_ON");/*send status of LED i.e LED ON
		}
		//else 
		//USART_SendString("Select Proper Option");/*send message for selecting proper option*/
    } 
	return(0);
}

