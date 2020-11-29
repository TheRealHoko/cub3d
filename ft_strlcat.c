/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:07:46 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/23 16:20:06 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	while (dst[i])
		i++;
	if (i > size)
		return (size + ft_strlen((char *)src));
	while (src[j] != 0 && (j + i < size - 1))
	{
		dst[j + i] = src[j];
		j++;
	}
	dst[j + i] = 0;
	return (len);
}
