/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:41:24 by mochegri          #+#    #+#             */
/*   Updated: 2021/05/15 11:59:12 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_unshanking(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if (ft_nbr_shunk(*b, (*b)->shunk) == 1)
			ft_push(a, b, 'a');
		else if (ft_nbr_shunk(*b, (*b)->shunk) == 2)
		{
			if ((*b)->data <= (*b)->next->data)
				ft_swap(*b, 'b');
			ft_push(a, b, 'a');
			ft_push(a, b, 'a');
		}
		else
			ft_b_divide(a, b);
	}
}

void	ft_shanking(t_stack **a, t_stack **b, int start, int nbr_ra)
{
	int	pivot;
	int	shunk;

	shunk = (*a)->shunk;
	while (!ft_is_sorted(*a) && ft_nbr_shunk(*a, (*a)->shunk) > 2)
	{
		shunk++;
		nbr_ra = 0;
		pivot = ft_get_the_midlle(*a, (*a)->shunk);
		while (ft_chr_less_pivot(*a, pivot))
		{
			if (ft_help_norm(a, b, pivot, shunk))
			{
				ft_rotate(a, 'a');
				nbr_ra++;
			}
		}
		while (!start && nbr_ra--)
			ft_reverse(a, 'a');
	}
	if (!ft_is_sorted(*a))
		ft_swap(*a, 'a');
}

int	ft_help_norm(t_stack **a, t_stack **b, int pivot, int shunk)
{
	if ((*a)->data < pivot)
	{
		ft_push(b, a, 'b');
		(*b)->shunk = shunk;
		return (0);
	}
	return (1);
}

void	ft_b_divide(t_stack **a, t_stack **b)
{
	int	pivot;
	int	rb_nbr;

	rb_nbr = 0;
	pivot = 0;
	pivot = ft_get_the_midlle(*b, (*b)->shunk);
	while (ft_chr_grender_pivot(*b, pivot))
	{
		if ((*b)->data > pivot)
		{
			ft_push(a, b, 'a');
			(*a)->shunk++;
			(*a)->shunk++;
		}
		else
		{
			ft_rotate(b, 'b');
			rb_nbr++;
		}
	}
	while (rb_nbr--)
		ft_reverse(b, 'b');
	ft_shanking(a, b, 0, 0);
}
