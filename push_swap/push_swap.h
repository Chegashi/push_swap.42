/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:34 by mochegri          #+#    #+#             */
/*   Updated: 2021/03/29 18:58:50 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP_H
# define __PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct      s_stack
{
	int				data;
	struct s_stack  *next;
}					t_stack;

int                 ft_atoi(char *s);
int			        ft_isdigit(int c);
int                 ft_operation(t_stack *a, t_stack *b, char *oper);
void				ft_exit();
void				ft_putstr(char *str);
void				ft_s(t_stack *a, t_stack *b, char *str);
void        		ft_p(t_stack *a, t_stack *b, char *str);
void    			ft_r(t_stack *a, t_stack *b, char *str);
void				ft_rr(t_stack *a, t_stack *b, char *str);
t_stack				*ft_init_stack(int ac, char **av);

# endif
