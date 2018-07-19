#include "../headers/ft_printf.h"

void			print_width_str(t_p *p)
{
	int 		arg_len;

	arg_len = p->width;
	while (arg_len > 0)
	{
		if (p->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		arg_len--;
	}
}

int            print_string(t_p *p)
{
	if (!p->data)
	{
		ft_putstr("(null)");
		return ((int) ft_strlen("(null)"));
	}
	else
	{
		int res;
		int i;
		flags_priority(p);
		p->data_len = (int) ft_strlen(p->data);
		if (p->precision > p->data_len)
			res = p->data_len + p->width;
		else if (p->precision && p->precision < p->data_len)
			res = p->precision + p->width;
		else
			res = p->data_len + p->width;

		if (p->width && p->precision && p->data[0])
		{
			p->width -= p->precision;
			res -= p->precision;
			if (p->width < 0)
				p->width = 0;
		}

		p->pos = 1;
		if (p->width && p->data[0] && !p->precision)
		{
			p->width -= 4;
			res -= 4;
		}
		///////////////////////////// width = width - numbOfSpacesInString
		i = 0;
		if (p->minus)
		{
			while ((i < p->precision && p->data[i]) || (p->data[i] && !p->precision))
			{
				write(1, &(p->data[i]), 1);
				i++;
			}
			print_width_str(p);


		}
		else
		{
			print_width_str(p);
			while ((i < p->precision && p->data[i]) || (p->data[i] && !p->precision))
			{
				write(1, &(p->data[i]), 1);
				i++;
			}

		}


		return (res);
	}
}