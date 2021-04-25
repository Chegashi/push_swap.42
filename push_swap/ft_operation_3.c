/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:55:56 by abort             #+#    #+#             */
/*   Updated: 2021/04/25 04:05:21 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free_stack(t_stack *stack)
{
    t_stack *tmp;
    
    while(stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}

void    ft_free(t_push_swap *p_checker)
{
    char *cmd;

    cmd = p_checker->cmd[0];
    ft_free_stack(p_checker->a);
    ft_free_stack(p_checker->b);
    while (cmd)
    {
        free(cmd);
        cmd++;
    }
}
