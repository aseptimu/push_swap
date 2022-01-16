/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:51:23 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/16 17:48:30 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line.h"

void	do_cmd(t_list **a, t_list **b, int cmd)
{
	if (cmd == 0)
		sabs(a, b, 'a');
	if (cmd == 1)
		sabs(a, b, 'b');
	if (cmd == 2)
		sabs(a, b, 's');
	if (cmd == 3)
		pab(a, b, 'a');
	if (cmd == 4)
		pab(a, b, 'b');
	if (cmd == 5)
		rabr(a, b, 'a');
	if (cmd == 6)
		rabr(a, b, 'b');
	if (cmd == 7)
		rabr(a, b, 'r');
	if (cmd == 8)
		rrabr(a, b, 'a');
	if (cmd == 9)
		rrabr(a, b, 'b');
	if (cmd == 10)
		rrabr(a, b, 'r');
}

int	cmp_commands(char *gnl)
{
	char	*cmds[11];
	int		i;

	i = 0;
	cmds[0] = "sa\n";
	cmds[1] = "sb\n";
	cmds[2] = "ss\n";
	cmds[3] = "pa\n";
	cmds[4] = "pb\n";
	cmds[5] = "ra\n";
	cmds[6] = "rb\n";
	cmds[7] = "rr\n";
	cmds[8] = "rra\n";
	cmds[9] = "rrb\n";
	cmds[10] = "rrr\n";
	while (i != 11)
	{
		if (ft_strncmp(gnl, cmds[i], 6) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	do_instructions(int *args_m, t_list **a, t_list **b)
{
	char	*gnl;
	int		cmd;

	gnl = "2";
	cmd = 0;
	while (gnl != NULL)
	{
		gnl = get_next_line(0);
		if (!gnl)
			return ;
		cmd = cmp_commands(gnl);
		if (cmd == -1)
		{
			free(gnl);
			ft_lstclear(a, NULL);
			ft_lstclear(b, NULL);
			errors(-1, args_m);
		}
		do_cmd(a, b, cmd);
		free(gnl);
	}
}
