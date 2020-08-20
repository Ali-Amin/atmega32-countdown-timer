#ifndef BitMath_h_
#define	BitMath_h_



#define clr_bit(reg,no) reg &= ~(1<<no)
#define set_bit(reg,no) reg|=(1<<no)
#define get_bit(reg,no) (reg&(1<<no))?1:0


#endif

