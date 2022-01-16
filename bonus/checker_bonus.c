/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:24:22 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/16 18:44:09 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	check_sorted(t_list *a, t_list *b)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->next && tmp->val > tmp->next->val)
			return (-1);
		tmp = tmp->next;
	}
	if (b)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*args_m;
	int		err;

	if (argc == 1)
		return (0);
	b = NULL;
	args_m = check_args(argc, argv);
	if (args_m == NULL)
		errors(-1, NULL);
	err = init_stack(argc, args_m, &a);
	if (err == -1)
		errors(-1, args_m);
	do_instructions(args_m, &a, &b);
	err = check_sorted(a, b);
	ft_lstclear(&a, NULL);
	free(args_m);
	if (err == -1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (0);
}
