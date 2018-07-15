#include "../headers/ft_printf.h"

char        *any_unsigned_dec_to_str(size_t nb)
{
    return (ft_itoa_base(nb, 10));
}