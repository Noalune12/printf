/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:00:43 by lbuisson          #+#    #+#             */
/*   Updated: 2024/11/21 15:49:18 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// //no %
	// printf("WITHOUT %%...\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("print this"));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("print this"));
	// printf("\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("o"));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("o"));
	// printf("\n\n");

	// //%c
	// printf("%%c\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%c%c%c%c", 'c', 'h', 'a', 'r'));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%c%c%c%c", 'c', 'h', 'a', 'r'));
	// printf("\n\n");

	// //%s
	// printf("%%s\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%s", "coucou"));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%s", "coucou"));
	// printf("\n\n");
	// char	*str = NULL;
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%s", str));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%s", str));
	// printf("\n\n");

	// //%p
	// printf("%%p\n\n");
	// char	str1[] = "char";
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%p", str1));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%p", str1));
	// printf("\n\n");
	// char	*str2 = NULL;
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%p", str2));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%p", str2));
	// printf("\n\n");

	// //%d
	// printf("%%d\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%d", 0));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%d", 0));
	// printf("\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%d", -42));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%d", -42));
	// printf("\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%d", -2147483648));
	// printf("\n\nPRINTF\n");
	// //printf("\nreturn = %d", printf("%d", -2147483648)); //long int ???
	// printf("\n\n");
	// // printf("FT_PRINTF\n");
	// // printf("\nreturn = %d", ft_printf("%d", 99999999999999999));
	// // printf("\n\nPRINTF\n");
	// // printf("\nreturn = %d", printf("%d", 99999999999999999));
	// // printf("\n\n");

	// //%u
	// printf("%%u\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%u", 0));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%u", 0));
	// printf("\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%u", 4294967295));
	// printf("\n\nPRINTF\n");
	// //printf("\nreturn = %d", printf("%u", 4294967295));
	// printf("\n\n");

	// //%x and X
	// printf("%%x and X\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%x", 0));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%x", 0));
	// printf("\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%x", 100));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%x", 100));
	// printf("\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("%X", 100));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("%X", 100));
	// printf("\n\n");

	// //%%
	printf("%%%%\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf(" %% "));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf(" %% "));
	printf("\n\n");

	// //backslash
	// printf("\\\\\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf("\\\\\n\t\??\n"));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf("\\\\\n\t\??\n"));
	// printf("\n\n");
	//wrong %
	printf("WRONG %%...\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("hello %h hello"));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("hello %h hello"));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%h"));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%h"));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("hello %h hello %h hello %h"));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("hello %h hello %h hello %h"));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("% % % "));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("% % % "));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%h %h %h "));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%h %h %h "));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%- %- %- "));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%- -%- %- "));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%d %h %h %-"));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%d %h %h %-"));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%, jj"));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%, jj"));
	printf("\n\n");
	printf("FT_PRINTF\n");
	printf("\nreturn = %d", ft_printf("%%%"));
	printf("\n\nPRINTF\n");
	printf("\nreturn = %d", printf("%%%"));
	printf("\n\n");
	// printf("FT_PRINTF\n");
	// printf("\nreturn = %d", ft_printf(0));
	// printf("\n\nPRINTF\n");
	// printf("\nreturn = %d", printf(NULL));
	return (0);

}
