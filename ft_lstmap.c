/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:11:43 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/30 13:32:40 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;

	while (lst)
	{
		if (!(new_l = f(lst->content)))
		{
			ft_lstclear(&new_l, del);
			del(new_l);
			return (NULL);
		}
		lst = lst->next;
		new_l = new_l->next;
	}
	return (new_l);
}
