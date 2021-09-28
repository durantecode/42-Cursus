/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:31:36 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/28 20:48:26 by ldurante         ###   ########.fr       */
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

void	init_stack(t_list **a, long n)
{
	t_list	*aux;

	aux = *a;
	while (aux)
	{
		if (n == *(int *)aux->content)
			ft_error(a);
		aux = aux->next;
	}
	ft_lstadd_back(a, ft_new_stack((void *) &n, sizeof(int)));
}

int	ft_check_num(t_list **a, char *argv)
{
	long	n;

	if (!ft_atoi(argv) && argv[0] != '0')
	{
		if ((argv[0] == '+' || argv[0] == '-')
			&& argv[1] == '0')
			n = ft_atoi(argv);
		else
			ft_error(a);
	}
	else
		n = ft_atoi(argv);
	if (n > MAX_INT || n < MIN_INT)
		ft_error(a);
	return (n);
}

void	get_numbers(char *argv, t_list **a)
{
	char	**param;
	long	n;
	int		j;

	param = ft_split(argv, ' ');
	j = 0;
	while (param[j] != '\0')
	{
		n = ft_check_num(a, param[j]);
		init_stack(a, n);
		free(param[j]);
		j++;
	}
	free(param);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	while (i < argc)
	{
		get_numbers(argv[i], &a);
		i++;
	}
	push_swap(&a, &b);
	ft_exit(&a, &b);
}
