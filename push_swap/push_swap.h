/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:34 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/30 01:22:58 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_stack
{
	int				data;
	int				rank;
	struct s_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	t_stack		*a;
	t_stack		*b;
	int			color;
	int			verbos;
	char		**cmd;
}	t_push_swap;


int					ft_operation(t_stack *a, t_stack *b, char *oper);
void				ft_swap(t_stack *a);
void				ft_push(t_stack **a, t_stack **b);
void				ft_rotate(t_stack **a);
void				ft_reverse(t_stack **a);
void				ft_s(t_stack *a, t_stack *b, char *str);
void				ft_p(t_stack **a, t_stack *b, char *str);
void				ft_r(t_stack **a, t_stack **b, char *str);
void				ft_rr(t_stack **a, t_stack **b, char *str);
void				ft_check_duplicate(t_stack *a);
char				*ft_read_cmd(void);
void				ft_check_oper(char *str);
void				ft_exec_cmd(t_push_swap *p_checker);
void				ft_checker(t_push_swap p_checker);
void				ft_print_stack(t_stack *a, t_stack *b, char *str);
void				ft_free(t_push_swap *p_checker);
void				ft_print_init(t_stack a);
void				ft_print_stack(t_stack *a, t_stack *b, char *str);;
void				ft_free_stack(t_stack *stack);
t_stack				*ft_init_stack(int ac, char **av);
void				ft_putchar_coef(char c, int nbr);
void				print_header(char *str);
int					ft_get_the_midlle(t_stack *a);
void				ft_init_rank(t_stack *a);
void				ft_sort_integer_table(int *tab, int size);
#endif
