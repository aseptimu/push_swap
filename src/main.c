/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:33:50 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/15 17:46:47 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	errors(int code, int *args_m)
{
	write(2, "Error\n", 6);
	free(args_m);
	exit (code);
}

int	init_stack(int argc, int *args, t_list **b)
{
	int		i;
	t_list	*a;

	i = 1;
	while (i < argc)
	{
		a = ft_lstnew(args[i - 1]);
		if (!a)
			return (-1);
		ft_lstadd_back(b, a);
		i++;
	}
	return (0);
}

int	check_sorted(int *args_m, int argc)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (args_m[i] < args_m[i - 1])
			return (0);
		i++;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		mid;
	int		*args_m;
	int		err;

	args_m = check_args(argc, argv);
	if (args_m == NULL)
		errors(-1, NULL);
	err = check_sorted(args_m, argc);
	if (err == -1)
	{
		free(args_m);
		return (0);
	}
	err = init_stack(argc, args_m, &a);
	if (err == -1)
		errors(-1, args_m);
	mid = sort_stack(args_m, argc);
	push_swap(&a, &b, argc, mid);
	ft_lstclear(&a, NULL);
	free(args_m);
	return (0);
}
