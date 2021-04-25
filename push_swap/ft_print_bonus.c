/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:51:32 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/25 04:35:58 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_init(t_stack a)
{
	t_stack	*iter;

	ft_putstr("__________________________________________________\n");
	ft_putstr("Init a and b:\n");
	iter = &a;
	while (iter)
	{
		ft_putnbr(iter->data);
		ft_putstr("\n");
		iter = iter->next;
	}
	ft_putstr("-\t\t\t\t\t-\na\t\t\t\t\tb\n");
}

void	ft_print_stack(t_stack *a, t_stack *b, char *str)
{
	t_stack	*iter_a;
	t_stack	*iter_b;

	ft_putstr("__________________________________________________\n");
	ft_putstr("Exec ");
	ft_putstr(str);
	ft_putstr(":\n");
	iter_a = a;
	iter_b = b;
	while (iter_a || iter_b)
	{
		if (iter_a)
			ft_putnbr(iter_a->data);
		ft_putstr("-\t\t\t\t\t");
		if (iter_b)
			ft_putnbr(iter_b->data);
		ft_putstr("\n");
		iter_a = iter_a->next;
		iter_b = iter_b->next;
	}
	ft_putstr("-\t\t\t\t\t-\na\t\t\t\t\tb\n");
}
