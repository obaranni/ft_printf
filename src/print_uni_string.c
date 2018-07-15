#include "../headers/ft_printf.h"

/*
 * 00000000 -- 0000007F: 	0xxxxxxx
 * 00000080 -- 000007FF: 	110xxxxx 10xxxxxx
 * 00000800 -- 0000FFFF: 	1110xxxx 10xxxxxx 10xxxxxx
 * 00010000 -- 001FFFFF: 	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 */

void           masks(t_p *p)
{
    char       *bites;

    bites = ft_itoa_base((size_t)p->data_uint, 2);

    int i = 0;
    while (p->data_uint[i])
    {
        int j = 0;
        printf("%s\n", bites);
        while (bites[j])
        {
            printf("%c", bites[j]);
            if (j % 4 == 0 )//&& j != 0)
                printf(" ");
            j++;
        }
        i++;
    }
    printf("\n");
}

int            uni_string(t_p *p) {
    int i;
    i = 0;


    if (!p->data_uint)
    {
        ft_putstr("(null)");
        return ((int) ft_strlen("(null)"));
    }
    else
    {
        write(1, "\n", 1);
        masks(p);
        while (p->data_uint[i])
        {
            ft_putnbr(p->data_uint[i]);
            i++;
        }
        write(1, "\n", 1);

//        ft_putstr((char*)p->data_uint);
        return ((int) ft_strlen((char*)p->data_uint));
    }
}