/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:07:30 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/07 18:43:32 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new_s = malloc(sizeof(new_s) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_s[j + i] = s2[j];
		j++;
	}
	new_s[j + i] = '\0';
	return (new_s);
}
