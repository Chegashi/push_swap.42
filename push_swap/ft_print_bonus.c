/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:51:32 by mochegri          #+#    #+#             */
/*   Updated: 2021/05/15 11:44:14 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_init(t_stack a)
{
	t_stack	*iter;

	ft_putchar_coef('*', 81);
	ft_putstr("\n");
	ft_putstr("|\t\t\t\tInit a and b:\t\t\t\t\t|\n");
	ft_putchar_coef('*', 81);
	ft_putstr("\n");
	ft_putstr("|\t\ta\t\t\t|\t\tb\t\t\t|\n");
	ft_putchar_coef('*', 81);
	ft_putstr("\n");
	iter = &a;
	while (iter)
	{
		ft_putstr("|");
		ft_putnbr(iter->data);
		ft_putstr("\t\t\t\t\t|\t\t\t\t\t|\n");
		iter = iter->next;
	}
	ft_putchar_coef('*', 81);
	ft_putstr("\n\n");
}

void	ft_print_stack(t_stack *a, t_stack *b, char *str)
{
	t_stack	*iter_a;
	t_stack	*iter_b;

	print_header(str);
	iter_a = a;
	iter_b = b;
	while (iter_a || iter_b)
	{
		write(1, "|", 1);
		if (iter_a)
		{
			ft_putnbr(iter_a->data);
			iter_a = iter_a->next;
		}
		else
			ft_putstr(" ");
		ft_putstr("\t\t\t\t\t|");
		if (iter_b)
		{
			ft_putnbr(iter_b->data);
			iter_b = iter_b->next;
		}
		ft_putstr("\t\t\t\t\t|\n");
	}
	ft_putchar_coef('*', 81);
}

void	ft_putchar_coef(char c, int nbr)
{
	while (nbr--)
		write(1, &c, 1);
}

void	print_header(char *str)
{
	write(1, "\n", 1);
	ft_putchar_coef('*', 81);
	ft_putstr("\n");
	ft_putstr("|\t\t\t\tExec : ");
	ft_putstr(str);
	ft_putstr("\t\t\t\t\t|\n");
	ft_putchar_coef('*', 81);
	ft_putstr("\n");
	ft_putstr("|\t\ta\t\t\t|\t\tb\t\t\t|\n");
	ft_putchar_coef('*', 81);
	ft_putstr("\n");
}

void	ft_checker(t_push_swap p_s)
{
	if (p_s.b || !ft_is_sorted(p_s.a))
	{
		ft_putstr("KO\n");
		ft_exit();
	}
	ft_putstr("OK\n");
}
