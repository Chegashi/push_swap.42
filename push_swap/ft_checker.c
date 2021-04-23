/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:28 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/23 17:45:02 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap		p_checker;

	av++;
	ac--;
	if ((p_checker.color = !ft_strcmp("-c", av[1])) ||
			(p_checker.verbos = !ft_strcmp("-v", av[1])))
	{
		p_checker.verbos = 1;
		av++;
	}
	p_checker.a = ft_init_stack(ac, av);
	p_checker.b = NULL;
	p_checker.cmd = ft_split(ft_read_cmd(), ' ');
	ft_exec_cmd(&p_checker);
	ft_checker(p_checker);
	return (0);
}

t_stack	*ft_init_stack(int ac, char **av)
{
	int			i;
	t_stack		*a;
	t_stack		*tmp;

	i = 0;
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
	while(get_next_line(0, &cmd))
	{	
		ft_check_oper(cmd);
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

void	ft_exec_cmd(t_push_swap *p_checker)
{
	char*	cmd;

	cmd = p_checker.cmd[0];
	while (cmd)
	{
		if (*cmd == 's')
			ft_s(p_checker.a, p_checker.b, cmd[1]);
		else if (*cmd == 'p')
			ft_p(p_checker.a, p_checker.b, cmd[1]);
		else if (*cmd == 'r' && cmd[1] == 'r')
			ft_rr(p_checker.a, p_checker.b, cmd[1]);
		else
			ft_r(p_checker.a, p_checker.b, cmd[1]);
	}
	
}
