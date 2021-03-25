/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:54:11 by jzeybel           #+#    #+#             */
/*   Updated: 2021/03/19 18:06:01 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substrfree(char *s, size_t start, size_t len, int tofree)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	maxlen;

	if (!s)
		return (NULL);
	maxlen = start;
	i = 0;
	while (s[maxlen++] != '\0' && i < len)
		i++;
	new_s = malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		new_s[i++] = s[start++];
	new_s[i] = '\0';
	if (tofree)
		free(s);
	return (new_s);
}
