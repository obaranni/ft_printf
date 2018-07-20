#include "../headers/ft_printf.h"

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
	while ((*arr1)[i] && i < len)
	{
		(*arr2)[i] = (*arr1)[i];
		i++;
	}
}
