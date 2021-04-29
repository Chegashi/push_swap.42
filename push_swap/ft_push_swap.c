/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:46:29 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/29 17:49:26 by mochegri         ###   ########.fr       */
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
	ft_free(&p_swap);
    return (0);
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

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	array =  (int *)malloc(sizeof(int) * len);
	while (a)
	{
		array[i++] = a->data;
		a = a->next;
	}
		pivot = array[len / 2 - 1];
	free(array);
	return (pivot);
}