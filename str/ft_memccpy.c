/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:51:28 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/21 04:15:03 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*nsrc;
	unsigned char	*ndst;
	unsigned int	i;

	i = 0;
	nsrc = (unsigned char *)src;
	ndst = (unsigned char *)dst;
	while (i < n)
	{
		ndst[i] = nsrc[i];
		if (nsrc[i] == (unsigned char)c)
			return (ndst + i + 1);
		i++;
	}
	return (0);
}
