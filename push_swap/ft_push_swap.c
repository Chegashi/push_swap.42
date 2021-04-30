/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:46:29 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/30 17:47:17 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int				pivot;
	t_push_swap		p_swap;

	av++;
	ac--;
	p_swap.a = ft_init_stack(ac, av);
	p_swap.b = NULL;
	ft_init_rank(p_swap.a);
	pivot = ft_get_the_midlle(p_swap.a);
	
	ft_free_stack(p_swap.a);
    return (0);
}

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;
	int tmp;

	i = size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j <= i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i--;
	}
}

void	ft_init_rank(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		tmp->rank = 0;
		tmp = tmp->next;
	}
}

int	ft_get_the_midlle(t_stack *a)
{
	int len;
	int	*array;
	int i;
	int pivot;
	t_stack *tmp;

	tmp = a;
	i = 0;
	len = ft_len_stack(a);
	array =  (int *)malloc(sizeof(int) * len);
	while (a)
	{
		array[i++] = tmp->data;
		tmp = tmp->next;
	}
	ft_sort_integer_table(array, len);
	pivot = array[len / 2];
	free(array);
	return (pivot);
}

void	ft_shanking(t_stack **a, t_stack **b)
{
	int shank;
	int pivot;
	t_stack *tmp;

	shank = 0;
	while (ft_len_stack(*a) > 2 || !ft_is_sorted(*a))
	{
		while (tmp)
		{
			/* code */
		}
		
	}
	
}