/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:41:15 by jenlee            #+#    #+#             */
/*   Updated: 2025/07/16 15:58:41 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	parse_flag(const char *format, t_format *flag)
{
	int	i;

	i = 0;
	while (*format == '+' || *format == ' ' || *format == '#')
	{
		if (*format == '+')
			flag->plus = 1;
		if (*format == ' ')
			flag->space = 1;
		if (*format == '#')
			flag->hash = 1;
		format++;
		i++;
	}
	flag->specifier = *format;
	return (i);
}

void	struct_zero(t_format *fmt)
{
	fmt->space = 0;
	fmt->hash = 0;
	fmt->plus = 0;
	fmt->specifier = 0;
}

int	check_specifier(t_format *fmt, va_list args)
{
	int	count;

	count = 0;
	if (fmt->specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (fmt->specifier == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (fmt->specifier == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		count += ft_printnbr(va_arg(args, int), fmt);
	else if (fmt->specifier == 'u')
		count += ft_print_u(va_arg(args, unsigned int));
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		count += ft_print_x(va_arg(args, unsigned int), \
fmt->specifier, fmt);
	else if (fmt->specifier == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	t_format	fmt;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			struct_zero(&fmt);
			format += parse_flag(format, &fmt);
			count += check_specifier(&fmt, args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(void)
{
    int my_len, real_len;

    // %c - characters
    my_len = ft_printf("Char: %c %c %c\n", 'A', '0', '@');
    real_len = printf("Char: %c %c %c\n", 'A', '0', '@');
    printf("[Return] ft_printf: %d | printf: %d\n\n", my_len, real_len);

    // %s - strings
    my_len = ft_printf("String: %s\n", "Hello, world!");
    real_len = printf("String: %s\n", "Hello, world!");
    printf("[Return] ft_printf: %d | printf: %d\n\n", my_len, real_len);

    // NULL string
	char *str = NULL;
    my_len = ft_printf("NULL string: %s\n", str);
    real_len = printf("NULL string: %s\n", str);
    printf("[Return] ft_printf: %d | printf: %d\n\n", my_len, real_len);

    // %d and %i - signed integers
    my_len = ft_printf("Signed: %d, %i, %d\n", 0, -42, INT_MIN);
    real_len = printf("Signed: %d, %i, %d\n", 0, -42, INT_MIN);
    printf("[Return] ft_printf: %d | printf: %d\n\n", my_len, real_len);

    // %u - unsigned integers
    my_len = ft_printf("Unsigned: %u, %u\n", 0, UINT_MAX);
    real_len = printf("Unsigned: %u, %u\n", 0, UINT_MAX);
    printf("[Return] ft_printf: %d | printf: %d\n\n", my_len, real_len);

    // %x / %X - hexadecimal
    my_len = ft_printf("Hex lower: %x | upper: %X\n", 255, 255);
    real_len = printf("Hex lower: %x | upper: %X\n", 255, 255);
    printf("[Return] ft_printf: %d | printf: %d\n\n", my_len, real_len);

    // Edge hex values
    my_len = ft_printf("Hex edge: %x | %x | %x\n", 0, UINT_MAX, 16);
    real_len = printf("Hex edge: %x | %x | %x\n", 0, UINT_MAX, 16);
    printf("[Return] ft_printf: %d | printf: %d\n\n", my_len, real_len);

    // %p - pointers
    int *ptr = malloc(sizeof(int));
    if (ptr)
        *ptr = 42;

    my_len = ft_printf("Pointer: %p\n", ptr);
    real_len = printf("Pointer: %p\n", ptr);
    printf("[Return] ft_printf: %d | printf: %d\n\n", my_len, real_len);

    my_len = ft_printf("NULL pointer: %p\n", (void *)NULL);
    real_len = printf("NULL pointer: %p\n", (void *)NULL);
    printf("[Return] ft_printf: %d | printf: %d\n\n", my_len, real_len);

    // %% - percent sign
    my_len = ft_printf("Percent: %% %% %%\n");
    real_len = printf("Percent: %% %% %%\n");
    printf("[Return] ft_printf: %d | printf: %d\n\n", my_len, real_len);

    free(ptr); // prevent memory leak

    return 0;
}*/
