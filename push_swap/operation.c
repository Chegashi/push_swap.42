/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:28:53 by mochegri          #+#    #+#             */
/*   Updated: 2021/03/29 19:43:07 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap(t_stack *a)
{
	int tmp;

	if (a && a->next)
	{
		tmp = a->data;
		a->data = a->next->data;
		a->next->data = tmp;
	}
}

void		ft_push(t_stack *a, t_stack *b)
{
	t_stack		*tmp;

	tmp = b;
	b = b->next;
	tmp->next = a;
	a = tmp;
}

void        ft_rotate(void)
{
    
}

void		ft_reverse(t_stack *a)
{
	t_stack *tmp;
	t_stack *last;

	last = a;
	while (!(last->next->next))
		last = last->next;
	
}
