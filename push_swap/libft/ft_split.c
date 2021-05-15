/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:35:36 by mochegri          #+#    #+#             */
/*   Updated: 2021/05/15 11:51:41 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	word_nbr( char *s, char c)
{
	int	count;

	count = 0;
	if (*s)
		count++;
	while (*s)
	{
		if (*s == c && *(s + 1))
			count++;
		s++;
	}
	return (count);
}

int	len_wrd( char *s, char c)
{
	char	*len;

	len = s;
	while (*len && *len != c)
		len++;
	return (len - s);
}

void	*ft_free_mem(char **wrds, int j)
{
	while (j--)
		free(wrds[j]);
	free(wrds);
	return (NULL);
}

char	**ft_fill(char *s, char c, char **wrds)
{
	int	j;
	int	k;
	int	nbr_word;

	j = -1;
	nbr_word = word_nbr(s, c);
	while (++j < nbr_word && *s)
	{
		while (*s == c)
			s++;
		k = 0;
		wrds[j] = malloc(sizeof(char) * (len_wrd(s, c) + 1));
		if (wrds[j] == NULL)
			return (ft_free_mem(wrds, j));
		while (*s && *s != c)
			wrds[j][k++] = *s++;
		wrds[j][k] = 0;
	}
	wrds[j] = 0;
	return (wrds);
}

char	**ft_split(char *s, char c)
{
	char	**wrds;

	if (!s)
		return (NULL);
	wrds = malloc(sizeof(char *) * (word_nbr(s, c) + 1));
	if (!wrds)
		return (NULL);
	return (ft_fill(s, c, wrds));
}
