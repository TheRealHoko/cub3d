/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:08:37 by jzeybel           #+#    #+#             */
/*   Updated: 2020/12/01 14:20:59 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*find))
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] && (big[i + j] == find[j] && i + j < len))
			j++;
		if (find[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
