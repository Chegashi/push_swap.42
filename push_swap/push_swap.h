/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:34 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/16 22:33:16 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP_H
# define __PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

int                 ft_operation(t_stack *a, t_stack *b, char *oper);
void				ft_swap(t_stack *a);
void				ft_push(t_stack *a, t_stack * b);
void				ft_rotate(t_stack *a);
void				ft_reverse(t_stack *a);
void				ft_s(t_stack *a, t_stack *b, char *str);
void				ft_p(t_stack *a, t_stack *b, char *str);
void    			ft_r(t_stack *a, t_stack *b, char *str);
void				ft_rr(t_stack *a, t_stack *b, char *str);
void				ft_check_duplicate(t_stack *a);
void				ft_read_cmd(t_stack *a, t_stack *b);
void				ft_check_oper(char *str);
void				ft_cmd(t_stack *a, t_stack *b, char *oper);
void				ft_checker(t_stack *a, t_stack *b);
t_stack				*ft_init_stack(int ac, char **av);

# endif
