/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:09:28 by jzeybel           #+#    #+#             */
/*   Updated: 2020/12/03 17:52:47 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char			*new_s;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(new_s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len-- && s[i])
	{
		new_s[i] = s[start++];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
