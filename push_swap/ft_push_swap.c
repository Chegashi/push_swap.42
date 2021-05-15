/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:46:29 by mochegri          #+#    #+#             */
/*   Updated: 2021/05/15 11:40:29 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap		p_swap;

	av++;
	ac--;
	p_swap.a = ft_init_stack(ac, av);
	p_swap.b = NULL;
	ft_init_shunk(p_swap.a);
	ft_quick_sort(&(p_swap.a), &(p_swap.b));
	ft_free_stack(p_swap.a);
	return (0);
}

void	ft_quick_sort(t_stack **a, t_stack **b)
{
	if (ft_is_sorted(*a) && !(*b))
		return ;
	if (ft_len_stack(*a) == 3)
		ft_sort_3(a);
	else
	{
		ft_shanking(a, b, 1, 0);
		ft_unshanking(a, b);
	}
}

void	ft_sort_integer_table(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = size;
	while (--i >= 0)
	{
		j = -1;
		while (++j <= i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}

int	ft_get_the_midlle(t_stack *a, int shunk)
{
	int	len;
	int	*array;
	int	i;
	int	pivot;

	i = 0;
	shunk = a->shunk;
	len = ft_len_stack(a);
	array = (int *)malloc(sizeof(int) * len);
	while (a && a->shunk == shunk)
	{
		array[i++] = a->data;
		a = a->next;
	}
	ft_sort_integer_table(array, len);
	pivot = array[len / 2];
	free(array);
	return (pivot);
}

int	ft_chr_less_pivot(t_stack *a, int pivot)
{
	t_stack	*sp;

	sp = a;
	while (sp)
	{
		if (sp->data < pivot)
			return (1);
		sp = sp->next;
	}
	return (0);
}
