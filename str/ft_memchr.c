/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:51:45 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/17 17:51:46 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ns;

	i = 0;
	ns = (unsigned char *)s;
	while (i < n)
	{
		if (ns[i] == (unsigned char)c)
			return (ns + i);
		i++;
	}
	return (0);
}
