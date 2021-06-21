/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:06:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/21 15:32:52 by ldurante         ###   ########.fr       */
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
	int		p_star;
}		t_print;

int		ft_printf(const char *format, ...);
int 	ft_check_format(t_print *tab, const char *format, int pos);
void    ft_dash(t_print *tab, const char *format, int pos);
void    ft_zero(t_print *tab, const char *format, int pos);
void    ft_point(t_print *tab, const char *format, int pos);
void    ft_star(t_print *tab, const char *format, int pos);

void	ft_fill_space(int spaces, t_print *tab);
void	update_tab_diu(t_print *tab, int len);
char	*check_number(unsigned long nb, int i);

void	basic_width(t_print *tab, char *str, long len);
void	len_width_nopreci(t_print *tab, char *str, int len, long digit);
void	width_len_nopreci(t_print *tab, char *str, int len, long digit);
void	preci_no_width(t_print *tab, char *str, int len, long digit);
void	preci_and_width(t_print *tab, char *str, int len, long digit);

void	ft_print_char(t_print *tab, int i);
void	ft_print_str(t_print *tab);
void	ft_print_di(t_print *tab);
void	ft_print_u(t_print *tab);
void	ft_print_pointer(t_print *tab);
void	ft_print_x(t_print *tab, int i);

char	*ft_itoa_base(unsigned int nb, unsigned int base, int i);
char	*ft_uitoa_base(unsigned long nb, unsigned int base, int i);
char	*ft_uitoa(unsigned long int n);

t_print *ft_reset_tab(t_print *tab);

#endif