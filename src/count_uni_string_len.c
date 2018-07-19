#include "../headers/ft_printf.h"

int 			count_uni_string_len(unsigned int **arr)
{
	unsigned int *box;
	char 		byte;
	int 		len;
	int 		i;

	box = arr[0];
	len = 0;
	while (*(*arr))
	{
		while (((*(*arr)) & 0xFF000000) == 0)
			(*(*arr)) = (*(*arr)) << 8;
		i = 0;
		while (i < 4)
		{
			byte = (char)((*(*arr)));
			if (byte)
				len++;
			(*(*arr)) = (*(*arr)) >> 8;
			i++;
		}
		(*arr)++;
	}
	*arr = box;
	return (len);
}