/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:51:19 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/15 17:50:32 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	all_big(t_list **b, int mid)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->val < mid)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	push_mid(t_list **a, t_list **b, int mid)
{
	t_list	*tmp;
	int		counter;

	tmp = *a;
	counter = 0;
	while (tmp->next->next->next != NULL)
	{
		if (tmp->val < mid || counter < 2 || all_big(b, mid) != 0)
			pab(a, b, 'b');
		else
		{
			pab(a, b, 'b');
			rabr(a, b, 'b');
		}
		tmp = *a;
		counter++;
	}
}

void	push_swap(t_list **a, t_list **b, int argc, int mid)
{
	if (argc == 3)
	{
		sort_2(a, b);
	}
	else
	{	
		push_mid(a, b, mid);
		sort_3(a, b);
		sort(a, b);
	}
}
