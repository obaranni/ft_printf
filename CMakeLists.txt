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
        src/printing_usig_dec.c
                src/fetch_data.c
                src/any_unsigned_dec_to_str.c
                libft/ft_strcpy.c
                src/digit_len.c
                src/calculate_argument_lenth.c
        src/print_sign_dec.c
                src/type_cast.c
                src/choose_datatype_handler.c
        src/printing_sig_dec.c
                src/print_width.c
        libft/ft_putnbr
                src/print_prcision.c
        src/print_unsign_dec.c
        src/any_signed_dec_to_str.c
        src/print_letter.c
        src/printing_usig_dec.c
        src/print_hex.c
        src/print_octal.c
        src/itoa_base_size.c
        src/print_width_char.c
        src/print_uni_char.c
        src/masks_for_unicode.c
        src/duplicate_array.c
        src/count_uni_string_len.c
        src/printing_octal.c
        src/any_octal_to_str.c
        src/print_string.c
        src/printing_unicode.c
        libft/ft_strcmp.c
        libft/ft_strdup.c
        capture.c

        src/cast_hex.c src/printing_string.c src/preparation_string.c)
