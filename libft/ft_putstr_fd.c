/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:48:53 by lbuisson          #+#    #+#             */
/*   Updated: 2024/11/21 09:54:46 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int		res;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		res = ft_putchar_fd(s[i], fd);
		if (res == -1)
			return (-1);
		i++;
	}
	return (1);
}
