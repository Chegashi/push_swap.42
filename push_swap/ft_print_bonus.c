/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:51:32 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/24 16:24:13 by mochegri         ###   ########.fr       */
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