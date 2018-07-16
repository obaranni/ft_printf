#include "../headers/ft_printf.h"

/*
 * 00000000 -- 0000007F: 	0xxxxxxx
 * 00000080 -- 000007FF: 	110x xxxx  10xx xxxx
 * 00000800 -- 0000FFFF: 	1110 xxxx  10xx xxxx  10xx xxxx
 * 00010000 -- 001FFFFF: 	1111 0xxx  10xx xxxx  10xx xxxx  10xx xxxx
 *
 * Cutting
 *
 * 111100110101010111101011101
 * 000000000000011111111111000
 * &
 * 000000000000010111101011000
 *
 * Adding mask part
 * 000000000000010111101011000
 * 000000000110000000000000000
 * |
 * 000000000110010111101011000
 */

void 			dup_arr(unsigned int **arr1, unsigned int **arr2)
{
	int			i;
	int 		len;

	i = 0;
	len = 0;
	while ((*arr1)[i++])
		len++;
	*arr2 = (unsigned int*)malloc(sizeof(unsigned int) * len + 1);
	(*arr2)[len] = 0;
	i = 0;
	while ((*arr1)[i])
	{
		(*arr2)[i] = (*arr1)[i];
		i++;
	}
}

void			print_binary(unsigned int digit, int bytes)
{
	char        *bites;
    int         j;
    int         t;
	int			len;

    bites = ft_itoa_base((size_t)digit, 2);
    j = 0;
    t = 0;
	len = (int)ft_strlen(bites);
    while (bites[j] || (j == 0 && t < bytes * 8))
    {
    	if (t + len >= bytes * 8 && bites[j])
        	printf("%c", bites[j]);
        else
            printf("0");

        if ((t + 1) % 4 == 0)
            printf(" ");

        if (t + len >= bytes * 8 && bites[j])
            j++;
		t++;
	}
    printf("\n");
	printf("\n");
    free(bites);
}

void           masks(t_p *p)
{
	unsigned int a;
	unsigned int b;
	unsigned int c;

	if (p->data_uint_copy[0] <= 0x7F)
	{
		p->data_uint_copy[0] = (p->data_uint_copy[0] & 0x7F);
	}
	else if (p->data_uint_copy[0] <= 0x7FF)
	{
		print_binary(p->data_uint_copy[0], 4);
		a = (p->data_uint_copy[0] & 0x3F) | 0x80;
		b = (p->data_uint_copy[0] & 0x1F00) | 0xC000;
		p->data_uint_copy[0] = a | b;
		print_binary(p->data_uint_copy[0], 4);
	}
}

int            uni_string(t_p *p) {
    int 		i;

	dup_arr(&p->data_uint, &p->data_uint_copy);
	i = 0;
    if (!p->data_uint)
    {
        ft_putstr("(null)");
        return ((int) ft_strlen("(null)"));
    }
    else
    {
        masks(p);

        ft_putstr((char*)p->data_uint_copy);
        return ((int) ft_strlen((char*)p->data_uint_copy));
    }
}