/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:31:36 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/28 03:24:33 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	init_stack(t_list **a, t_list **aux_stack, long n)
{
	t_list	*aux;

	aux = *a;
	while (aux)
	{
		if (n == *(int *)aux->content)
			ft_error(4, a);
		aux = aux->next;
	}
	ft_lstadd_back(a, ft_new_stack((void *) &n, sizeof(int)));
	ft_lstadd_back(aux_stack, ft_new_stack((void *) &n, sizeof(int)));
}

int	ft_check_num(t_list **a, char *argv)
{
	long	n;

	if (!ft_atoi(argv) && argv[0] != '0')
	{
		if ((argv[0] == '+' || argv[0] == '-')
			&& argv[1] == '0')
			ft_error(2, a);
		else
			ft_error(1, a);
	}
	else
		n = ft_atoi(argv);
	if (n > MAX_INT || n < MIN_INT)
		ft_error(3, a);
	return (n);
}

int	check_argument(char *argv)
{
	char	**test;
	int i;

	test = ft_split(argv, ' ');
	i = 0;
	while (test[i] != '\0')
		i++;
	if (i > 1)
		return (1);
	// else
	// 	write(1, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*aux_stack;
	char	**arg;
	int		i;
	int		j;
	long	n;

	i = 1;
	a = NULL;
	b = NULL;
	aux_stack = NULL;
	if (argc >= 2)
	{
		while (i < argc)
		{
			if (check_argument(argv[i]))
			{
				arg = ft_split(argv[i], ' ');
				j = 0;
				while (arg[j] != '\0')
				{
					n = ft_check_num(&a, arg[j]);
					init_stack(&a, &aux_stack, n);
					j++;
				}
			}
			else
			{
				n = ft_check_num(&a, argv[i]);
				init_stack(&a, &aux_stack, n);
			}
			i++;
		}
		// print_stack(a, b);
		push_swap(&a, &b, &aux_stack);
	}
	else
		ft_error(0, &a);
	ft_exit(&a, &b, &aux_stack);
}
