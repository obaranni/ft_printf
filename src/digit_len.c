#include "../headers/ft_printf.h"

int 				init_sign(t_p *p)
{
	int 			flag;

	flag = 0;
	if (p->size == 'z')
		(size_t)p->data < 0 ? flag = 1 : 0;
	else if (p->size == 'j')
		(intmax_t)p->data < 0 ? flag = 1 : 0;
	else if (p->size == 'L')
		(long long int)p->data < 0 ? flag = 1 : 0;
	else if (p->size == 'l')
		(long)p->data < 0 ? flag = 1 : 0;
	else if (p->size == 'h')
		(short)p->data < 0 ? flag = 1 : 0;
	else if (p->size == 'H')
		(char)p->data < 0 ? flag = 1 : 0;
	else
		(int)p->data < 0 ? flag = 1 : 0;
	p->pos = 1;
	if (flag)
		p->pos = 0;
	return(0);
}

int 			digit_len(long long digit)
{
	int 	i;

	i = 0;
	if (digit == 0)
		return (1);
	while (digit > 0 || digit < 0)
	{
		digit = digit / 10;
		i++;
	}
	return (i);
}

int 		find_digit_len(t_p *p)
{
	if (p->size == 'z')
		p->data_len = digit_len((size_t*)p->data);
	else if (p->size == 'j')
		p->data_len = digit_len((intmax_t*)p->data);
 	else if (p->size == 'L')
		p->data_len = digit_len((long long*)p->data);
	else if (p->size == 'l')
		p->data_len = digit_len(((long)p->data));
	else if (p->size == 'h')
		p->data_len = digit_len(((short)p->data));
	else if (p->size == 'H')
		p->data_len = digit_len(((char)p->data));
	else
		p->data_len = digit_len(((int)p->data));
	return (0);
}