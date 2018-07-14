/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:06:05 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/19 13:08:11 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

//#include "../../checker/moulitest_42projects/ft_printf_tests/project.h"

int			main(void) {
    int i = 0;
    char *s;
    while (i++ != 1) {

//        printf("Returned: %d\n", printf("1 Hello \"%2.10d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("1 Hello \"%2.10d\"\n", 89));
//
//        printf("Returned: %d\n", printf("2 Hello \"% 2.10d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("2 Hello \"% 2.10d\"\n", 89));
//
//        printf("Returned: %d\n", printf("2.1 Hello \"% d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("2.1 Hello \"% d\"\n", 89));
//
//        printf("Returned: %d\n", printf("3 Hello \"% -10.3d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("3 Hello \"% -10.3d\"\n", 89));
//
//        printf("Returned: %d\n", printf("4 Hello \"% -10.7d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("4 Hello \"% -10.7d\"\n", 89));
//
//        printf("Returned: %d\n", printf("4.1 Hello \"% -+10.7d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("4.1 Hello \"% -+10.7d\"\n", 89));
//
//        printf("Returned: %d\n", printf("4.2 Hello \"%8.7i\"\n", 80009));
//        printf("Returned: %d\n\n", ft_printf("4.2 Hello \"%8.7i\"\n", 80009));
//
//        printf("Returned: %d\n", printf("5 Hello \"% +-10.7d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("5 Hello \"% +-10.7d\"\n", 89));
//
//        printf("Returned: %d\n", printf("6 Hello \"%+-10.7d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("6 Hello \"%+-10.7d\"\n", 89));
//
//        printf("Returned: %d\n", printf("7 Hello \"%+10.7d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("7 Hello \"%+10.7d\"\n", 89));
//
//        printf("Returned: %d\n", printf("8 Hello \"% +10.7d\"\n", -89));
//        printf("Returned: %d\n\n", ft_printf("8 Hello \"% +10.7d\"\n", -89));
//
//        printf("Returned: %d\n", printf("9 Hello \"% 0+10.3d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("9 Hello \"% 0+10.3d\"\n", 89));
//
//        printf("Returned: %d\n", printf("9.1 Hello \"% 0+10d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("9.1 Hello \"% 0+10d\"\n", 89));
//
//        printf("Returned: %d\n", printf("10 Hello \"% +10.3d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("10 Hello \"% +10.3d\"\n", 89));
//
//        printf("Returned: %d\n", printf("11 Hello \"% -+10.7d\"\n", -89));
//        printf("Returned: %d\n\n", ft_printf("11 Hello \"% -+10.7d\"\n", -89));
//
//        printf("Returned: %d\n", printf("12 Hello \"% 0+11.1d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("12 Hello \"% 0+11.1d\"\n", 89));
//
//        printf("Returned: %d\n", printf("13 Hello \"% 0 9.1d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("13 Hello \"% 0 9.1d\"\n", 89));
//
//        printf("Returned: %d\n", printf("14 Hello \"%- 50.33lld\"\n", LONG_LONG_MIN));
//        printf("Returned: %d\n\n", ft_printf("14 Hello \"%- 50.33lld\"\n", LONG_LONG_MIN));
//
//        printf("Returned: %d\n", printf("15 Hello \"%lld\"\n", LONG_LONG_MAX));
//        printf("Returned: %d\n\n", ft_printf("15 Hello \"%lld\"\n", LONG_LONG_MAX));
//
//        printf("Returned: %d\n", printf("15.1 Hello \"%hd\"\n", SHRT_MIN));
//        printf("Returned: %d\n\n", ft_printf("15.1 Hello \"%hd\"\n", SHRT_MIN));
//
//        printf("Returned: %d\n", printf("16 Hello \"%hd\"\n", SHRT_MAX));
//        printf("Returned: %d\n\n", ft_printf("16 Hello \"%hd\"\n", SHRT_MAX));
//
//        printf("Returned: %d\n", printf("17 Hello \"%hhd\"\n", CHAR_MIN));
//        printf("Returned: %d\n\n", ft_printf("17 Hello \"%hhd\"\n", CHAR_MIN));
//
//        printf("Returned: %d\n", printf("18 Hello \"%hhd\"\n", CHAR_MAX));
//        printf("Returned: %d\n\n", ft_printf("18 Hello \"%hhd\"\n", CHAR_MAX));
//
//        printf("Returned: %d\n", printf("19 Hello \"%u\"\n", -1));
//        printf("Returned: %d\n\n", ft_printf("19 Hello \"%u\"\n", -1));
//
//        printf("Returned: %d\n", printf("20 Hello \"% 9.7u\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("20 Hello \"% 9.7u\"\n", -4235));
//
//        printf("Returned: %d\n", printf("20.1 Hello \"% 9.7u\"\n", -4294967294));
//        printf("Returned: %d\n\n", ft_printf("20.1 Hello \"% 9.7u\"\n", -4294967294));
//
//        printf("Returned: %d\n", printf("20.2 Hello \"% 9.7u\"\n", -42));
//        printf("Returned: %d\n\n", ft_printf("20.2 Hello \"% 9.7u\"\n", -42));
//
//        printf("Returned: %d\n", printf("21 Hello \"% 9.7u\"\n", -1));
//        printf("Returned: %d\n\n", ft_printf("21 Hello \"% 9.7u\"\n", -1));
//
//        printf("Returned: %d\n", printf("22 Hello \"% 11.7u\"\n", -1));
//        printf("Returned: %d\n\n", ft_printf("22 Hello \"% 11.7u\"\n", -1));
//
//        printf("Returned: %d\n", printf("23 Hello \"% -13.7u\"\n", -1));
//        printf("Returned: %d\n\n", ft_printf("23 Hello \"% -13.7u\"\n", -1));
//
//        printf("Returned: %d\n", printf("24 Hello \"% -13.7u\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("24 Hello \"% -13.7u\"\n", 1));
//
//        printf("Returned: %d\n", printf("25 Hello \"% 4u\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("25 Hello \"% 4u\"\n", 1));
//
//        printf("Returned: %d\n", printf("26 Hello \"%- 4u\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("26 Hello \"%- 4u\"\n", 1));
//
//        printf("Returned: %d\n", printf("27 Hello \"%0+- 4u\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("27 Hello \"%0+- 4u\"\n", 1));
//
//        printf("Returned: %d\n", printf("28 Hello \"%0+- 4u\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("28 Hello \"%0+- 4u\"\n", 1));
//
//        printf("Returned: %d\n", printf("29 Hello \"%.5i\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("29 Hello \"%.5i\"\n", -4235));
//
//        printf("Returned: %d\n", printf("30 Hello \"%%\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("30 Hello \"%%\"\n", -4235));
//
//        printf("Returned: %d\n", printf("30.1 Hello \"%5m\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("30.1 Hello \"%5m\"\n", -4235));
//
//        printf("Returned: %d\n", printf("30.2 Hello \"%5%\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("30.2 Hello \"%5%\"\n", -4235));
//
//        printf("Returned: %d\n", printf("30.3 Hello \"%-05K\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("30.3 Hello \"%-05K\"\n", -4235));
//
//        printf("Returned: %d\n", printf("30.4 Hello \"%%\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("30.4 Hello \"%%\"\n", 1));
//

//        for (int i = 0; i < 10000000; i++) {
//            printf("Returned: %d\n", printf("\"%%\"\n"));
//            printf("Returned: %d\n\n", ft_printf("\"%%\"\n"));
//            printf("Returned: %d\n", printf("\"%%\"\n"));
//            printf("Returned: %d\n\n", ft_printf("\"%%\"\n"));
//            printf("Returned: %d\n", printf("\"%%\"\n"));
//            printf("Returned: %d\n\n", ft_printf("\"% %\"\n"));
//            printf("Returned: %d\n", printf("\"%%\"\n"));
//            printf("Returned: %d\n\n", ft_printf("\"%%\"\n"));
//            printf("Returned: %d\n", printf("\"%%\"\n"));
//            printf("Returned: %d\n\n", ft_printf("\"%%\"\n"));
//        }

        printf("Returned: %d", ft_printf("%%"));
//        write(1,"\n",1);
        printf("Returned: %d", printf("%%"));


//        printf("Returned: %d\n", printf("31 Hello \"%U\"\n", ULONG_LONG_MAX));
//        printf("Returned: %d\n\n", ft_printf("31 Hello \"%U\"\n", ULONG_LONG_MAX));
//
//        printf("Returned: %d\n", printf("31.1 Hello \"%hhU\"\n", ULONG_LONG_MAX));
//        printf("Returned: %d\n\n", ft_printf("31.1 Hello \"%hhU\"\n", ULONG_LONG_MAX));
//
//        printf("Returned: %d\n", printf("31.2 Hello \"%U\"\n", -1));
//        printf("Returned: %d\n\n", ft_printf("31.2 Hello \"%U\"\n", -1));
//
//        printf("Returned: %d\n", printf("31.3 Hello \"%U\"\n", 42));
//        printf("Returned: %d\n\n", ft_printf("31.3 Hello \"%U\"\n", 42));
//
//        printf("Returned: %d\n", printf("32 Hello \"%D\"\n", 42));
//        printf("Returned: %d\n\n", ft_printf("32 Hello \"%D\"\n", 42));
//
//        printf("Returned: %d\n", printf("32.1 Hello \"%D\"\n", -1L));
//        printf("Returned: %d\n\n", ft_printf("32.1 Hello \"%D\"\n", -1L));
//
//        printf("Returned: %d\n", printf("32.1 Hello \"%D\"\n", LONG_MAX));
//        printf("Returned: %d\n\n", ft_printf("32.1 Hello \"%D\"\n", LONG_MAX));
//
//        printf("Returned: %d\n", printf("32.1 Hello \"%D\"\n", LONG_MIN));
//        printf("Returned: %d\n\n", ft_printf("32.1 Hello \"%D\"\n", LONG_MIN));
//
//        printf("Returned: %d\n", printf("32.1 Hello \"%s\"\n", "pidr"));
//        printf("Returned: %d\n\n", ft_printf("32.1 Hello \"%s\"\n", "pidr"));
//
//		printf("Returned: %d\n", printf("32.2 Hello NULL_STR \"%s\"\n", (char*)NULL));
//		printf("Returned: %d\n\n", ft_printf("32.2 Hello NULL_STR \"%s\"\n", (char*)NULL));

//        printf("Returned: %d\n", printf("33 % "));
//        printf("Returned: %d\n\n", ft_printf("33 % "));
//
//		printf("Returned: %d\n", printf("33.1 \"{%}\""));
//		printf("Returned: %d\n\n", ft_printf("33.1 \"{%}\""));
//
//		printf("Returned: %d\n", printf("33.2 \"{%{\""));
//		printf("Returned: %d\n\n", ft_printf("33.2 \"{%{\""));
//
//		printf("Returned: %d\n", printf("33.3 \"{%[[[\""));
//		printf("Returned: %d\n\n", ft_printf("33.3 \"{%[[[\""));
//
//		printf("Returned: %d\n", printf("33.4 \"{%///\""));
//		printf("Returned: %d\n\n", ft_printf("33.4 \"{%///\""));
//
//		printf("Returned: %d\n", printf("33.5 \"{%00\""));
//		printf("Returned: %d\n\n", ft_printf("33.5 \"{%00\""));
//
//		printf("Returned: %d\n", printf("34 Hello \"%p\"\n", &i));
//		printf("Returned: %d\n\n", ft_printf("34 Hello \"%p\"\n", &i));
//
//		printf("Returned: %d\n", printf("34.1 Hello \"%p\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("34.1 Hello \"%p\"\n", 0));
//
//		printf("Returned: %d\n", printf("35 Hello \"%X\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("35 Hello \"%X\"\n", 42));
//
//		printf("Returned: %d\n", printf("35.1 Hello \"%X\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("35.1 Hello \"%X\"\n", 0));
//
//		printf("Returned: %d\n", printf("35.2 Hello \"%X\"\n", 4294967296));
//		printf("Returned: %d\n\n", ft_printf("35.2 Hello \"%X\"\n", 4294967296));
//
//		printf("Returned: %d\n", printf("35.3 Hello \"%lx\"\n", 4294967296));
//		printf("Returned: %d\n\n", ft_printf("35.3 Hello \"%lx\"\n", 4294967296));
//
//		printf("Returned: %d\n", printf("35.4 Hello \"%.2x\"\n", 4296));
//		printf("Returned: %d\n\n", ft_printf("35.4 Hello \"%.2x\"\n", 4296));
//
//		printf("Returned: %d\n", printf("35.5 Hello \"%#x\"\n", 4296));
//		printf("Returned: %d\n\n", ft_printf("35.5 Hello \"%#x\"\n", 4296));
//
//		printf("Returned: %d\n", printf("35.6 Hello \"%#x\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("35.6 Hello \"%#x\"\n", 0));
//
//		printf("Returned: %d\n", printf("35.7 Hello \"%#X\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("35.7 Hello \"%#X\"\n", 42));
//
//		printf("Returned: %d\n", printf("35.8 Hello \"%#8x\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("35.8 Hello \"%#8x\"\n", 42));
//
//		printf("Returned: %d\n", printf("35.9 Hello \"%#.x %#.0x\"\n", 0, 0));
//		printf("Returned: %d\n\n", ft_printf("35.9 Hello \"%#.x %#.0x\"\n", 0, 0));
//
//		printf("Returned: %d\n", printf("35.10 Hello \"%#x %#x\"\n", 0, 0));
//		printf("Returned: %d\n\n", ft_printf("35.10 Hello \"%#x %#x\"\n", 0, 0));

//		printf("Returned: %d\n", printf("36 Hello \"%o\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("35 Hello \"%o\"\n", 42));
//
//		printf("Returned: %d\n", printf("36.1 Hello \"%O\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("35.1 Hello \"%O\"\n", 0));
//
//		printf("Returned: %d\n", printf("36.2 Hello \"%O\"\n", 4294967296));
//		printf("Returned: %d\n\n", ft_printf("35.2 Hello \"%O\"\n", 4294967296));

//		printf("Returned: %d\n", printf("37 Hello \"%c\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("37 Hello \"%c\"\n", 42));
//
//		printf("Returned: %d\n", printf("37 Hello \"%c\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("37 Hello \"%c\"\n", 42));
//
//        printf("Returned: %d\n", printf("37 Hello \"%s\"\n", "may the four be with two"));
//        printf("Returned: %d\n\n", ft_printf("37 Hello \"%s\"\n", "may the four be with two"));
//
//		printf("%lc", 0x1F625);


//        char *c;
//        char d = 'a';
//        c = &d;
//        printf("Returned: %d\n", printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
//        printf("Returned: %d\n\n", ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
//
//        printf("Returned: %d\n", printf("%u", UINT_MAX));
//        printf("Returned: %d\n\n", ft_printf("%u", UINT_MAX));
//
//        printf("Returned: %d\n", printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888));
//        printf("Returned: %d\n\n", ft_printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888));
//
//        printf("Returned: %d\n", printf("before %d after", 42));
//        printf("Returned: %d\n\n", ft_printf("before %d after", 42));

    //    printf("\nIteration %d\n",i);
    }
	return (0);
}
