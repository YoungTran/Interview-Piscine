#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
    if (value != 0)
		parkingRow |= (1 << pos);
	else
		parkingRow &= ~(1 << pos);
	return (parkingRow);
}