/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 03:21:51 by abort             #+#    #+#             */
/*   Updated: 2021/04/16 22:39:52 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_stack *a)
{
    int tmp;

	tmp = a->data;
	a->data = a->next->data;
	a->next->data = tmp;
}

void    ft_push(t_stack *a, t_stack * b)
{
    t_stack *tmp;

	tmp = b;
	b = b->next;
	tmp->next = a;
	a = tmp;
}

void	ft_rotate(t_stack *a)
{
	//
}

void	ft_reverse(t_stack *a)
{
	//
}

void ft_checker(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (!b)
		ft_putstr("ko\n");
		ft_exit();
	tmp = a;
	while (tmp)
	{
		if (tmp->next && tmp->data > tmp->next->data)
		{
			ft_putstr("ko\n");
			ft_exit();
		}
		tmp = tmp->next;
	}
	ft_putstr("OK\n");
}