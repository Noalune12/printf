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
	if (spec == 'c' || spec == 's' || spec == 'p' || spec == 'd' || spec == 'i'
		|| spec == 'u' || spec == 'x' || spec == 'X' || spec == '%')
		return (1);
	return (0);
}

static void	ft_print_spec(char spec, va_list *args, int *len)
{
	if (spec == 'c')
		ft_print_char(va_arg(*args, int), len);
	if (spec == 's')
		ft_print_str(va_arg(*args, char *), len);
	if (spec == 'p')
		ft_print_ptr(va_arg(*args, void *), len);
	if (spec == 'd' || spec == 'i')
		ft_print_nbr(va_arg(*args, int), len);
	if (spec == 'u')
		ft_print_unbr(va_arg(*args, unsigned int), len);
	if (spec == 'x' || spec == 'X')
		ft_print_hexa(va_arg(*args, unsigned int), len, spec);
	if (spec == '%')
		ft_print_char('%', len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;

	va_start(args, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%' && ft_check_specifier(*(fmt + 1)) == 1)
		{
			fmt++;
			ft_print_spec(*fmt, &args, &len);
		}
		else if (*fmt == '%' && ft_check_specifier(*(fmt + 1)) == 0)
			return (len);
		else
		{
			ft_putchar_fd(*fmt, 1);
			len++;
		}
		fmt++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>

int	main(void)
{
	//no %
	printf("WITHOUT %%...\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("print this"));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("print this"));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("o"));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("o"));
	printf("\n\n");

	//%c
	printf("%%c\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%c%c%c%c", 'c', 'h', 'a', 'r'));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%c%c%c%c", 'c', 'h', 'a', 'r'));

	//%s
	printf("%%s\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%s", "coucou"));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%s", "coucou"));
	printf("\n\n");
	char	*str = NULL;
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%s", str));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%s", str));
	printf("\n\n");

	//%p
	printf("%%p\n\n");
	char	str1[] = "char";
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%p", str1));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%p", str1));
	printf("\n\n");
	char	*str2 = NULL;
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%p", str2));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%p", str2));

	//%d
	printf("%%d\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%d", 0));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%d", 0));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%d", -42));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%d", -42));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%d", -2147483648));
	printf("\n\nPRINTF\n");
	//printf("\nreturn = %d", printf("%d", -2147483648)); //long int ???
	printf("\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%d", 99999999999999999));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%d", 99999999999999999));
	// printf("\n\n");

	//%u
	printf("%%u\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%u", 0));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%u", 0));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%u", 4294967295));
	printf("\n\nPRINTF\n");
	//printf("\nreturn = %d", printf("%u", 4294967295));
	printf("\n\n");

	//%x and X
	printf("%%x and X\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%x", 0));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%x", 0));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%x", 100));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%x", 100));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%X", 100));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%X", 100));
	printf("\n\n");

	//%%
	printf("%%%%\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%%"));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%%"));
	printf("\n\n");

	//backslash
	printf("\\\\\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("\\\\\n\t\??\n"));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("\\\\\n\t\??\n"));
	printf("\n\n");
	// //wrong %
	// printf("WRONG %%...\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("print this%e"));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("print this%e", "hello"));

}
*/
