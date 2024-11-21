/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:33:17 by lbuisson          #+#    #+#             */
/*   Updated: 2024/11/21 09:54:02 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_print_nbr(int nb, int *len)
{
	int	res;

	res = ft_putnbr_fd(nb, 1);
	if (res == -1)
		return (-1);
	if (nb == -2147483648)
	{
		(*len) += 11;
		return (1);
	}
	if (nb < 0)
	{
		nb = -nb;
		(*len)++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		(*len)++;
	}
	(*len)++;
	return (1);
}

int	ft_print_unbr(unsigned int nb, int *len)
{
	int	res;

	if (nb >= 10)
	{
		ft_print_unbr(nb / 10, len);
	}
	res = ft_print_char(nb % 10 + '0', len);
	if (res == -1)
		return (-1);
	return (1);
}

int	ft_puthex(size_t nbr, int *len, char *hex_digits)
{
	int	res;

	if (nbr >= 16)
		ft_puthex(nbr / 16, len, hex_digits);
	res = ft_print_char(hex_digits[nbr % 16], len);
	if (res == -1)
		return (-1);
	return (1);
}

int	ft_print_hexa(unsigned int hex, int *len, char *hex_digits)
{
	int	res;

	if (hex == 0)
	{
		res = ft_print_char('0', len);
		if (res == -1)
			return (-1);
	}
	else
	{
		res = ft_puthex(hex, len, hex_digits);
		if (res == -1)
			return (-1);
	}
	return (1);
}
