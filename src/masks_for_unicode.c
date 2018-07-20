#include "../headers/ft_printf.h"

void           masks(unsigned int *u)
{
	unsigned int a;
	unsigned int b;

	if (*u <= 0x7F)
		*u = (*u & 0x7F);
	else if (*u <= 0x7FF)
	{
		a = (*u & 0x3F) | ((*u & 0xFFFFC0) << 2) | 0x80;
		b = a & 0x1FFF;
		*u = (((a & 0xFE000) << 3) | 0xC000) | b;
	}
	else if (*u <= 0xFFFF)
	{
		a = (*u & 0x3F) | ((*u & 0xFFFFC0) << 2) | 0x80;
		b = ((a & 0xFFFFC000) << 2) | (a & 0x3FFF) | 0x8000;
		*u = ((b & 0xF000000) << 2) | (b & 0x3FFFFF) | 0xE00000;
	}
	else if (*u <= 0x1FFFFF)
	{
		a = (*u & 0x3F) | ((*u & 0xFFFFC0) << 2) | 0x80;
		b = ((a & 0xFFFFC000) << 2) | (a & 0x3FFF) | 0x8000;
		a = ((b & 0xFFC00000) << 2) | (b & 0x3FFFFF) | 0x800000;
		*u = (a & 0x7FFFFFF) | 0xF0000000;
	}
}