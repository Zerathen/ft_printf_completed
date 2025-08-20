/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:50:58 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/09 17:35:07 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static int	hex_len(unsigned int num, t_format *fmt)
{
	int	i;

	i = 0;
	if (fmt->hash && num != 0)
		i += 2;
	while (num != 0)
	{
		i++;
		num /= 16;
	}
	return (i);
}

static void	ft_hex(unsigned int num, const char x_X)
{
	if (num >= 16)
	{
		ft_hex(num / 16, x_X);
		ft_hex(num % 16, x_X);
	}
	else
	{
		if (num < 10)
			ft_putchar(num + '0');
		else
		{
			if (x_X == 'x')
				ft_putchar(num - 10 + 'a');
			if (x_X == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	ft_print_x(unsigned int num, const char x_X, t_format *fmt)
{
	if (num == 0)
		return (ft_putchar('0'));
	else
	{
		if (fmt->hash && num != 0)
		{
			if (x_X == 'x')
				ft_printstr("0x");
			if (x_X == 'X')
				ft_printstr("0X");
		}
		ft_hex(num, x_X);
		return (hex_len(num, fmt));
	}
}
