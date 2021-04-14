/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:35:57 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/14 17:39:41 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int	ft_atoi(char *s)
{
	long long	nbr;
	int		signe;

	nbr = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '+')
			signe = 1;
		else
			signe = -1;
		s++;
	}
	while (*s)
	{
		if (!ft_isdigit(*s) || nbr > 2147483647 || nbr < -2147483648)
			ft_exit();
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	printf("[%lld]\n", nbr);
	return ((int)nbr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_exit(void)
{
	ft_putstr("Error\n");
	exit(EXIT_SUCCESS);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
