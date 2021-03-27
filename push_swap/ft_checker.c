/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:28 by mochegri          #+#    #+#             */
/*   Updated: 2021/03/27 18:21:00 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = ft_init_stack(ac, av);
    b = NULL;
    // while ()
    // {
    //     /* code */
    // }
    
    return (0);
}

t_stack     *ft_init_stack(int ac, char **av)
{
    int i;
    t_stack *a;
    t_stack *tmp;

    i = 0;

    while (++i < ac)
    {
        printf("---%d", a->data);
        tmp = (t_stack*)malloc(sizeof(t_stack));
        if (i == 1)
            a = tmp;
        tmp->data = ft_atoi(av[i]);
        tmp = tmp->next;
        tmp = a;
    }
    while (a)
    {
        printf("%d\n",a->data);
        a = a->next;
    }
    
    return (a);
}

int			ft_atoi(char *s)
{
	long    nbr;
    int     signe;

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
        if(!ft_isdigit(*s) || nbr > 2147483647 || nbr < -2147483648)
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

int         ft_exit(char *str)
{
    ft_putstr(str);
    exit(EXIT_SUCCESS);
    return (0);
}

void	    ft_putstr(char *str)
{
	while (str)
		write(1, &(*str++), 1);
}

void        ft_sa(void)
{
    
}

void        ft_sb(void)
{
    
}

void        ft_ss(void)
{
    
}

void        ft_pa(void)
{
    
}

void        ft_pb(void)
{
    
}

void        ft_ra(void)
{
    
}

void        ft_rb(void)
{
    
}

void        ft_rr(void)
{
    
}

void        ft_rra(void)
{
    
}

void        ft_rrb(void)
{
    
}

void        ft_rrr(void)
{
    
}

