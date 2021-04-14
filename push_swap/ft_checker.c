/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:28 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/14 17:38:39 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	if (ac > 1)
	{
		a = ft_init_stack(ac, av);
		b = NULL;
		while (a)
		{
			printf("%d\n", a->data);
			a = a->next;
		}
		
	// ft_read_commend(a, b);
	// ft_checker(a, b);
	}
	return (0);
}

t_stack			*ft_init_stack(int ac, char **av)
{
	int			i;
	t_stack		*a;
	t_stack		*tmp;

	i = 1;
	tmp = (t_stack*)malloc(sizeof(t_stack));
	a = tmp;
	a->data = ft_atoi(av[i]);
	while (++i < ac)
	{
		tmp->next = (t_stack*)malloc(sizeof(t_stack));
		tmp = tmp->next;
		tmp->data = ft_atoi(av[i]);
	}
	tmp->next = NULL;
	return (a);
}



// int				ft_operation(t_stack *a, t_stack *b, char *oper)
// {
// 	if (ft_check_oper(oper))
// 	{
// 		if (*oper == 's')
// 			ft_s(a, b, oper);
// 		else if (*oper == 'p')
// 			ft_p(a, b, oper);
// 		else if (*oper == 'r' && oper[1] == 'r')
// 			ft_rr(a, b, oper);
// 		else
// 			ft_r(a, b, oper);
// 		return (1);
// 	}
// 	else if (ft_strcmp(oper, ""))
// 		return (0);
// 	else
// 		ft_exit();
// }

// int				ft_check_oper(char *str)
// {
// 	if (!(ft_strcmp("sa", str) && ft_strcmp("sb", str) &&
// 		ft_strcmp("ss", str) && ft_strcmp("pa", str) &&
// 		ft_strcmp("pb", str) && ft_strcmp("ra", str) &&
// 		ft_strcmp("rb", str) && ft_strcmp("rr", str) &&
// 		ft_strcmp("rra", str) && ft_strcmp("rrb", str) &&
// 		ft_strcmp("rr", str)))
// 		return (0);
// 	return (1);
// }
