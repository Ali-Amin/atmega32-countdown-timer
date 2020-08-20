#include "types.h"
#include "DIO_LOC.h"
#include "DIO.h"

#include "BIT_MATH.h"

void DIO_vidSetPortDir(u8 PortName, u8 u8PortDir)
{
	switch (PortName)
	{
	case PORTA:
	{
		DDRA_REGISTER = u8PortDir;
	}
	break;

	case PORTB:
	{
		DDRB_REGISTER = u8PortDir;
	}
	break;

	case PORTC:
	{
		DDRC_REGISTER = u8PortDir;
	}
	break;

	case PORTD:
	{
		DDRD_REGISTER = u8PortDir;
	}
	break;
	}
}

void DIO_vidSetPinDir(u8 u8PortName, u8 u8PinNo, u8 u8Dir)
{
	switch (u8PortName)
	{

	case PORTA:
	{
		if (u8Dir == PORTDIR_INPUT)
		{
			clr_bit(DDRA_REGISTER, u8PinNo);
		}
		else if (u8Dir == PORTDIR_OUTPUT)
		{
			set_bit(DDRA_REGISTER, u8PinNo);
		}
	}
	break;

	case PORTB:
	{
		if (u8Dir == PORTDIR_INPUT)
		{
			clr_bit(DDRB_REGISTER, u8PinNo);
		}
		else if (u8Dir == PORTDIR_OUTPUT)
		{
			set_bit(DDRB_REGISTER, u8PinNo);
		}
	}
	break;

	case PORTC:
	{
		if (u8Dir == PORTDIR_INPUT)
		{
			clr_bit(DDRC_REGISTER, u8PinNo);
		}
		else if (u8Dir == PORTDIR_OUTPUT)
		{
			set_bit(DDRC_REGISTER, u8PinNo);
		}
	}
	break;

	case PORTD:
	{
		if (u8Dir == PORTDIR_INPUT)
		{
			clr_bit(DDRD_REGISTER, u8PinNo);
		}
		else if (u8Dir == PORTDIR_OUTPUT)
		{
			set_bit(DDRD_REGISTER, u8PinNo);
		}
	}
	break;
	}
}

void DIO_vidSetPinVal(u8 u8PortName, u8 u8PinNo, u8 u8PinVal)
{

	switch (u8PortName)
	{

	case PORTA:
	{
		if (u8PinVal == HIGH)
		{
			set_bit(PORTA_REGISTER, u8PinNo);
		}
		else if (u8PinVal == LOW)
		{
			clr_bit(PORTA_REGISTER, u8PinNo);
		}
	}
	break;

	case PORTB:
	{
		if (u8PinVal == HIGH)
		{
			set_bit(PORTB_REGISTER, u8PinNo);
		}
		else if (u8PinVal == LOW)
		{
			clr_bit(PORTB_REGISTER, u8PinNo);
		}
	}
	break;

	case PORTC:
	{
		if (u8PinVal == HIGH)
		{
			set_bit(PORTC_REGISTER, u8PinNo);
		}
		else if (u8PinVal == LOW)
		{
			clr_bit(PORTC_REGISTER, u8PinNo);
		}
	}
	break;

	case PORTD:
	{
		if (u8PinVal == HIGH)
		{
			set_bit(PORTD_REGISTER, u8PinNo);
		}
		else if (u8PinVal == LOW)
		{
			clr_bit(PORTD_REGISTER, u8PinNo);
		}
	}
	break;
	}
}

void DIO_vidSetPortVal(u8 u8PortName, u8 u8PortVal)
{
	switch (u8PortName)
	{
	case PORTA:
	{
		PORTA_REGISTER = u8PortVal;
	}
	break;

	case PORTB:
	{
		PORTB_REGISTER = u8PortVal;
	}
	break;

	case PORTC:
	{
		PORTC_REGISTER = u8PortVal;
	}
	break;

	case PORTD:
	{
		PORTD_REGISTER = u8PortVal;
	}
	break;
	}
}

u8 DIO_u8GetPortVal(u8 u8PortName)
{
	switch (u8PortName)
	{
	case PORTA:
		return PORTA_REGISTER;
	case PORTB:
		return PORTB_REGISTER;
	case PORTC:
		return PORTC_REGISTER;
	case PORTD:
		return PORTD_REGISTER;
	}
	return 0;
}

u8 DIO_u8GetPinVal(u8 u8PortName, u8 u8PinNo)
{
	switch (u8PortName)
	{
	case PORTA:
		return get_bit(PINA_REGISTER, u8PinNo);

	case PORTB:
		return get_bit(PINB_REGISTER, u8PinNo);

	case PORTC:
		return get_bit(PINC_REGISTER, u8PinNo);

	case PORTD:
		return get_bit(PIND_REGISTER, u8PinNo);
	}
	return 0;
}
