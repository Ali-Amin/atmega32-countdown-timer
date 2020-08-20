
#include "../../MCAL/types.h"

#define F_CPU 12000000
#include "../../MCAL/DIO.h"
#include "util/delay.h"
#include "../LCD_HAL/LCD.h"
#include "../LCD_HAL/LCD_LOC.h"
#include "../LCD_HAL/LCD_CFG.h"

void LCD_vidInit()
{
	/* Sets the pin Directions for RW, RS, Enable, and DataPort */
	DIO_vidSetPinDir(LCD_RWPort, LCD_RWPin, PORTDIR_OUTPUT);
	DIO_vidSetPinDir(LCD_RSPort, LCD_RSPin, PORTDIR_OUTPUT);
	DIO_vidSetPinDir(LCD_EnablePort, LCD_EnablePin, PORTDIR_OUTPUT);
	DIO_vidSetPortDir(LCD_DataPort, PORTDIR_OUTPUT);

	_delay_ms(50);
	LOC_vidSendCMD(0b00111100); // Set Function
	_delay_ms(2);

	LOC_vidSendCMD(0b00001100); // Display ON/OFF Control
	_delay_ms(2);

	LOC_vidSendCMD(0b00000001); // Clear Display
	_delay_ms(5);

	LOC_vidSendCMD(0b00000110); // Entry Mode Set
}

void LOC_vidSendCMD(u8 u8CMD)
{
	/*Set RW to 0 (write mode)*/
	DIO_vidSetPinVal(LCD_RWPort, LCD_RWPin, 0);

	/*Set RS to 0 (write to IR)*/
	DIO_vidSetPinVal(LCD_RSPort, LCD_RSPin, 0);

	/*Set command*/
	DIO_vidSetPortVal(LCD_DataPort, u8CMD);

	LOC_vidEnablePulse();
}

/*Set falling register*/
void LOC_vidEnablePulse()
{
	DIO_vidSetPinVal(LCD_EnablePort, LCD_EnablePin, 1);
	_delay_ms(2);
	DIO_vidSetPinVal(LCD_EnablePort, LCD_EnablePin, 0);
}

void LCD_vidWriteChar(u8 u8Char)
{
	/*Set RW to 0 (write mode)*/
	DIO_vidSetPinVal(LCD_RWPort, LCD_RWPin, 0);

	/*Set RS to 1 (write to DR)*/
	DIO_vidSetPinVal(LCD_RSPort, LCD_RSPin, 1);

	/*Set command*/
	DIO_vidSetPortVal(LCD_DataPort, u8Char);

	LOC_vidEnablePulse();
}

/*Takes array and size of array and prints it on the LCD*/
void LCD_vidWriteString(u8 u8String[], u8 u8Size)
{
	u8 u8CharIndex = 0;
	for (u8CharIndex = 0; u8CharIndex < u8Size; u8CharIndex++)
	{
		LCD_vidWriteChar(u8String[u8CharIndex]);
	}
}
