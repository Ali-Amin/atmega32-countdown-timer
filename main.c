#include "MCAL/types.h"
#include "MCAL/DIO.h"
#include "HAL/KPAD_HAL/KeyPad.h"
#include "HAL/LCD_HAL/LCD.h"
#include "MCAL/Timer/Timer.h"
#include "avr/interrupt.h"

#define CPU_F 8000000

u8 LOC_u8RecordPress(void);
void LOC_initCountdownTimer(void);
void LOC_vidHandleTimerInterrupt(void);
void LOC_vidBeginCountdown(void);

u8 u8TimerCount;   // How many times the timer completed counting
u16 u16InputCount; // The number of times the user pressed on the keypad
u8 isCountingDown; // true when counting down
u8 LCDText[8];     // Text that is displayed on the LCD

int main(void)
{
    /*INIT*/
    LOC_initCountdownTimer();

    while (1)
    {

        /* Take input from user (KEYPAD)*/
        u8 u8Input = LOC_u8RecordPress();
        if (isCountingDown == '1' && u8Input != '*')
        {
            continue;
        }
        if (u8Input == '*') // Reset Countdown Timer
        {
            LOC_initCountdownTimer();
        }

        else if (u8Input == '#') // Begin Counting Down
        {
            LOC_vidBeginCountdown();
        }

        else
        {
            if (u16InputCount < 8) // Prevents adding more numbers than the max (6 numbers + 2 colons)
            {
                LOC_vidHandleInput(u8Input);
            }
        }
    }
    return 0;
}

/* Handles input from keypad and how to display it on LCD*/
void LOC_vidHandleInput(u8 u8Number)
{

    if (u16InputCount == 2 || u16InputCount == 5)
    {
        LCDText[7 - u16InputCount - 1] = u8Number;
        u16InputCount++;
    }
    else
    {
        LCDText[7 - u16InputCount] = u8Number;
    }

    LCD_vidInit();
    LCD_vidWriteString(LCDText, 8);

    u16InputCount++;
}

/* Returns the value pressed on the keypad */
u8 LOC_u8RecordPress(void)
{
    while (1)
    {
        u8 u8PressVal = KPAD_u8GetKeyVal();

        switch (u8PressVal)
        {
        case 1:
            return '1';
            break;
        case 2:
            return '2';
            break;
        case 3:
            return '3';
            break;
        case 4:
            break;
        case 5:
            return '4';
            break;
        case 6:
            return '5';
            break;
        case 7:
            return '6';
            break;
        case 8:
            break;
        case 9:
            return '7';
            break;
        case 10:
            return '8';
            break;
        case 11:
            return '9';
            break;
        case 12:
            break;
        case 13:
            return '*';
            break;
        case 14:
            return '0';
            break;
        case 15:
            return '#';
            break;
        case 16:
            break;
        default:
            break;
        }
    }
}

/* Initialization Function for the entire program */
void LOC_initCountdownTimer(void)
{
    /* INITIALIZE VARIABLES */
    u8TimerCount = 0;
    u16InputCount = 0;
    isCountingDown = '0';

    /* INITIALIZE LCD */
    LCDText[0] = '-';
    LCDText[1] = '-';
    LCDText[2] = ':';
    LCDText[3] = '-';
    LCDText[4] = '-';
    LCDText[5] = ':';
    LCDText[6] = '-';
    LCDText[7] = '-';
    LCD_vidInit();
    LCD_vidWriteString(LCDText, 8);

    /* INITIALIZE KEYPAD */
    KPAD_vidInit();

    /* INITIALIZE TIMER*/
    TMR_vidInit();
}

/* Begin counting down */
void LOC_vidBeginCountdown(void)
{
    u16 index;
    u16 length = sizeof(LCDText) / sizeof(u8);

    for (index = 0; index < length; index++)
    {
        if (LCDText[index] == '-')
        {
            LCDText[index] = '0';
        }
    }

    isCountingDown = '1';
    u8TimerCount = 0;
}

/* Decreases countdown timer by 1 sec every time the timer ISR runs */
void LOC_vidHandleTimerInterrupt(void)
{

    if (LCDText[7] == '0') //first second = 0
    {
        if (LCDText[6] == '0') //second second = 0
        {
            if (LCDText[4] == '0') //first minute = 0
            {
                if (LCDText[3] == '0') //second minute = 0
                {
                    if (LCDText[1] == '0') //first hour = 0
                    {
                        if (LCDText[0] == '0') //second hour = 0
                        {
                        }
                        else
                        {
                            LCDText[0]--;
                            LCDText[1] = '9';
                            LCDText[3] = '5';
                            LCDText[4] = '9';
                            LCDText[6] = '5';
                            LCDText[7] = '9';
                        }
                    }
                    else
                    {
                        LCDText[1]--;
                        LCDText[3] = '5';
                        LCDText[4] = '9';
                        LCDText[6] = '5';
                        LCDText[7] = '9';
                    }
                }
                else
                {
                    LCDText[3]--;
                    LCDText[4] = '9';
                    LCDText[6] = '5';
                    LCDText[7] = '9';
                }
            }
            else
            {
                LCDText[4]--;
                LCDText[6] = '5';
                LCDText[7] = '9';
            }
        }
        else
        {
            LCDText[6]--;
            LCDText[7] = '9';
        }
    }
    else
    {
        LCDText[7]--;
    }

    LCD_vidInit();
    LCD_vidWriteString(LCDText, 8);
}

/* Timer ISR*/
ISR(TIMER0_OVF_vect)
{

    if (u8TimerCount == 29 && isCountingDown == '1')
    {
        LOC_vidHandleTimerInterrupt();
        u8TimerCount = 0;
    }
    if (isCountingDown == '1')
    {

        u8TimerCount++;
    }

    TIMER_REGISTER = 0;
}
