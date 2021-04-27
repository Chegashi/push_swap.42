/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:28 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/27 08:26:27 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap		p_checker;

	av++;
	ac--;
	p_checker.color = !ft_strcmp("-c", *av);
	p_checker.verbos = !ft_strcmp("-v", *av);
	if (p_checker.color || p_checker.verbos)
	{
		p_checker.verbos = 1;
		av++;
		ac--;
	}
	p_checker.a = ft_init_stack(ac, av);
	p_checker.b = NULL;
	p_checker.cmd = ft_split(ft_read_cmd(), ' ');
	ft_exec_cmd(&p_checker);
	ft_checker(p_checker);
	ft_free(&p_checker);
	return (0);
}

t_stack	*ft_init_stack(int ac, char **av)
{
	int			i;
	t_stack		*a;
	t_stack		*tmp;

	i = 0;
	a = NULL;
	if (ac)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			return (NULL);
		a = tmp;
		a->data = ft_atoi(av[i]);
		while (++i < ac)
		{
			tmp->next = (t_stack *)malloc(sizeof(t_stack));
			if (!tmp->next)
				return (NULL);
			tmp = tmp->next;
			tmp->data = ft_atoi(av[i]);
		}
		tmp->next = NULL;
		ft_check_duplicate(a);
	}
	return (a);
}

void	ft_check_duplicate(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*iter;

	tmp = a;
	while (tmp)
	{
		iter = a;
		while (iter)
		{
			if (tmp->data == iter->data && tmp != iter)
				ft_exit();
			iter = iter->next;
		}
		tmp = tmp->next;
	}
}

char	*ft_read_cmd(void)
{
	char	*cmd;
	char	*cmds;
	char	*tmp;

	cmd = (char *)malloc(sizeof(char));
	cmds = ft_strdup("");
	while (get_next_line(0, &cmd))
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
	return (cmds);
}

void	ft_exec_cmd(t_push_swap *p_checker)
{
	char	**cmd;

	cmd = p_checker->cmd;
	if (p_checker->verbos)
		ft_print_init(*(p_checker->a));
	while (*cmd)
	{
		if (**cmd == 's')
			ft_s(p_checker->a, p_checker->b, *cmd);
		else if (**cmd == 'p' && *((*cmd) + 1) == 'a')
			ft_push(&(p_checker->a), &(p_checker->b));
		else if (**cmd == 'p' && *((*cmd) + 1) == 'b')
			ft_push(&(p_checker->b), &(p_checker->a));
		else if (**cmd == 'r' && *((*cmd) + 1) == 'r' && *((*cmd) + 2))
			ft_rr(&(p_checker->a), &(p_checker->b), *cmd);
		else
			ft_r(&(p_checker->a), &(p_checker->b), *cmd);
		if (p_checker->verbos)
			ft_print_stack(p_checker->a, p_checker->b, *cmd);
		// else if (p_checker->verbos)
		// 	ft_print_stack(p_checker->a, p_checker->b, *cmd);
		cmd++;
		if (p_checker->verbos)
			write(1, "\n\n", 1);
	}
}
