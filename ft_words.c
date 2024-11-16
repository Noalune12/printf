#include "ft_printf.h"

void	ft_print_char(char c, int *len)
{
	ft_putchar_fd(c, 1);
	(*len)++;
}

void	ft_print_str(char *str, int *len)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		(*len) += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		(*len) += ft_strlen(str);
	}
}
