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




int				print_uni_string(t_p *p)
{
	int 		i;
	int 		len;

    if (!p->data_uint)
    {
        ft_putstr("(null)");
        return ((int) ft_strlen("(null)"));
    }
    else
    {
		i = 0;
		dup_arr(&p->data_uint, &p->data_uint_copy);
		while (p->data_uint_copy[i])
		{
			masks(&p->data_uint_copy[i]);
			printing_unicode(&p->data_uint_copy[i++]);
		}
		len = count_uni_string_len(&p->data_uint_copy);
		free(p->data_uint_copy);
        return (len);
    }
}