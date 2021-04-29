/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:54:11 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/17 23:30:12 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substrfree(char *s, size_t start, size_t len)
{
	char			*new_s;
	size_t			i;

	i = ft_strlen(s);
	if (!s || start > i)
		return (NULL);
	if (i < start + len)
		len = i - start;
	new_s = malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (NULL);
	i = -1;
	while (++i < len)
		new_s[i] = s[start + i];
	new_s[i] = '\0';
	free(s);
	return (new_s);
}
