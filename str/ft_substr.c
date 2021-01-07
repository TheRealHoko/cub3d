/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:09:28 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/07 18:38:47 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	maxlen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	maxlen = start;
	i = 0;
	while (s[maxlen++] != '\0' && i < len)
		i++;
	new_s = malloc(sizeof(char) * (i + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (len-- && s[start])
	{
		new_s[i] = s[start++];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
