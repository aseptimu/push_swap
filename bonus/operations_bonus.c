/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:52:00 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/16 18:10:20 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sabs(t_list **a, t_list **b, char flag)
{
	t_list	*tmp;

	if (!*a && (flag == 'a' || flag == 's'))
		return ;
	if (!*b && (flag == 'b' || flag == 's'))
		return ;
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
}

void	pab(t_list **a, t_list **b, char flag)
{
	t_list	*tmp;

	if (!*a && flag == 'b')
		return ;
	if (!*b && flag == 'a')
		return ;
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
}

void	rabr(t_list **a, t_list **b, char flag)
{
	t_list	*tmp;

	if ((flag == 'a' || flag == 'z') && *a)
	{
		if (*a == NULL)
			return ;
		tmp = ft_lstlast(*a);
		tmp ->next = *a;
		tmp = *a;
		*a = tmp->next;
		tmp->next = NULL;
	}
	if ((flag == 'b' || flag == 'z') && *b)
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
}

void	rrabr(t_list **a, t_list **b, char flag)
{
	t_list	*tmp;

	if ((flag == 'a' || flag == 'z') && *a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = *a;
		*a = tmp->next;
		tmp->next = NULL;
	}
	if ((flag == 'b' || flag == 'z') && *b && (*b)->next)
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
}
