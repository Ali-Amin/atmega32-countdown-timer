
#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_

#define TCCR0_REGISTER *((volatile u8 *)0x53)
#define TIMER_REGISTER *((volatile u8 *)0x52) //TCNT REGISTER
#define OCR0_REGISTER *((volatile u8 *)0x5C)
#define TIMSK_REGISTER *((volatile u8 *)0x59)

//#define INT0_vect _vector_1
//#define TIMER0OVF_vect _vector_11

//#define ISR ()
// void TIMER0OVF_vect (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
// void TIMER0OVF_vect (void)

void TMR_vidInit();

#endif /* TIMER_TIMER_H_ */
