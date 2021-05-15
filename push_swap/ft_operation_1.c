/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:41:19 by mochegri          #+#    #+#             */
/*   Updated: 2021/05/15 14:32:19 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_oper(char *str)
{
	if (ft_strcmp("sa", str) && ft_strcmp("sb", str)
		&& ft_strcmp("ss", str) && ft_strcmp("pa", str)
		&& ft_strcmp("pb", str) && ft_strcmp("ra", str)
		&& ft_strcmp("rb", str) && ft_strcmp("rr", str)
		&& ft_strcmp("rra", str) && ft_strcmp("rrb", str)
		&& ft_strcmp("rrr", str))
		ft_exit();
}

void	ft_s(t_stack *a, t_stack *b, char *str)
{
	if (str[1] == 'a')
		ft_swap(a, 0);
	else if (str[1] == 'b')
		ft_swap(b, 0);
	else
	{
		ft_swap(a, 0);
		ft_swap(b, 0);
	}
}

void	ft_r(t_stack **a, t_stack **b, char *str)
{
	if (str[1] == 'a')
		ft_rotate(a, 0);
	else if (str[1] == 'b')
		ft_rotate(b, 0);
	else if (str[1])
	{
		ft_rotate(a, 0);
		ft_rotate(b, 0);
	}
}

void	ft_rr(t_stack **a, t_stack **b, char *str)
{
	if (str[2] == 'a')
		ft_reverse(a, 0);
	else if (str[2] == 'b')
		ft_reverse(b, 0);
	else
	{
		ft_reverse(a, 0);
		ft_reverse(b, 0);
	}
}

t_stack	*ft_init_stack(int ac, char **av)
{
	int			i;
	t_stack		*a;
	t_stack		*tmp;

	i = 0;
	a = NULL;
	if (ac)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			return (NULL);
		a = tmp;
		a->data = ft_atoi(av[i]);
		while (++i < ac)
		{
			tmp->next = (t_stack *)malloc(sizeof(t_stack));
			if (!tmp->next)
				return (NULL);
			tmp = tmp->next;
			tmp->data = ft_atoi(av[i]);
		}
		tmp->next = NULL;
		ft_check_duplicate(a);
	}
	return (a);
}
