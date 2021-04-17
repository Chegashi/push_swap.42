/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:41:19 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/16 22:58:13 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_oper(char *str)
{
	if (!(ft_strcmp("sa", str) || ft_strcmp("sb", str) ||
		ft_strcmp("ss", str) || ft_strcmp("pa", str) ||
		ft_strcmp("pb", str) || ft_strcmp("ra", str) ||
		ft_strcmp("rb", str) || ft_strcmp("rr", str) ||
		ft_strcmp("rra", str) || ft_strcmp("rrb", str) ||
		ft_strcmp("rr", str)))
		ft_exit();
}

void	ft_s(t_stack *a, t_stack *b, char *str)
{
	if (str[1] == 'a')
		ft_swap(a);
	else if (str[1] == 'b')
		ft_swap(b);
	else
	{
		ft_swap(a);
		ft_swap(b);
	}
}

void	ft_p(t_stack *a, t_stack *b, char *str)
{
	if (str[1] == 'a')
		ft_push(a, b);
	else
		ft_push(b, a);
}

void	ft_r(t_stack *a, t_stack *b, char *str)
{
	if (str[1] == 'a')
		ft_rotate(a);
	else if (str[1] == 'b')
		ft_rotate(b);
	else
	{
		ft_rotate(a);
		ft_rotate(b);
	}
}

void	ft_rr(t_stack *a, t_stack *b, char *str)
{
	if (str[1] == 'a')
		ft_reverse(a);
	else if (str[1] == 'b')
		ft_reverse(b);
	else
	{
		ft_reverse(a);
		ft_reverse(b);
	}
}
