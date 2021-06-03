/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:34:34 by durante           #+#    #+#             */
/*   Updated: 2021/06/03 13:28:27 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_isdash(t_print *tab, char *aux, char *str, int len)
{
	if (tab->preci && tab->width)
	{
		aux = ft_substr(str, 0, tab->preci);
		ft_putstr_fd(aux, 1);
		if (tab->preci < len)
			ft_fill_space(tab->width - tab->preci, tab);
		else
			ft_fill_space(tab->width - len, tab);
		free(aux);
	}
	else if (tab->point && !tab->preci)
		ft_fill_space(tab->width, tab);
	else
	{
		ft_putstr_fd(str, 1);
		ft_fill_space(tab->width - len, tab);
	}
	tab->length += tab->width;
}

void	ft_notdash(t_print *tab, char *aux, char *str, int len)
{
	if (!tab->point || tab->preci >= len)
		ft_fill_space(tab->width - len, tab);
	else if (tab->point && tab->preci < len && tab->preci > 0)
		ft_fill_space(tab->width - tab->preci, tab);
	else
		ft_fill_space(tab->width, tab);
	tab->length += tab->width;
	aux = ft_substr(str, 0, tab->preci);
	if (tab->point)
	{
		ft_putstr_fd(aux, 1);
		if (len >= tab->width)
		{
			if (tab->preci <= tab->width && tab->width != 1)
				ft_fill_space(tab->width - tab->preci, tab);
			else
				ft_fill_space(tab->width - len, tab);
		}
		if (!tab->width && tab->preci > len)
			tab->length += len;
		else if (!tab->width && tab->preci)
			tab->length += tab->preci;
	}
	else
		ft_putstr_fd(str, 1);
}

void	ft_print_str(t_print *tab)
{
	int		len;
	char	*str;
	char	*aux;

	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (len >= tab->width && !tab->point)
	{
		ft_putstr_fd(str, 1);
		tab->length += len;
	}
	else if (tab->dash)
		ft_isdash(tab, aux, str, len);
	else
	{
		ft_notdash(tab, aux, str, len);
		free(aux);
	}
}
