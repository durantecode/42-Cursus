/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:06:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/11 20:27:27 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_print
{         
      va_list	args;    		// arg to print out                    
      int		width;      	// width                
      int		preci;        	// precision              
      int		zero;       	// zero padding               
      int		point;      	// .     
      int		dash;       	// -               
      int		length;      	// total_length (return value)              
      int		sign;       	// positive or negative number               
      int		is_zero;      	// is number zero                 
      int		percen;   	// %               
      int		space;         	// space flag ' '            
}    t_print;

int		ft_printf(const char *format, ...);

#endif