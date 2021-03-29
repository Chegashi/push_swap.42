/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:28 by mochegri          #+#    #+#             */
/*   Updated: 2021/03/29 19:31:03 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int ac, char **av)
{
	int			to_read;
	char		*oper;
	t_stack		*a;
	t_stack		*b;

	to_read = 1;
	if (ac < 2)
		ft_exit();
	oper = (char*)malloc(sizeof(char*));
	a = ft_init_stack(ac, av);
	b = NULL;
	while (to_read && ft_get_next_line(0, oper))
		to_read = ft_operation(a, b, oper);
	ft_checker(a, b);
	return (0);
}

t_stack			*ft_init_stack(int ac, char **av)
{
	int			i;
	t_stack		*a;
	t_stack		**tmp;

	i = 0;
	a = *tmp;
	while (++i < ac)
	{
		*tmp = (t_stack*)malloc(sizeof(t_stack));
		(*tmp)->data = ft_atoi(av[i]);
		(*tmp) = (*tmp)->next;
	}
	tmp = NULL;
	return (a);
}

void			ft_exit(void)
{
	ft_putstr("Error\n");
	exit(EXIT_SUCCESS);
}

int				ft_operation(t_stack *a, t_stack *b, char *oper)
{
	if (ft_check_oper(oper))
	{
		if (*oper == 's')
			ft_s(a, b, oper);
		else if (*oper == 'p')
			ft_p(a, b, oper);
		else if (*oper == 'r' && oper[1] == 'r')
			ft_rr(a, b, oper);
		else
			ft_r(a, b, oper);
		return (1);
	}
	else if (ft_strcmp(oper, ""))
		return (0);
	else
		ft_exit();
}

int				ft_check_oper(char *str)
{
	if (!(ft_strcmp("sa", str) && ft_strcmp("sb", str) &&
		ft_strcmp("ss", str) && ft_strcmp("pa", str) &&
		ft_strcmp("pb", str) && ft_strcmp("ra", str) &&
		ft_strcmp("rb", str) && ft_strcmp("rr", str) &&
		ft_strcmp("rra", str) && ft_strcmp("rrb", str) &&
		ft_strcmp("rr", str)))
		return (0);
	return (1);
}

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

void    ft_r(t_stack *a, t_stack *b, char *str)
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
