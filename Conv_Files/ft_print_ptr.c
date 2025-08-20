/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:01:43 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/04 14:07:47 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static void	print_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		print_ptr(num / 16);
		print_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

static int	ptr_len(unsigned long long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		print_ptr(ptr);
		len += ptr_len(ptr);
	}
	return (len);
}
