#include "../../MCAL/types.h"
#ifndef LCD_H_
#define LCD_H_

void LCD_vidInit();
void LCD_vidWriteChar(u8 u8Char);
void LCD_vidWriteString(u8 u8String[], u8 u8Size);
void LCD_vidShiftRight();
void LCD_vidShiftLeft();

#endif /* LCD_H_ */
