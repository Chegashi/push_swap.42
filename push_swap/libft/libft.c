/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:35:57 by mochegri          #+#    #+#             */
/*   Updated: 2021/03/30 14:52:41 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			ft_atoi(char *s)
{
	long	nbr;
	int		signe;

	nbr = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '+')
			signe = 1;
		else
			signe = 1;
		s++;
	}
	while (*s)
	{
		if (!ft_isdigit(*s) || nbr > 2147483647 || nbr < -2147483648)
			ft_exit("ERROR\n");
		nbr = nbr * 10 + *s - '0';
		s++;
	}
	return ((int)nbr);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void		ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
