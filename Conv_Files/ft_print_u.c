/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:43:20 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/04 14:04:59 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static int	num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (1);
}

static char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	*ft_uitoa(unsigned int num)
{
	char	*n;
	int		len;

	if (num == 0)
		return (ft_strdup(""));
	len = num_len(num);
	n = (char *)malloc((len + 1) * sizeof(char));
	if (!n)
		return (NULL);
	n[len] = '\0';
	while (num != 0)
	{
		n[--len] = num % 10 + '0';
		num /= 10;
	}
	return (n);
}

int	ft_print_u(unsigned int num)
{
	int		counter;
	char	*n;

	counter = 0;
	if (num == 0)
		counter += write (1, "0", 1);
	else
	{
		n = ft_uitoa(num);
		counter += ft_printstr(n);
		free (n);
	}
	return (counter);
}
