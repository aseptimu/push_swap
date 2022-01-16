/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:29:45 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/16 17:39:37 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

int		*check_args(int argc, char **argv);
void	errors(int code, int *args_m);
void	do_instructions(int *args_m, t_list **a, t_list **b);

void	sabs(t_list **a, t_list **b, char flag);
void	pab(t_list **a, t_list **b, char flag);
void	rabr(t_list **a, t_list **b, char flag);
void	rrabr(t_list **a, t_list **b, char flag);

#endif