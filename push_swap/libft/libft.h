/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:34 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/16 01:49:41 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int			ft_atoi(char *s);
int			ft_isdigit(int c);
int         ft_strcmp(char *s1, char *s2);
void		ft_putstr(char *str);
void		ft_exit(void);

# endif
