/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durante <durante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:06:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/27 17:38:53 by durante          ###   ########.fr       */
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
	va_list     args;    		// arg to print out                    
	int         width;      	// width                
	int		preci;        	// precision              
	int		zero;       	// zero padding               
	int		point;      	// .     
	int		dash;       	// -           
	int		length;      	// total_length (return value)              
	int		sign;       	// positive or negative number               
	int		is_zero;      	// is number zero                 
	int		percen;   	      // %               
	int		space;         	// space flag ' '            
}    t_print;

int   ft_printf(const char *format, ...);
int   ft_check_format(t_print *tab, const char *format, int pos);
void  check_width(t_print *tab);
void	ft_print_char(t_print *tab);
void	ft_fill_space(int spaces, t_print *tab);
t_print *ft_reset_tab(t_print *tab);

#endif