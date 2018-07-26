#include "../headers/ft_printf.h"
#define START ***s
#define END *end
#define SUBSTR (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z' || *s == '*')
#define SIZES(p) (p == 'h' || p == 'l' || p == 'j' || p == 'z')

int 		find_pair(char *s, char c)
{
	int 	flag;

	flag = 0;
	while (SUBSTR)
	{
		if (*s == c && *(s + 1) == c)
		{
			flag = 1;
			*s = '*';
			*(s + 1) = '*';
		}
		s++;
	}
	return (flag);
}





int			find_char(char *s, char c)
{
	int 	flag;

	flag = 0;
	while (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z' || *s == '*')
//    while ()
	{
		if (*s == c)
		{
			flag = 1;
			*s = '*';
		}
		s++;
	}
	return (flag);
}

int 		find_sizes(char *s, t_p *p)
{
	if (find_char(s, 'z'))
		p->size = 'z';
	else if (find_char(s, 'j'))
		p->size = 'j';
	else if (find_pair(s, 'l'))
		p->size = 'L';
	else if (find_char(s, 'l'))
		p->size = 'l';
	else
	{
		find_pair(s, 'h');
		if (find_char(s, 'h'))
			p->size = 'h';
		else
			p->size = 'H';
	}
	return (0);
}


int

read_size(char ***s, t_p *p)
{
    char 	*end;
    size_t	len;

    p->size = 0;
    len = 0;


    if ((***s == 'h' || ***s == 'l' || ***s == 'j' || ***s == 'z'))
    {
        end = **s;
        while (SIZES(END))
        {
            len++;
            end++;
        }
        end = ft_strsub(**s, 0, len);
        find_sizes(end, p);
        while (SIZES(START))
            (**s)++;
        free(end);
    }
    return (0);
}