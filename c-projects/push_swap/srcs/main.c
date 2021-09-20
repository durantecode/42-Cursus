/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:31:36 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/20 18:03:43 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_list *a)
{
    while (a != NULL)
    {
        printf("%d\n", *(int *)a->content);
        a = a->next;
    }
}

t_list	*ft_new_stack(void *content, size_t size)
{
	t_list	*str;
	void	*aux;

	str = malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	aux = malloc(size);
	if (!aux)
	{
		free(str);
		str = NULL;
	}
	ft_memcpy(aux, content, size);
	str->content = aux;
	str->next = NULL;
	return (str);
}

int	ft_check_num(char *argv)
{
	int n;
	
	if (!ft_atoi(argv))
		ft_error();
	else
		n = ft_atoi(argv);
	return (n);
}

int	main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	int	i;
	int	n;

	i = 1;
	if (argc > 2)
	{
		while (i < argc)
		{
			n = ft_check_num(argv[i]);
			ft_lstadd_back(&a, ft_new_stack((void *) &n, sizeof(int)));
			i++;
		}
		print_stack(a);
	}
	else
		ft_error();
	//printf("LIST SIZE: %d \n", ft_lstsize(a));
	//system("leaks push_swap");
}