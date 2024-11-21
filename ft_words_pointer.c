/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:33:28 by lbuisson          #+#    #+#             */
/*   Updated: 2024/11/21 09:55:18 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, int *len)
{
	int	res;

	res = ft_putchar_fd(c, 1);
	if (res == -1)
		return (-1);
	(*len)++;
	return (1);
}

int	ft_print_str(char *str, int *len)
{
	int	res;

	if (!str)
	{
		res = ft_putstr_fd("(null)", 1);
		if (res == -1)
			return (-1);
		(*len) += 6;
	}
	else
	{
		res = ft_putstr_fd(str, 1);
		if (res == -1)
			return (-1);
		(*len) += ft_strlen(str);
	}
	return (1);
}

int	ft_print_ptr(void *ptr, int *len, char *hex_digits)
{
	size_t	addr;
	int		res;

	if (!ptr)
	{
		res = ft_putstr_fd("(nil)", 1);
		if (res == -1)
			return (-1);
		(*len) += 5;
	}
	else
	{
		addr = (size_t)ptr;
		res = ft_putstr_fd("0x", 1);
		if (res == -1)
			return (-1);
		(*len) += 2;
		res = ft_puthex(addr, len, hex_digits);
		if (res == -1)
			return (-1);
	}
	return (1);
}
