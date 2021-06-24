/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:34:34 by durante           #+#    #+#             */
/*   Updated: 2021/06/24 16:08:44 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_isdash(t_print *tab, char *aux, char *str, int len)
{
	if (tab->preci && tab->width)
	{
		tab->length += write(1, aux, ft_strlen(aux));
		if (tab->preci < len)
			ft_fill_space(tab->width - tab->preci, tab);
		else
			ft_fill_space(tab->width - len, tab);
	}
	else if (tab->point && !tab->preci)
		ft_fill_space(tab->width, tab);
	else
	{
		if (!tab->width && tab->preci)
			tab->length += write(1, aux, ft_strlen(aux));
		else
			tab->length += write(1, str, len);
		ft_fill_space(tab->width - len, tab);
	}
}

void	ft_notdash(t_print *tab, char *aux, char *str, int len)
{
	if (!tab->point || tab->preci >= len)
		ft_fill_space(tab->width - len, tab);
	else if (tab->point && tab->preci < len && tab->preci > 0)
		ft_fill_space(tab->width - tab->preci, tab);
	else
		ft_fill_space(tab->width, tab);
	if (tab->point)
	{
		tab->length += write(1, aux, ft_strlen(aux));
		if (len >= tab->width && tab->preci > 0)
		{
			if (tab->preci <= tab->width && tab->width != 1
				&& len < tab->width)
				ft_fill_space(tab->width - tab->preci, tab);
			if (tab->sign && tab->preci == 0)
				tab->length += write(1, str, len);
			else
				ft_fill_space(tab->width - len, tab);
		}
		else if (tab->sign)
			tab->length += write(1, str, len);
	}
	else
		tab->length += write(1, str, len);
}

void	ft_print_str(t_print *tab)
{
	int		len;
	char	*str;
	char	*aux;

	if (tab->preci == -1)
	{
		tab->preci = 0;
		if (tab->sign || tab->p_star)
			tab->point = 0;
	}
	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	aux = ft_substr(str, 0, tab->preci);
	if (len >= tab->width && !tab->point)
		tab->length += write(1, str, len);
	else if (tab->dash)
		ft_isdash(tab, aux, str, len);
	else
		ft_notdash(tab, aux, str, len);
	free(aux);
}
