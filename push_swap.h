/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:53:25 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/15 18:17:59 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_score
{
	int	score_ra;
	int	score_rb;
	int	score_rra;
	int	score_rrb;
	int	s_rarb;
	int	s_rarrb;
	int	s_rrarb;
	int	s_rrarrb;
	int	s_min;
	int	s_fin;
	int	flag;
	int	op_ra;
	int	op_rb;
	int	op_rra;
	int	op_rrb;
	int	op_rr;
	int	op_rrr;
	int	size_a;
	int	size_b;
}				t_score;

int		*check_args(int argc, char **argv);
void	push_swap(t_list **a, t_list **b, int argc, int mid);
void	sabs(t_list **a, t_list **b, char flag);
void	pab(t_list **a, t_list **b, char flag);
void	rabr(t_list **a, t_list **b, char flag);
void	rrabr(t_list **a, t_list **b, char flag);
void	sort_2(t_list **a, t_list **b);
void	sort_3(t_list **a, t_list **b);
void	calc_score(t_score *score, t_list *curr_b, t_list **a, t_list **b);
void	score_ra(t_score *score, t_list *min_val, t_list *curr_b, t_list *a);
void	score_rb(t_score *score, t_list **b, t_list *curr_b);
void	count_scores(t_score *score);
void	ismin(t_score *score);
void	sort(t_list **a, t_list **b);
t_list	*find_min_val(t_list **a);
int		sort_stack(int *args_m, int argc);
void	errors(int code, int *args_m);
#endif