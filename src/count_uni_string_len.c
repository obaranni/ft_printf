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

int 			count_uni_string_len(unsigned int **arr)
{
	unsigned int *box;
	int 		len;

	box = arr[0];

	len = 0;
	while (*(*arr))
	{
		if (*(*arr) <= 0x7F)
			len += 1;
		else if (*(*arr) <= 0x7FF)
			len += 2;
		else if (*(*arr) <= 0xFFFF)
			len += 3;
		else if (*(*arr) <= 0x1FFFFF)
			len += 4;
		(*arr)++;
	}
	*arr = box;
	return (len);
}