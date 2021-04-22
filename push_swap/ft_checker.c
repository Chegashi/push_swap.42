/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:28 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/22 03:44:41 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		**cmd;

	if (ac > 1)
	{
		a = ft_init_stack(ac, av);
		b = NULL;
		cmd = ft_split(ft_read_cmd(), ' ');
		printf("==========\n");
		ft_print_stack(a);
		ft_reverse(&a);
		printf("=======ee===\n");
		ft_print_stack(a);
		//ft_checker(a, b);
		printf("%p%p\n",b, cmd);
	}
	return (0);
}

t_stack	*ft_init_stack(int ac, char **av)
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
	ft_check_duplicate(a);
	return (a);
}

void	ft_check_duplicate(t_stack *a)
{
	t_stack *tmp;
	t_stack *iter;

	tmp = a;
	while(tmp)
	{
		iter = a;
		while(iter)
		{
			if(tmp->data == iter->data && tmp != iter)
				ft_exit();
			iter = iter->next;
		}
		tmp = tmp->next;
	}
}

char	*ft_read_cmd(void)
{
	char *cmd;
	char *cmds;
	char *tmp;

	cmd = (char*)malloc(sizeof(char));
	cmds = ft_strdup("");
	while(1)
	{
		get_next_line(0, &cmd);
		ft_check_oper(cmd);
		if(!ft_strcmp(cmd, ""))
			break;
		tmp = ft_strjoin(cmds, cmd);
		free(cmds);
		cmds = tmp;
		tmp = ft_strjoin(cmds, " ");
		free(cmds);
		cmds = tmp;
	}
	free(cmd);
	return(cmds);
}

void	ft_cmd(t_stack *a, t_stack *b, char *oper)
{
	if (*oper == 's')
		ft_s(a, b, oper);
	else if (*oper == 'p')
		ft_p(a, b, oper);
	// else if (*oper == 'r' && oper[1] == 'r')
	// 	ft_rr(a, b, oper);
}
