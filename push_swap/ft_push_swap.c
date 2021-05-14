/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:46:29 by mochegri          #+#    #+#             */
/*   Updated: 2021/05/14 14:49:53 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_push_swap		p_swap;
	
	if (ac > 2)
	{
		av++;
		ac--;
		p_swap.a = ft_init_stack(ac, av);
		p_swap.b = NULL;
		ft_init_shunk(p_swap.a);
		ft_quick_sort(&(p_swap.a), &(p_swap.b));
		ft_free_stack(p_swap.a);
	}
    return (0);
}

void	ft_quick_sort(t_stack **a, t_stack **b)
{
	if (ft_is_sorted(*a) && !(*b))
		return;
	ft_shanking(a, b, 1);
	ft_unshanking(a, b);
}

void	ft_shanking(t_stack **a, t_stack **b, int start)
{
	int  pivot;
	int shunk;
	int nbr_ra;

	shunk = (*a)->shunk;
	while (!ft_is_sorted(*a) && ft_nbr_shunk(*a, (*a)->shunk) > 2)
	{
		shunk++;
		nbr_ra = 0;
		pivot = ft_get_the_midlle(*a, (*a)->shunk);
		while (ft_chr_less_pivot(*a, pivot))
			if ((*a)->data < pivot)
			{
				ft_push(b, a, 'b');
				(*b)->shunk = shunk;
			}
			else if (ft_bottum_stack(*a) < pivot)
			{
				ft_reverse(a, 'a');
				ft_push(b, a, 'b');
				(*b)->shunk = shunk;
			}
			else
			{
				ft_rotate(a, 'a');
				nbr_ra++;
			}
		while (!start && nbr_ra--)
			ft_reverse(a, 'a');
	}
	if (!ft_is_sorted(*a))
		ft_swap(*a, 'a');
}

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;
	int tmp;

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
	int len;
	int	*array;
	int i;
	int pivot;

	i = 0;
	shunk = a->shunk;
	len = ft_len_stack(a);
	array =  (int *)malloc(sizeof(int) * len);
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
	t_stack *sp;

	sp = a;
	while (sp)
	{
		if (sp->data < pivot)
			return (1);
		sp = sp->next;
	}
	return (0);
}

int	ft_bottum_stack(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->data);

}

void	ft_unshanking(t_stack **a, t_stack **b)
{
	int	pivot = 0;
	int rb_nbr;
	while (*b)
	{
		if (ft_nbr_shunk(*b, (*b)->shunk) == 1)
			ft_push(a, b, 'a');
		else if (ft_nbr_shunk(*b, (*b)->shunk) == 2)
		{
			if ((*b)->data < (*b)->next->data)
				ft_swap(*b, 'b');
			ft_push(a, b, 'a');
			ft_push(a, b ,'a');
		}
		else
		{
			rb_nbr = 0;
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
			ft_shanking(a, b, 0);
		}
	}
}

int	ft_nbr_shunk(t_stack *a, int shunk)
{
	int n;
	
	n = 0;
	while (a && a->shunk == shunk)
	{
		n++;
		a =  a->next;
	}
	return (n);
}

int	ft_chr_grender_pivot(t_stack *a, int pivot)
{
	t_stack *sp;
	int shunk;

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