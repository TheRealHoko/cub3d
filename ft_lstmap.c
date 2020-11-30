/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:11:43 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/30 17:08:40 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*tmp;
	t_list	*new_elem;

	if (!f)
		return (NULL);
	new_l = NULL;
	while (lst)
	{
		if (!(tmp = f(lst->content)))
		{
			ft_lstclear(&new_l, del);
			return (NULL);
		}
		if (!(new_elem = ft_lstnew(tmp)))
		{
			ft_lstclear(&new_l, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&new_l, new_elem);
		lst = lst->next;
	}
	return (new_l);
}
