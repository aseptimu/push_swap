/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:21:45 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/15 17:51:07 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_pos(t_list *a, t_list *curr_b)
{
	t_list	*tmp;
	int		max;

	tmp = a;
	max = curr_b->val;
	while (max > tmp->val)
	{
		if (tmp->next == NULL)
			return (max);
		tmp = tmp->next;
	}
	max = tmp->val;
	tmp = a;
	while (tmp)
	{
		if (tmp->val < max && tmp->val > curr_b->val)
			max = tmp->val;
		tmp = tmp->next;
	}
	return (max);
}

void	score_ra(t_score *score, t_list *min_val, t_list *curr_b, t_list *a)
{
	t_list	*tmp;
	int		min;

	min = find_pos(a, curr_b);
	score->score_ra = 0;
	tmp = a;
	while (tmp->val != min)
	{
		if (curr_b->val == min && tmp->val == min_val->val)
		{
			score->score_rra = score->size_a - score->score_ra;
			return ;
		}
		if (tmp->next == NULL)
			tmp = a;
		else
			tmp = tmp->next;
		score->score_ra++;
	}
	score->score_rra = score->size_a - score->score_ra;
}

void	score_rb(t_score *score, t_list **b, t_list *curr_b)
{
	t_list	*tmp;

	tmp = *b;
	score->score_rb = 0;
	while (tmp != curr_b)
	{
		score->score_rb++;
		tmp = tmp->next;
	}
	score->score_rrb = score->size_b - score->score_rb;
}

void	calc_score(t_score *score, t_list *curr_b, t_list **a, t_list **b)
{
	t_list	*min_val;

	min_val = find_min_val(a);
	score_ra(score, min_val, curr_b, *a);
	score_rb(score, b, curr_b);
	count_scores(score);
	ismin(score);
}
