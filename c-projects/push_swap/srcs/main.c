/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:31:36 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/22 01:21:25 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_list *a, t_list *b)
{
	write(1, "------\n", 7);
	while (a || b)
	{
		if (a && b)
		{
			ft_putnbr_fd(*(int *)a->content, 1);
			write(1, "   ", 3);
			ft_putnbr_fd(*(int *)b->content, 1);
			write(1, "   \n", 4);
		}
		else
		{
			if (!b)
			{
				ft_putnbr_fd(*(int *)a->content, 1);
				write(1, "\n", 1);
			}	
			if (!a)
			{
				write(1, "    ", 4);
				ft_putnbr_fd(*(int *)b->content, 1);
				write(1, "   \n", 4);
			}
		}
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	write(1, "--- ---\n", 8);
	write(1, " a   b \n\n", 9);
}

t_list	*ft_new_stack(void *content, size_t size)
{
	t_list	*stack;
	void	*aux;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	aux = malloc(size);
	if (!aux)
	{
		free(stack);
		stack = NULL;
	}
	ft_memcpy(aux, content, size);
	stack->content = aux;
	stack->next = NULL;
	return (stack);
}

int	ft_check_num(char *argv)
{
	long	n;
	int		i;

	i = 0;
	while(argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]) && argv[i] != '-')
			ft_error();
		i++;
	}
	n = ft_atoi(argv);
	if (n > 2147483647 || n < -2147483648)
		ft_error();
	return (n);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	long	n;

	i = 1;
	if (argc > 2)
	{
		while (i < argc)
		{
			n = ft_check_num(argv[i]);
			ft_lstadd_back(&a, ft_new_stack((void *) &n, sizeof(int)));
			i++;
		}
		print_stack(a, b);
		ft_swap(a, b, 'a');
		ft_push(&a, &b, 'b');
		ft_push(&a, &b, 'b');
		ft_push(&a, &b, 'b');
		ft_rotate(&a, &b, 'r');
		ft_rev_rotate(&a, &b, 'r');
		ft_swap(a, b, 'a');
		ft_push(&a, &b, 'a');
		ft_push(&a, &b, 'a');
		ft_push(&a, &b, 'a');
		print_stack(a, b);

	}
	else
		ft_error();
	// system("leaks push_swap");
}
