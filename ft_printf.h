/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:46:55 by lbuisson          #+#    #+#             */
/*   Updated: 2024/11/12 11:47:38 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

void	ft_print_char(char c, int *len);
void	ft_print_str(char *str, int *len);
void	ft_print_ptr(void *ptr, int *len);
void	ft_print_nbr(int nb, int *len);
void	ft_print_unbr(unsigned int nb, int *len);
void	ft_print_hexa(unsigned int hex, int *len, char x);

#endif
