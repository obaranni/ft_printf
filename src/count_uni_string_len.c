#include "../headers/ft_printf.h"

//int 			count_uni_string_len(unsigned int **arr)
//{
//	unsigned int *box;
//	char 		byte;
//	int 		len;
//	int 		i;
//
//	box = arr[0];
//	len = 0;
//	while (*(*arr))
//	{
//		while (((*(*arr)) & 0xFF000000) == 0)
//			(*(*arr)) = (*(*arr)) << 8;
//		i = 0;
//		while (i < 4)
//		{
//			byte = (char)((*(*arr)));
//			if (byte)
//				len++;
//			(*(*arr)) = (*(*arr)) >> 8;
//			i++;
//		}
//		(*arr)++;
//	}
//	*arr = box;
//	return (len);
//}

int 			count_uni_char_len(unsigned int c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x1FFFFF)
		return (4);
    return (0);
}

int 			count_uni_string_len(unsigned int **arr)
{
	unsigned int *box;
	int 		len;

	box = arr[0];

	len = 0;
	while (*(*arr))
	{
		len += count_uni_char_len(*(*arr));
		(*arr)++;
	}
	*arr = box;
	return (len);
}