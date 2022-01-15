/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:51 by aseptimu          #+#    #+#             */
/*   Updated: 2022/01/12 13:46:12 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*newl;
	t_list	*cpyl;

	cpyl = (void *)0;
	while (lst)
	{
		newl = ft_lstnew(f(lst->val));
		if (!newl)
		{
			ft_lstclear(&cpyl, del);
			return ((void *)0);
		}
		ft_lstadd_back(&cpyl, newl);
		lst = lst->next;
	}
	return (cpyl);
}
