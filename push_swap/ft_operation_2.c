/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 03:21:51 by abort             #+#    #+#             */
/*   Updated: 2021/04/24 17:08:59 by mochegri         ###   ########.fr       */
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

void    ft_push(t_stack *dest, t_stack *src)
{
    t_stack *tmp;
	if (src)
	{
		tmp = src;
		src = src->next;
		tmp->next = dest;
		dest = tmp;
	}
}

void	ft_rotate(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*head;

	head = a;
	a = a->next;
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	tmp->next->next = NULL;
}

void	ft_reverse(t_stack *a)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = a;
	a = last; 	
}

void ft_checker(t_push_swap p_s)
{
	t_stack	*tmp;

	if (!p_s.b)
	{
		ft_putstr("ko\n");
		ft_exit();
	}
	tmp = p_s.a;
	while (tmp)
	{
		if (tmp->next && tmp->data > tmp->next->data)
		{
			ft_putstr("KO\n");
			ft_exit();
		}
		tmp = tmp->next;
	}
	ft_putstr("OK\n");
}
