/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:06:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/09 11:56:11 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define SPECIFIERS "cspdiuxX%"

typedef struct s_print
{
	va_list	args;
	int		width;
	int		preci;
	int		zero;
	int		point;
	int		dash;
	int		length;
	int		percen;
	int		sign;
}    t_print;

int		ft_printf(const char *format, ...);
int 	ft_check_format(t_print *tab, const char *format, int pos);
void    ft_dash(t_print *tab, const char *format, int pos);
void    ft_zero(t_print *tab, const char *format, int pos);
void    ft_point(t_print *tab, const char *format, int pos);
void    ft_star(t_print *tab, const char *format, int pos);

void	ft_fill_space(int spaces, t_print *tab);

void	ft_print_char(t_print *tab, int i);
void	ft_print_str(t_print *tab);
void	ft_print_diu(t_print *tab);

t_print *ft_reset_tab(t_print *tab);

#endif