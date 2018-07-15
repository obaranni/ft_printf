cmake_minimum_required(VERSION 3.9)
project(ft_printf)

set(CMAKE_CXX_STANDARD 99)

add_executable( ft_printf
                headers/ft_printf.h
        main.c
                 src/ft_itoa_base.c
#                /Users/obaranni/printf/src/printf_main2.c
                src/mainloop.c
                src/flags.c
                src/width.c
                libft/ft_atoi.c
                libft/ft_isdigit.c
                src/precision.c
                src/sizes.c
                libft/ft_strsub.c
                libft/ft_strlen.c
                src/read_conversion_letter.c
                libft/ft_strchr.c
                libft/ft_putchar.c
                libft/ft_putstr.c
                src/print_usig_dec.c
                src/fetch_data.c
                src/any_unsigned_dec_to_str.c
                libft/ft_strcpy.c
                src/digit_len.c
                src/calculate_argument_lenth.c
                src/int_to_sign_dec.c
                src/type_cast.c
                src/choose_datatype_handler.c
        src/printf_sig_dec.c
                src/print_width.c
        libft/ft_putnbr
                src/print_prcision.c
                src/int_to_unsign_dec.c
        src/any_signed_dec_to_str.c
        src/print_letter.c
        src/print_usig_dec.c
        src/print_string.c
        src/print_hex.c
        src/print_octal.c
        src/itoa_base_size.c
        src/print_char.c
        src/print_width_char.c
        src/print_uni_string.c)
