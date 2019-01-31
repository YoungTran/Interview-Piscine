#include "header.h"

int			leftmostCar(unsigned int parkingRow)
{
	int		ret;

	ret = -1;
	if (parkingRow != 0)
	{
		for (ret = 0; parkingRow != 1; ret += 1)
			parkingRow >>= 1;
	}
	return (ret);
}