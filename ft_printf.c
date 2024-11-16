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
	if (spec =='c' || spec =='s' || spec =='p'  || spec =='d' || spec =='i'
		 || spec =='u' || spec =='x' || spec =='X' || spec =='%')
		return (1);
	return (0);
}

static void	ft_print_spec(char spec, va_list *args, int *len)
{
	if (spec == 'c')
		ft_print_char(va_arg(*args, int), len);
	if (spec == 's')
		ft_print_str(va_arg(*args, char *), len);
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
			return (len); //???
		//case backslash
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
	// //wrong %
	// printf("WRONG %%...\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("print this%e"));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("print this%e", "hello"));

}
