/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:08:37 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/25 18:25:00 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		while (find[j] && (big[i] == find[j] && i < len))
		{
			if (find[j + 1] == '\0')
				return ((char *)&big[i - j]);
			j++;
			i++;
		}
		i++;
	}
	return (0);
}
