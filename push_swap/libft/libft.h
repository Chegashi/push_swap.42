/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:34 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/26 16:53:14 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *s);
int		ft_isdigit(int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	ft_exit(void);
char	**ft_split(char *s, char c);
void	ft_putnbr(int nb);
#endif
