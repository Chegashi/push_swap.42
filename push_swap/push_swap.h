/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:34 by mochegri          #+#    #+#             */
/*   Updated: 2021/03/27 18:19:19 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP_H
# define __PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
typedef struct  s_stack
{
    int data;
    struct s_stack  *next;
}               t_stack;

int			ft_atoi(char *s);
int			ft_isdigit(int c);
int         ft_exit(char *str);
void	    ft_putstr(char *str);
t_stack     *ft_init_stack(int ac, char **av);

# endif