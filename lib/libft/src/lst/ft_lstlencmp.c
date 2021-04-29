/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlencmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:09:46 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/22 00:19:35 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlencmp(t_list *lst)
{
	size_t	i;

	i = ft_strlen((char *)lst->data);
	while (lst)
	{
		if (lst->next && (i < ft_strlen((char *)lst->next->data)))
			i = ft_strlen((char *)lst->next->data);
		lst = lst->next;
	}
	return (i);
}
