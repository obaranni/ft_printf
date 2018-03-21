
#include "../headers/ft_printf.h"

int			queue(char ***box, t_p *p)
{
	read_flags(box, p);
	read_width(box, p);
	read_precision(box, p);
	read_size(box, p);
	if (read_conv_letter(box, p))
		return (1);
	else
		return (0);
}

int			ft_printf(char *s, ...)
{
	t_p		p;
	char 	**box;
	va_list l;
	int 	b;

	b = 0;
	box = &s;
	va_start(l, s);
	while (**box)
	{
		if (**box == '%')
		{
			s++;
			if (queue(&box, &p))
			{
				b += fetch_data(&l, &p);
			}
		}
		else
		{
			write(1, s, 1);
			b++;
		}
		s++;
	}
//	printf("\n'0' == %d\n", p.zero);
//	printf("' ' == %d\n", p.space);
//	printf("'#' == %d\n", p.sharp);
//	printf("'+' == %d\n", p.plus);
//	printf("'-' == %d\n", p.minus);
//	printf("'width' == %d\n", p.width);
//	printf("'precision' == %d\n", p.precision);
//	printf("'size' == [%c]\n", p.size);
	return (b); //bytes
}