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

static void	ft_printhex(size_t ptr, int *len)
{
	const char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (ptr >= 16)
		ft_printhex(ptr / 16, len);
	ft_print_char(hex_digits[ptr % 16], len);
}

void	ft_print_ptr(void *ptr, int *len)
{
	size_t	addr;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		(*len) += 5;
	}
	else
	{
		addr = (size_t)ptr;
		ft_putstr_fd("0x", 1);
		(*len) += 2;
		ft_printhex(addr, len);
	}
}
