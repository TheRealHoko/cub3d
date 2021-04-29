/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:07:05 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/15 15:49:11 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ss;

	ss = (unsigned char *)s;
	while (*ss != c && *ss != '\0')
		ss++;
	if (*ss == c)
		return ((char *)ss);
	return (NULL);
}
