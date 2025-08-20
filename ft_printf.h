/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:27:46 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/01 16:58:17 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_format
{
	int		plus;
	int		space;
	int		hash;
	char	specifier;
}	t_format;

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printnbr(int n, t_format *fmt);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_u(unsigned int num);
int		ft_print_x(unsigned int num, const char x_X, t_format *fmt);
int		ft_printf(const char *format, ...);
#endif
