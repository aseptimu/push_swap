/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:52:00 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/14 19:51:49 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	output(char flag_stack, int flag_cmd)
{
	if (flag_stack == 'a' && flag_cmd == 0)
		write (1, "sa\n", 3);
	if (flag_stack == 'b' && flag_cmd == 0)
		write (1, "sb\n", 3);
	if (flag_stack == 's' && flag_cmd == 0)
		write (1, "ss\n", 3);
	if (flag_stack == 'a' && flag_cmd == 1)
		write (1, "pa\n", 3);
	if (flag_stack == 'b' && flag_cmd == 1)
		write (1, "pb\n", 3);
	if (flag_stack == 'a' && flag_cmd == 2)
		write (1, "ra\n", 3);
	if (flag_stack == 'b' && flag_cmd == 2)
		write (1, "rb\n", 3);
	if (flag_stack == 'r' && flag_cmd == 2)
		write (1, "rr\n", 3);
	if (flag_stack == 'a' && flag_cmd == 3)
		write (1, "rra\n", 4);
	if (flag_stack == 'b' && flag_cmd == 3)
		write (1, "rrb\n", 4);
	if (flag_stack == 'r' && flag_cmd == 3)
		write (1, "rrr\n", 4);
}

void	sabs(t_list **a, t_list **b, char flag)
{
	t_list	*tmp;

	if (flag == 'a' || flag == 'z')
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
	if (flag == 'b' || flag == 'z')
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
	}
	else if (flag == 's')
		sabs(a, b, 'z');
	output(flag, 0);
}

void	pab(t_list **a, t_list **b, char flag)
{
	t_list	*tmp;

	if (flag == 'a')
	{
		tmp = *b;
		*b = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (flag == 'b')
	{
		tmp = *a;
		*a = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
	output(flag, 1);
}

void	rabr(t_list **a, t_list **b, char flag)
{
	t_list	*tmp;

	if (flag == 'a' || flag == 'z')
	{
		if (*a == NULL)
			return ;
		tmp = ft_lstlast(*a);
		tmp ->next = *a;
		tmp = *a;
		*a = tmp->next;
		tmp->next = NULL;
	}
	if (flag == 'b' || flag == 'z')
	{
		if (*b == NULL)
			return ;
		tmp = ft_lstlast(*b);
		tmp ->next = *b;
		tmp = *b;
		*b = tmp->next;
		tmp->next = NULL;
	}
	if (flag == 'r')
		rabr(a, b, 'z');
	output(flag, 2);
}

void	rrabr(t_list **a, t_list **b, char flag)
{
	t_list	*tmp;

	if (flag == 'a' || flag == 'z')
	{
		tmp = *a;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = *a;
		*a = tmp->next;
		tmp->next = NULL;
	}
	if (flag == 'b' || flag == 'z')
	{
		tmp = *b;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = *b;
		*b = tmp->next;
		tmp->next = NULL;
	}
	if (flag == 'r')
		rrabr(a, b, 'z');
	output(flag, 3);
}
