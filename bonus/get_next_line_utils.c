/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:22:26 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/24 17:50:51 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	i++;
	p = malloc(i * sizeof(char));
	if (!p)
		return ((void *)0);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		lens1;
	int		lens2;
	int		i;

	if (!s1 && !s2)
		return ((void *)0);
	if (!s1 && s2)
		return (ft_strdup((char *)s2));
	if (s1 && !s2)
		return (ft_strdup((char *)s1));
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	p = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!p)
		return ((void *)0);
	i = 0;
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[lens1 + lens2] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_trim(char *str)
{
	int	j;
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			j = i;
			while (str[++j])
			{
				str[j] = '\0';
			}
		}
		i++;
	}
	return (str);
}
