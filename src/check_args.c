/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:54:44 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/15 17:39:50 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_digit(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] || argv[i][0] == '\0')
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9') || \
			argv[i][j] == '-' || argv[i][j] == '+'))
				return (-1);
			j++;
		}
		if (argv[i][0] == '0' && argv[i][1])
		{
			if (argv[i][1] != ' ')
				return (-1);
		}
		i++;
	}
	return (0);
}

static int	*convert_int(int argc, char **argv)
{
	int	i;
	int	*args;

	i = 0;
	args = (int *)malloc((argc - 1) * sizeof(int));
	if (!args)
		return (NULL);
	while (i < argc - 1)
	{
		args[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (args);
}

static int	check_double(const int *args_m, int argc)
{
	int	i;
	int	j;

	if (args_m == NULL)
		return (-1);
	i = 0;
	while (i < argc - 1)
	{
		j = i;
		while (j < argc - 1)
		{
			if (args_m[i] == args_m[j] && i != j)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*check_args(int argc, char **argv)
{
	int	*args_m;
	int	err;

	err = check_digit(argv, argc);
	if (err == -1)
	{
		return (NULL);
	}
	args_m = convert_int(argc, argv);
	err = check_double(args_m, argc);
	if (err == -1 || args_m == NULL)
	{
		free(args_m);
		return (NULL);
	}
	argc = 0;
	argv = 0;
	return (args_m);
}
