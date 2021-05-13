/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:34 by mochegri          #+#    #+#             */
/*   Updated: 2021/05/13 15:59:48 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				shunk;
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
void				ft_swap(t_stack *a, int c);
void				ft_push(t_stack **a, t_stack **b, int c);
void				ft_rotate(t_stack **a, int c);
void				ft_reverse(t_stack **a, int c);
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
int					ft_get_the_midlle(t_stack *a, int shunk);
void				ft_init_shunk(t_stack *a);
void				ft_sort_integer_table(int *tab, int size);
int					ft_is_sorted(t_stack *a);
int					ft_len_stack(t_stack *a);
void				ft_quick_sort(t_stack **a, t_stack **b);
void	ft_shanking(t_stack **a, t_stack **b);
int	ft_chr_less_pivot(t_stack *a, int pivot);
int	ft_bottum_stack(t_stack *a);
void	ft_unshanking(t_stack **a, t_stack **b);
int	ft_nbr_shunk(t_stack *a, int shunk);
int	ft_get_max(t_stack *b, int shunk);
int	ft_chr_grender_pivot(t_stack *a, int pivot);

#endif
