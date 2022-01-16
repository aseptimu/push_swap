/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:00:44 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/16 12:38:16 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	result(const char *str, unsigned long long res, int negative)
{
	int	i;

	i = 0;
	while (!(*str >= '0' && *str <= '9'))
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (res > 9223372036854775807 || i > 19)
	{
		if (negative == 1)
			return (INT32_MIN - 1LL);
		else if (negative == -1)
			return (INT32_MAX + 1LL);
	}
	return (res * negative);
}

long long	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	ret;
	int					negative;

	ret = 0;
	i = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		negative = -negative;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (result(str, ret, negative));
}
