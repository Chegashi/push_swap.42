/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:28 by mochegri          #+#    #+#             */
/*   Updated: 2021/05/13 17:19:44 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap		p_checker;

	av++;
	if (--ac)
	{
		p_checker.color = !ft_strcmp("-c", *av);
		p_checker.verbos = !ft_strcmp("-v", *av);
		if (p_checker.color || p_checker.verbos)
		{
			p_checker.verbos = 1;
			av++;
			ac--;
		}
	}
	if(ac)
	{
		p_checker.a = ft_init_stack(ac, av);
		ft_init_shunk(p_checker.a);
		p_checker.b = NULL;
		p_checker.cmd = ft_split(ft_read_cmd(), ' ');
		ft_exec_cmd(&p_checker);
		ft_checker(p_checker);
		ft_free(&p_checker);
	}
	return (0);
}

char	*ft_read_cmd(void)
{
	char	cmd[10];
	char	*cmds;
	char	*tmp;

	*cmd = 0;
	cmds = ft_strdup("");
	while (1)
	{
		cmd[read(0, cmd, 5) - 1] = 0;
		if (!(*cmd))
			break;
		ft_check_oper(cmd);
		tmp = ft_strjoin(cmds, cmd);
		free(cmds);
		cmds = tmp;
		tmp = ft_strjoin(cmds, " ");
		free(cmds);
		cmds = tmp;
	}
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
			ft_push(&(p_checker->a), &(p_checker->b), 0);
		else if (**cmd == 'p' && *((*cmd) + 1) == 'b')
			ft_push(&(p_checker->b), &(p_checker->a), 0);
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

void	ft_checker(t_push_swap p_s)
{
	if (p_s.b || !ft_is_sorted(p_s.a))
	{
		ft_putstr("KO[not sorted]\n");
		ft_exit();
	}
	ft_putstr("OK\n");
}
