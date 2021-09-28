/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:33:13 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/27 21:03:21 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define R "\033[0;31m"
# define G "\033[0;32m"
# define Y "\033[0;33m"
# define NC "\033[0m"

int		main(int argc, char **argv);
t_list	*ft_new_stack(void *content, size_t size);

int		push_swap(t_list **a, t_list **b, t_list **aux_stack);
void	sort_big_stack(t_list **a, t_list **b, int length);
void	sort_small_stack(t_list **a, t_list **b, int length);
void	simplify_stack(t_list **a, int length);

void	ft_swap(t_list **a, t_list **b, char c);
void	ft_push(t_list **a, t_list **b, char c);
void	ft_rotate(t_list **a, t_list **b, char c);
void	ft_rev_rotate(t_list **a, t_list **b, char c);

void	ft_error(int e, t_list **a);
void	ft_exit(t_list **a, t_list **b, t_list **aux_stack);
void	print_stack(t_list *a, t_list *b);

#endif