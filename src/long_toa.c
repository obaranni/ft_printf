#include "../headers/ft_printf.h"

static char		*ft_longmin(void)
{
    char		*min;
    char		*str;

    min = (char*)malloc(sizeof(char) * 7);
    str = "-32768";
    min = ft_strcpy(min, str);
    return (min);
}

static char		*ft_zero(long n)
{
    char		*zer;

    zer = (char*)malloc(sizeof(char) * 2);
    zer[0] = n + 48;
    zer[1] = '\0';
    return (zer);
}

static char		*ft_scan(int len, long n, int flag)
{
    char		*num;

    num = (char*)malloc((sizeof(char) * len) + 1);
    if (num == NULL)
        return (NULL);
    num[len] = '\0';
    while ((len != 0 && flag == 0) || (len != 1 && flag == 1))
    {
        num[len - 1] = (n % 10) + 48;
        n = n / 10;
        len--;
    }
    num[len - 1] = (n % 10) + 48;
    if (flag == 1)
    {
        num[0] = '-';
    }
    return (num);
}

char			*long_toa(long n)
{
    int flag;
    int len;
    int mem;

    if (n == LONG_MIN)
        return (ft_longmin());
    if (n == 0)
        return (ft_zero(n));
    len = 0;
    flag = 0;
    if (n < 0) {
        n = n * -1;
        flag = 1;
        len++;
    }
    mem = n;
    while ((mem * 1.0) >= 1) {
        mem = mem / 10;
        len++;
    }
    return (ft_scan(len, n, flag));
}