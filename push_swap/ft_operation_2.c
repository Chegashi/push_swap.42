/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 03:21:51 by abort             #+#    #+#             */
/*   Updated: 2021/05/01 17:44:38 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *a)
{
	int	tmp;

	if (ft_len_stack(a) > 1)
	{
		tmp = a->data;
		a->data = a->next->data;
		a->next->data = tmp;
	}
}

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	ft_rotate(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*head;

	if (*a && (*a)->next)
	{
		head = *a;
		*a = (*a)->next;
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = head;
		tmp->next->next = NULL;
	}
}

void	ft_reverse(t_stack **a)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *a;
		*a = last;
	}
}

int	ft_is_sorted(t_stack *a)
{
	while (a)
	{
		if (a->next && a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}
