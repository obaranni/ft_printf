
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

void		is_local(t_p *p)
{
	char 	*s;

	s = setlocale( LC_ALL, NULL) ;
//	if (*s == 'C')
//		p->local = 0;
//	else
		p->local = 1;
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
	is_local(&p);
	while (**box)
	{
		if (**box == '%')
		{
            s++;
			if (queue(&box, &p))
			{
                fetch_data(&l, &p);
                b += choose_datatype_handler(&p);
			}
			else if (**box)
			{
				write(1, s, 1);
				b++;
			}
        }
		else
		{
			write(1, s, 1);
			b++;
		}
        if (*s)
		    s++;
	}
    va_end(l);
	return (b); //bytes
}