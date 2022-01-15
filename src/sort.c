/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:37:40 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/15 18:16:33 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_min_val(t_list **a)
{
	t_list	*min_val;
	t_list	*tmp;

	min_val = *a;
	tmp = (*a)->next;
	while (tmp)
	{
		if (tmp->val < min_val->val)
			min_val = tmp;
		tmp = tmp->next;
	}
	return (min_val);
}

void	operation(t_score *score, t_list **a, t_list **b)
{
	while (score->op_ra--)
		rabr(a, b, 'a');
	while (score->op_rb--)
		rabr(a, b, 'b');
	while (score->op_rra--)
		rrabr(a, b, 'a');
	while (score->op_rrb--)
		rrabr(a, b, 'b');
	while (score->op_rr--)
		rabr(a, b, 'r');
	while (score->op_rrr--)
		rrabr(a, b, 'r');
}

static void	sort2(t_list **a, t_list **b, t_list *tmp)
{
	t_list	*min_val;
	int		size;
	int		i;

	size = ft_lstsize(*a);
	tmp = *a;
	min_val = find_min_val(a);
	i = 0;
	while (tmp != min_val)
	{
		i++;
		tmp = tmp->next;
	}
	if (size / 2 > i)
	{
		while (*a != min_val)
			rabr(a, b, 'a');
	}
	else
	{
		while (*a != min_val)
			rrabr(a, b, 'a');
	}
}

void	sort(t_list **a, t_list **b)
{
	t_score	score;
	t_list	*tmp;

	while (*b)
	{
		tmp = *b;
		score.flag = 0;
		score.s_fin = 0;
		score.size_a = ft_lstsize(*a);
		score.size_b = ft_lstsize(*b);
		while (tmp)
		{
			calc_score(&score, tmp, a, b);
			tmp = tmp->next;
		}
		operation(&score, a, b);
		pab(a, b, 'a');
	}
	sort2(a, b, tmp);
}
