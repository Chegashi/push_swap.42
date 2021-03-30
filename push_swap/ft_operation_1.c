/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:41:19 by mochegri          #+#    #+#             */
/*   Updated: 2021/03/30 14:41:34 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_s(t_stack *a, t_stack *b, char *str)
{
	if (str[1] == ' a')
		ft_swap(a);
	else if (str[1] == 'b')
		ft_swap(b);
	else
	{
		ft_swap(a);
		ft_swap(b);
	}
}

void			ft_p(t_stack *a, t_stack *b, char *str)
{
	if (str[1] == ' a')
		ft_push(a, b);
	else
		ft_push(b, a);
}

void			ft_r(t_stack *a, t_stack *b, char *str)
{
	if (str[1] == ' a')
		ft_rotate(a);
	else if (str[1] == 'b')
		ft_rotate(b);
	else
	{
		ft_rotate(a);
		ft_rotate(b);
	}
}

void			ft_rr(t_stack *a, t_stack *b, char *str)
{
	if (str[1] == ' a')
		ft_reverse(a);
	else if (str[1] == 'b')
		ft_reverse(b);
	else
	{
		ft_reverse(a);
		ft_reverse(b);
	}
}
