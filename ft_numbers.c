/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:33:17 by lbuisson          #+#    #+#             */
/*   Updated: 2024/11/20 09:26:25 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_print_nbr(int nb, int *len)
{
	ft_putnbr_fd(nb, 1);
	if (nb == -2147483648)
	{
		(*len) += 11;
		return ;
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
}

void	ft_print_unbr(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_print_unbr(nb / 10, len);
	}
	ft_print_char(nb % 10 + '0', len);
}

// static void	ft_print_hex_x(unsigned int hex, int *len, char x)
// {
// 	char	*hex_digits;

// 	if (x == 'x')
// 		hex_digits = "0123456789abcdef";
// 	else
// 		hex_digits = "0123456789ABCDEF";
// 	if (hex >= 16)
// 		ft_print_hex_x(hex / 16, len, x);
// 	ft_print_char(hex_digits[hex % 16], len);
// }

void	ft_print_hexa(unsigned int hex, int *len, char *hex_digits)
{
	if (hex == 0)
		ft_print_char('0', len);
	else
		ft_printhex(hex, len, hex_digits);
}
