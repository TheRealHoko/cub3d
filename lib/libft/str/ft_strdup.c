/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:07:19 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/21 12:58:36 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (len-- && (*s1 != '\0'))
		*s++ = *s1++;
	*s = '\0';
	return (s);
}
