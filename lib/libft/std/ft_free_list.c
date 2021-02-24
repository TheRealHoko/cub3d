/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:00:37 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/24 18:02:52 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h" 

void	*free_list(void	**list)
{
	int	i;
	void	**k;
	
	i = 0;
	k = list;
	while (*k++)
		i++;
	while (i--)
		free(list[i]);
	free(list);
	return (NULL);
}
