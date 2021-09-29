/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:33:13 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/29 22:59:35 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

int		main(int argc, char **argv);
t_list	*ft_new_stack(void *content, size_t size);

int		push_swap(t_list **a, t_list **b);
void	sort_small_stack(t_list **a, t_list **b, int length);
void	sort_big_stack(t_list **a, t_list **b, int length);
void	simplify_stack(t_list **a, t_list **b, int length);
int		is_sorted(t_list **a, int length);

void	ft_swap(t_list **a, t_list **b, char c);
void	ft_push(t_list **a, t_list **b, char c);
void	ft_rotate(t_list **a, t_list **b, char c);
void	ft_rev_rotate(t_list **a, t_list **b, char c);

void	ft_error(t_list **a);
void	ft_exit(t_list **a, t_list **b);
void	print_stack(t_list *a, t_list *b);

#endif