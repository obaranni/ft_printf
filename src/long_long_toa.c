#include "../headers/ft_printf.h"

static char		*ft_longlongmin(void)
{
    char		*min;
//    char		*str;
    char        str[] =   "-9223372036854775808";

    min = (char*)malloc(sizeof(char) * 21);
//    str = "-9223372036854775808";
    min = ft_strcpy(min, str);
    return (min);
}

static char		*ft_zero(ssize_t n)
{
    char		*zer;

    zer = (char*)malloc(sizeof(char) * 2);
    zer[0] = (char)(n + 48);
    zer[1] = '\0';
    return (zer);
}

static char		*ft_scan(size_t len, ssize_t n, int flag)
{
    char		*num;

    num = (char *)malloc(sizeof(char) * (len + 3000)); //sigabort at 19

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


char			*long_long_toa(ssize_t n)
{
    int			flag;
    int			len;
    long long   mem;

    if (n == LONG_LONG_MIN)
        return (ft_longlongmin());
    if (n == 0)
        return (ft_zero(n));
    len = 0;
    flag = 0;
    if (n < 0)
    {
        n = n * -1;
        flag = 1;
        len++;
    }
    mem = n;
    while ((mem * 1.0) >= 1)
    {
        mem = mem / 10;
        len++;
    }
    return (ft_scan(1, n, flag));
}