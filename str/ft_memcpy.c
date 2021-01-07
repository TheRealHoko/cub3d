/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:52:46 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/29 16:57:28 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*conv_dst;
	const char	*conv_src;

	conv_dst = (char *)dst;
	conv_src = (const char *)src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*conv_dst++ = *conv_src++;
	return (dst);
}
