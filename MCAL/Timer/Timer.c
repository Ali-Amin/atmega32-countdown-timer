#include "../types.h"
#include "../DIO.h"
#include "Timer.h"
#include "Timer_LOC.h"
#include "../BIT_MATH.h"
#include "avr/interrupt.h"

void TMR_vidInit()
{

	/* Sets the clock with prescalar value 1024 */
	set_bit(TCCR0_REGISTER, 0);
	set_bit(TCCR0_REGISTER, 2);

	/* Initializes TIMER REGISTER */
	TIMER_REGISTER = 0;

	/* Enables Timer Interrupt*/
	set_bit(TIMSK_REGISTER, 0);

	/*Enable Global Interrupt*/
	set_bit(SREG, 7);
}
