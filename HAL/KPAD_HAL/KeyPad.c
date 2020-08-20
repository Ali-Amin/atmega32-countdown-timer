#include "../../MCAL/types.h"
#include "../../MCAL/DIO.h"
#include "util/delay.h"

#include "../KPAD_HAL/KeyPad_Cfg.h"

u8 Columns[4] = {C1PIN, C2PIN, C3PIN, C4PIN};
u8 Rows[4] = {R1PIN, R2PIN, R3PIN, R4PIN};

void KPAD_vidInit(void)
{
	u8 u8ColumnNo = 0;
	//SET COLUMNS TO OUTPUT
	for (u8ColumnNo = 0; u8ColumnNo < 4; u8ColumnNo++)
	{
		DIO_vidSetPinDir(C_port, Columns[u8ColumnNo], PORTDIR_OUTPUT);
	}

	u8 u8RowNo = 0;
	for (u8RowNo = 0; u8RowNo < 4; u8RowNo++)
	{
		/*Set Rows as input*/
		DIO_vidSetPinDir(R_port, Rows[u8RowNo], PORTDIR_INPUT);
		/*Activate pull-up resistors */
		DIO_vidSetPinVal(R_port, Rows[u8RowNo], HIGH);
	}
}

u8 KPAD_u8GetKeyVal(void)
{
	u8 RowNo, ColNo;
	u8 RetValue = 0;
	for (ColNo = 0; ColNo < 4; ColNo++)
	{
		DIO_vidSetPinVal(C_port, Columns[ColNo], LOW);
		for (RowNo = 0; RowNo < 4; RowNo++)
		{
			if (DIO_u8GetPinVal(R_port, Rows[RowNo]) == LOW)
			{
				RetValue = ((RowNo * 4) + ColNo + 1);
				_delay_ms(200);
			}
		}

		DIO_vidSetPinVal(R_port, Columns[ColNo], HIGH);
	}
	return RetValue;
}
