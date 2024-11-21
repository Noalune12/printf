/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:41:21 by lbuisson          #+#    #+#             */
/*   Updated: 2024/11/12 11:59:15 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_specifier(char spec)
{
	if (spec == '\0')
		return (0);
	if (ft_strchr("cspdiuxX%", spec))
		return (1);
	return (0);
}

static int	ft_print_spec(char spec, va_list *args, int *len)
{
	int	res;

	res = 0;
	if (spec == 'c')
		res = ft_print_char(va_arg(*args, int), len);
	else if (spec == 's')
		res = ft_print_str(va_arg(*args, char *), len);
	else if (spec == 'p')
		res = ft_print_ptr(va_arg(*args, void *), len, "0123456789abcdef");
	else if (spec == 'd' || spec == 'i')
		res = ft_print_nbr(va_arg(*args, int), len);
	else if (spec == 'u')
		res = ft_print_unbr(va_arg(*args, unsigned int), len);
	else if (spec == 'x')
		res = ft_print_hexa(va_arg(*args, unsigned int),
				len, "0123456789abcdef");
	else if (spec == 'X')
		res = ft_print_hexa(va_arg(*args, unsigned int),
				len, "0123456789ABCDEF");
	else if (spec == '%')
		res = ft_print_char('%', len);
	if (res == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;
	int		res;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%' && ft_check_specifier(*(fmt + 1)) == 1)
		{
			fmt++;
			res = ft_print_spec(*fmt, &args, &len);
			if (res == -1)
				return (-1);
		}
		else if (*fmt == '%' && ft_check_specifier(*(fmt + 1)) == 0)
		{
			va_end(args);
			return (-1);
		}
		else
		{
			res = ft_print_char(*fmt, &len);
			if (res == -1)
				return (-1);
		}
		fmt++;
	}
	va_end(args);
	return (len);
}

// int	ft_printf(const char *fmt, ...)
// {
// 	va_list	args;
// 	int		len;
// 	int		res;

// 	if (!fmt)
// 		return (-1);
// 	va_start(args, fmt);
// 	len = 0;
// 	while (*fmt)
// 	{
// 		if (*fmt == '%' && ft_check_specifier(*(fmt + 1)) == 1)
// 		{
// 			fmt++;
// 			res = ft_print_spec(*fmt, &args, &len);
// 			if (res == -1)
// 				return (-1);
// 		}
// 		else if (*fmt == '%' && !(fmt + 1))
// 		{
// 			va_end(args);
// 			return (-1);
// 		}
// 		else if (*fmt == '%' && (ft_check_specifier(*(fmt + 1)) == 0))
// 		{
// 			if (!*(fmt + 2))
// 			{
// 				va_end(args);
// 				return (-1);
// 			}
// 			res = ft_print_char(*fmt, &len);
// 			if (res == -1)
// 					return (-1);
// 			fmt++;
// 		}
// 		else
// 		{
// 			res = ft_print_char(*fmt, &len);
// 			if (res == -1)
// 				return (-1);
// 		}
// 		fmt++;
// 	}
// 	va_end(args);
// 	return (len);
// }
