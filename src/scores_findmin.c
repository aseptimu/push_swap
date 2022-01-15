/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores_findmin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:31:48 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/15 18:01:31 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_scores(t_score *score)
{
	score->flag = 1;
	score->op_ra = 0;
	score->op_rb = 0;
	score->op_rr = 0;
	score->op_rra = 0;
	score->op_rrb = 0;
	score->op_rrr = 0;
}

void	ismin2(t_score *score)
{
	if (score->s_rrarb == score->s_min && \
	(score->s_rrarb < score->s_fin || score->flag == 0))
	{
		init_scores(score);
		score->s_fin = score->s_rrarb;
		score->op_rra = score->score_rra;
		score->op_rb = score->score_rb;
	}
	else if (score->s_rrarrb == score->s_min && \
	(score->s_rrarrb < score->s_fin || score->flag == 0))
	{
		init_scores(score);
		score->s_fin = score->s_rrarrb;
		if (score->score_rra < score->score_rrb)
		{
			score->op_rrb = score->score_rrb - score->score_rra;
			score->op_rrr = score->score_rra;
		}
		else
		{
			score->op_rra = score->score_rra - score->score_rrb;
			score->op_rrr = score->score_rrb;
		}
	}
}

void	ismin(t_score *score)
{
	if (score->s_rarb == score->s_min && \
	(score->s_rarb < score->s_fin || score->flag == 0))
	{
		init_scores(score);
		score->s_fin = score->s_rarb;
		if (score->score_ra < score->score_rb)
		{
			score->op_rb = score->score_rb - score->score_ra;
			score->op_rr = score->score_ra;
		}
		else
		{
			score->op_ra = score->score_ra - score->score_rb;
			score->op_rr = score->score_rb;
		}
	}
	else if (score->s_rarrb == score->s_min && \
	(score->s_rarrb < score->s_fin || score->flag == 0))
	{
		init_scores(score);
		score->s_fin = score->s_rarrb;
		score->op_ra = score->score_ra;
		score->op_rrb = score->score_rrb;
	}
	ismin2(score);
}

static int	findmincurscore(t_score score)
{
	if (score.s_rarb > score.s_rarrb)
		score.s_rarb = score.s_rarrb;
	if (score.s_rrarb > score.s_rrarrb)
		score.s_rrarb = score.s_rrarrb;
	if (score.s_rarb > score.s_rrarb)
		score.s_min = score.s_rrarb;
	else
		score.s_min = score.s_rarb;
	return (score.s_min);
}

void	count_scores(t_score *score)
{
	if (score->score_ra > score->score_rb)
		score->s_rarb = score->score_ra;
	else
		score->s_rarb = score->score_rb;
	score->s_rarrb = score->score_ra + score->score_rrb;
	score->s_rrarb = score->score_rra + score->score_rb;
	if (score->score_rra > score->score_rrb)
		score->s_rrarrb = score->score_rra;
	else
		score->s_rrarrb = score->score_rrb;
	score->s_min = findmincurscore(*score);
}
