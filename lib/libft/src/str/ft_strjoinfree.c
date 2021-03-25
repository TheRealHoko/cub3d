/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:55:17 by jzeybel           #+#    #+#             */
/*   Updated: 2021/03/19 18:06:01 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!s2)
		return (NULL);
	new_s = malloc(sizeof(char) * len);
	if (!new_s)
		return (NULL);
	while (s1 && s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2[++j] != '\0')
		new_s[j + i] = s2[j];
	new_s[i + j] = '\0';
	if (s1)
		free(s1);
	return (new_s);
}
