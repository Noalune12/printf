/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:52:19 by lbuisson          #+#    #+#             */
/*   Updated: 2024/11/21 09:53:46 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	res;

	if (n == -2147483648)
	{
		res = write(fd, "-2147483648", 11);
		if (res == -1)
			return (-1);
		return (1);
	}
	if (n < 0)
	{
		res = ft_putchar_fd('-', fd);
		if (res == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	res = ft_putchar_fd(n % 10 + '0', fd);
	if (res == -1)
		return (-1);
	return (1);
}
