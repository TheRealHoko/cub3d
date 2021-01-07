/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:07:19 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/06 19:09:49 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s = malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len);
	return (s);
}
