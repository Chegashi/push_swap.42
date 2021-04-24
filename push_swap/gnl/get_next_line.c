/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:34:48 by mochegri          #+#    #+#             */
/*   Updated: 2021/04/24 13:37:25 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	get_next_line(int fd, char **line)
{
	int	n;

	**line = '\0';
	if (fd < 0 || !line || BUFFER_SIZE < 0 || read(fd, NULL, 0))
		return (-1);
	free(*line);
	n = get_buffer(fd, line);
	if (!n && **line != '\0')
		return (1);
	return (n);
}

int	get_buffer(int fd, char **line)
{
	int			n;
	static char	*tmp = NULL;
	char		*buffer;
	char		*joker;
	char		*end;

	if (tmp == NULL)
		tmp = ft_char_calloc(1);
	buffer = ft_char_calloc(BUFFER_SIZE + 1);
	end = ft_strchr(tmp, '\n');
	n = read(fd, buffer, BUFFER_SIZE);
	while (!end && n > 0)
	{
		buffer[n] = '\0';
		joker = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = joker;
		end = ft_strchr(buffer, '\n');
		end = ft_strchr(tmp, '\n');
		n = read(fd, buffer, BUFFER_SIZE);
	}
	end = ft_strchr(tmp, '\n');
	free(buffer);
	return (n = ft_the_end(&tmp, line, &end));
}

int	ft_the_end(char **tmp, char **line, char **end)
{
	char		*joker;

	if (*end != NULL)
	{
		*line = ft_substr(*tmp, 0, (*end - *tmp));
		joker = ft_strdup(*end + 1);
		free(*tmp);
		*tmp = joker;
		return (1);
	}
	else
	{
		*line = ft_strdup(*tmp);
		free(*tmp);
		*tmp = NULL;
		return (0);
	}
}

char	*ft_strdup(const char *src)
{
	char	*p;
	size_t	i;

	i = -1;
	p = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (p == 0)
		return (0);
	while (++i < ft_strlen(src))
		p[i] = src[i];
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr_ch;
	int		i;

	i = 0;
	ptr_ch = NULL;
	if (!s)
		return (NULL);
	if (start > len)
		len = 0;
	ptr_ch = (char *)malloc(((int)len + 1) * sizeof(char));
	if (ptr_ch == NULL)
		return (0);
	if (start > ft_strlen(s))
	{
		ptr_ch[0] = '\0';
		return (0);
	}
	while (i < (int)len && s[start + i])
	{
		ptr_ch[i] = s[(int)start + i];
		i++;
	}
	ptr_ch[i] = '\0';
	return (ptr_ch);
}
