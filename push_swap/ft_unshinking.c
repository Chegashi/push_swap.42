/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unshinking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:51:45 by mochegri          #+#    #+#             */
/*   Updated: 2021/05/14 18:51:56 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bottum_stack(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->data);
}

int	ft_nbr_shunk(t_stack *a, int shunk)
{
	int	n;

	n = 0;
	while (a && a->shunk == shunk)
	{
		n++;
		a = a->next;
	}
	return (n);
}

int	ft_chr_grender_pivot(t_stack *a, int pivot)
{
	int		shunk;
	t_stack	*sp;

	shunk = a->shunk;
	sp = a;
	while (sp && sp->shunk == shunk)
	{
		if (sp->data > pivot)
			return (1);
		sp = sp->next;
	}
	return (0);
}

void	ft_sort_3(t_stack **a)
{
	int	c1;
	int	c2;
	int	c3;

	c1 = (*a)->data;
	c2 = (*a)->next->data;
	c3 = (*a)->next->next->data;
	if (c1 > c2 && c2 < c1 && c1 < c3)
		ft_swap(*a, 'a');
	else if (c1 > c2 && c2 > c3 && c1 > c3)
	{
		ft_swap(*a, 'a');
		ft_reverse(a, 'a');
	}
	else if (c1 > c2 && c2 < c3 && c1 > c3)
		ft_rotate(a, 'a');
	else if (c1 < c2 && c2 > c3 && c1 < c3)
	{
		ft_swap(*a, 'a');
		ft_reverse(a, 'a');
	}
	else
		ft_reverse(a, 'a');
}
