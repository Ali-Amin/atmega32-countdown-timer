#ifndef DIO_H_
#define DIO_H_

//defining the port numbers
#define PORTA 1
#define PORTB 2
#define PORTC 3
#define PORTD 4


#define HIGH 1
#define LOW 0
// defining the port direction
#define PORTDIR_OUTPUT ((u8)0xFF)
#define PORTDIR_INPUT ((u8)0x00)

//defining the pins
#define PIN0	((u8)0x00)
#define PIN1 	((u8)0x01)
#define PIN2 	((u8)0x02)
#define PIN3 	((u8)0x03)
#define PIN4 	((u8)0x04)
#define PIN5 	((u8)0x05)
#define PIN6 	((u8)0x06)
#define PIN7 	((u8)0x07)



void DIO_vidSetPortDir (u8 PortName,u8 PortDir);

void DIO_vidSetPinDir (u8 u8PortName,u8 u8PinNo,u8 u8Dir);

void DIO_vidSetPinVal (u8 u8PortName,u8 u8PinNo,u8 u8PinVal);


void DIO_vidSetPortVal (u8 u8PortName, u8 u8PortVal);

u8 DIO_u8GetPortVal(u8 u8PortName);

u8 DIO_u8GetPinVal(u8 u8PortName, u8 u8PinNo);
#endif

