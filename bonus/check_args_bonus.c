/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:54:44 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/16 14:05:13 by aseptimu         ###   ########.fr       */
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
		if (argv[i][0] == '0' && argv[i][j + 1] != '\0')
			return (-1);
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] < '0' || argv[i][j] > '9')
			return (-1);
		if (argv[i][j] == '0' && argv[i][j + 1] != '\0')
			return (-1);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	*convert_int(int argc, char **argv)
{
	int			i;
	int			*args;
	long long	check_overflow;

	i = 0;
	args = (int *)malloc((argc - 1) * sizeof(int));
	if (!args)
		return (NULL);
	while (i < argc - 1)
	{
		check_overflow = ft_atoi(argv[i + 1]);
		if (check_overflow > INT32_MAX || check_overflow < INT32_MIN)
			errors(1, args);
		args[i] = (int)check_overflow;
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
