/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 03:21:51 by abort             #+#    #+#             */
/*   Updated: 2021/04/22 03:42:44 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_stack *a)
{
    int tmp;

	tmp = a->data;
	a->data = a->next->data;
	a->next->data = tmp;
}

void    ft_push(t_stack *dest, t_stack *src)
{
    t_stack *tmp;
	if (src)
	{
		tmp = src;
		src = src->next;
		tmp->next = dest;
		dest = tmp;
	}
}

void	ft_rotate(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*head;

	head = a;
	a = a->next;
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	tmp->next->next = NULL;
}

void	ft_reverse(t_stack **a)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last; 
	printf("=======lastee===\n");
	ft_print_stack(*a);
	
}

void ft_checker(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (!b)
	{
		ft_putstr("ko\n");
		ft_exit();
	}
	tmp = a;
	while (tmp)
	{
		if (tmp->next && tmp->data > tmp->next->data)
		{
			ft_putstr("ko\n");
			ft_exit();
		}
		tmp = tmp->next;
	}
	ft_putstr("OK\n");
}

void	ft_print_stack(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while(tmp)
	{
		printf("%d\n",tmp->data);
		tmp = tmp->next;
	}
}