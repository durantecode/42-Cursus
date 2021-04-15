/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:19:59 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/15 13:11:53 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a new
** element. The variable ’content’ is initialized
** with the value of the parameter ’content’. The
** variable ’next’ is initialized to NULL. */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*str;

	str = malloc(sizeof(str));
	if (!str)
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}
