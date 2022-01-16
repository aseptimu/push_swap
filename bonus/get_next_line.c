/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:59:24 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/27 16:44:41 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check(char **bufcpy, char **p, char **ret, char *tmp)
{
	*p = NULL;
	if (*bufcpy)
	{
		*p = ft_strchr(*bufcpy, '\n');
		if (*p)
		{
			*ret = ft_strdup(*bufcpy);
			*ret = ft_trim(*ret);
			tmp = *bufcpy;
			*bufcpy = ft_strdup(++(*p));
			if (!*bufcpy)
				ret = NULL;
			free(tmp);
		}
		else
		{
			*ret = ft_strdup(*bufcpy);
			free(*bufcpy);
			*bufcpy = NULL;
		}
	}
	else
		*ret = ft_strdup("\0");
}

char	*ft_read(ssize_t *i, int fd, char *ret, char **p)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		exit (1);
	*i = read(fd, buf, BUFFER_SIZE);
	if (*i == -1)
	{
		free(ret);
		free(buf);
		exit (1);
	}
	buf[*i] = '\0';
	*p = ft_strchr(buf, '\n');
	return (buf);
}

char	*ft_join(char **p, char **bufcpy, char *ret, char *buf)
{
	char	*tmp;

	if (*p != NULL)
	{
		*bufcpy = ft_strdup(++(*p));
		if (!*bufcpy)
			exit (1);
	}
	tmp = ret;
	ret = ft_strjoin(ret, ft_trim(buf));
	if (!ret)
		exit (1);
	free(tmp);
	free(buf);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*bufcpy;
	char		*buf;
	char		*ret;
	char		*p;
	ssize_t		i;

	buf = NULL;
	if (fd < 0)
		exit (1);
	ret = NULL;
	check(&bufcpy, &p, &ret, buf);
	if (!ret)
		exit (1);
	i = BUFFER_SIZE;
	while (!p && i && i == BUFFER_SIZE)
	{
		buf = ft_read(&i, fd, ret, &p);
		if (!buf)
			return (NULL);
		ret = ft_join(&p, &bufcpy, ret, buf);
	}
	if (i || ft_strlen(ret))
		return (ret);
	free(ret);
	return (NULL);
}
