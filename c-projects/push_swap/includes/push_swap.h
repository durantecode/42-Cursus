/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:33:13 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/21 19:25:43 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

int		main(int argc, char **argv);
t_list	*ft_new_stack(void *content, size_t size);

void	ft_swap(t_list *a, t_list *b, char c);
void	ft_push(t_list **a, t_list **b, char c);
void	ft_rotate(t_list **a, t_list **b, char c);
void	ft_rev_rotate(t_list **a, t_list **b, char c);

void	delete_node(t_list **src);
int		ft_error(void);

#endif