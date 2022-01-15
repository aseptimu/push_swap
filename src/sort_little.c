/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:32:58 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/14 19:45:55 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(t_list **a, t_list **b)
{
	if ((*a)->val > (*a)->next->val)
		sabs(a, b, 'a');
}

void	sort_3(t_list **a, t_list **b)
{
	if ((*a)->next->val > (*a)->val && (*a)->next->val > (*a)->next->next->val)
		rrabr(a, b, 'a');
	else if ((*a)->val > (*a)->next->val && (*a)->val > (*a)->next->next->val)
		rabr(a, b, 'a');
	if ((*a)->val > (*a)->next->val)
		sabs(a, b, 'a');
}
