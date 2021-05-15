/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:55:56 by abort             #+#    #+#             */
/*   Updated: 2021/05/15 14:42:43 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	ft_free(t_push_swap *p_checker)
{
	char	**tmp;

	tmp = p_checker->cmd;
	ft_free_stack(p_checker->a);
	ft_free_stack(p_checker->b);
	while (*(p_checker->cmd))
	{
		free(*(p_checker->cmd));
		p_checker->cmd++;
	}
	free(tmp);
}

void	ft_check_duplicate(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*iter;

	tmp = a;
	while (tmp)
	{
		iter = a;
		while (iter)
		{
			if (tmp->data == iter->data && tmp != iter)
				ft_exit();
			iter = iter->next;
		}
		tmp = tmp->next;
	}
}

int	ft_len_stack(t_stack *a)
{
	int	len;
	int	shunk;

	shunk = a->shunk;
	len = 0;
	while (a && shunk == a->shunk)
	{
		len++;
		a = a->next;
	}
	return (len);
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
