/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:46:29 by mochegri          #+#    #+#             */
/*   Updated: 2021/05/06 09:57:56 by mochegri         ###   ########.fr       */
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
		t_stack *t;
		// t = p_swap.a;
		// while (t)
		// {
		// 	printf("[%d]\n", t->shunk);
		// 	t = t->next;
		// }
		t = p_swap.b;
		while (t)
		{
			printf("%d  {%d}\n",t->data, t->shunk);
			t = t->next;
		}
		ft_free_stack(p_swap.a);
	}
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

void	ft_init_shunk(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		tmp->shunk = 0;
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
	tmp = a;
	len = ft_len_stack(tmp);
	array =  (int *)malloc(sizeof(int) * len);
	while (tmp)
	{
		array[i++] = tmp->data;
		tmp = tmp->next;
	}
	ft_sort_integer_table(array, len);
	pivot = array[len / 2];
	free(array);
	return (pivot);
}

void	ft_quick_sort(t_stack **a, t_stack **b)
{
	if (ft_is_sorted(*a) && !(*b))
		return;
	ft_shanking(a, b);
	ft_unshanking(a, b);
}

void	ft_shanking(t_stack **a, t_stack **b)
{
	int shank;
	int  pivot;

	shank = 0;
	while (ft_len_stack(*a) > 2)
	{
		shank++;
		pivot = ft_get_the_midlle(*a);
		while (ft_chr_less_pivot(*a, pivot))
		{
			if ((*a)->data < pivot)
			{
				ft_push(b, a);
				write(1, "pb\n", 3);
				(*b)->shunk = shank;
			}
			else if (ft_bottum_stack(*a) < pivot)
			{
				ft_reverse(a);
				ft_push(b, a);
				write(1, "rra\npb\n", 7);
				(*b)->shunk = shank;
			}
			else
			{
				ft_rotate(a);
				write(1, "ra\n", 3);
			}
		}
	}
	if (!ft_is_sorted(*a))
	{
		ft_swap(*a);
		write(1, "sa\n", 3);
	}
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
	int	curent_shunk;
	int	max;
	int nbr_ra;

	while (*b)
	{
		nbr_ra = 0;
		curent_shunk = (*b)->shunk;
		if (ft_nbr_shunk(*b, curent_shunk) == 1)
		{
			ft_push(a, b);
			write(1, "pa\n", 3);
		}
		else if (ft_nbr_shunk(*b, curent_shunk) == 2)
		{
			if ((*b)->data < (*b)->next->data)
			{
				ft_swap(*b);
				write(1, "sb\n", 3);
			}
			else
			{
				ft_push(a, b);
				ft_push(a, b);
				write(1, "pa\npa\n", 6);
			}
		}
		else
		{
			max = ft_get_max(*b, curent_shunk);
			while ((*b)->data != max)
			{
				ft_rotate(b);
				write(1, "rb\n", 3);
				nbr_ra++;
			}
			ft_push(a, b);
			write(1, "pa\n", 3);
			while (nbr_ra--)
			{
				ft_reverse(b);
				write(1, "rrb\n", 4);
			}
		}
	}
}

int	ft_nbr_shunk(t_stack *a, int shunk)
{
	int n;
	t_stack *tmp;
	
	n = 0;
	tmp = a;
	while (tmp && tmp->shunk == shunk)
	{
		n++;
		tmp =  tmp->next;
	}
	return (n);
}

int	ft_get_max(t_stack *b, int shunk)
{
	int n;
	t_stack *tmp;

	tmp = b;
	n = -2147483648;
	while (tmp)
	{
		if(tmp->shunk == shunk && tmp->data > n)
			n = tmp->data;
		tmp =  tmp->next;
	}
	return (n);
}