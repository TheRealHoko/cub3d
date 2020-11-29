/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:11:43 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/27 22:32:33 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *))
{
	t_list	*tmp;

	tmp = ft_lstnew(lst);
	while (lst)
	{
		if (*del)
			ft_lstdelone(lst, del);
		f(tmp->content);
		lst = lst->next;
		tmp = tmp->content;
	}
	return (tmp);
}
