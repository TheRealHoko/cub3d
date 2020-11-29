/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:52:56 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/28 16:52:38 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ndst;
	unsigned char	*nsrc;
	unsigned char	*ldst;
	unsigned char	*lsrc;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	if (ndst < nsrc)
	{
		while (len--)
			*ndst++ = *nsrc++;
	}
	else
	{
		ldst = ndst + (len - 1);
		lsrc = nsrc + (len - 1);
		while (len--)
			*ldst-- = *lsrc--;
	}
	return (dst);
}
