/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:42:03 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/15 17:48:22 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*intdup(int *args_m, int argc)
{
	int	*ret;
	int	i;

	i = 0;
	ret = malloc((argc - 1) * sizeof(int));
	if (!ret)
		return (NULL);
	while (i < argc - 1)
	{
		ret[i] = args_m[i];
		i++;
	}
	return (ret);
}

int	sort_stack(int *args_m, int argc)
{
	int	*cpy;
	int	tmp;
	int	i;
	int	ret;

	i = 1;
	cpy = intdup(args_m, argc);
	if (!cpy)
		errors(-1, args_m);
	while (i < argc - 1)
	{
		if (cpy[i] < cpy[i - 1])
		{
			tmp = cpy[i];
			cpy[i] = cpy[i - 1];
			cpy[i - 1] = tmp;
			i = 1;
		}
		i++;
		if (i == argc - 1 && cpy[0] > cpy[1])
			i = 1;
	}
	ret = cpy[(argc - 1) / 2];
	free(cpy);
	return (ret);
}
