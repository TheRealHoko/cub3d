/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:49:05 by jzeybel           #+#    #+#             */
/*   Updated: 2021/03/19 18:06:01 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		sizesum;

	sizesum = count * size;
	ptr = malloc(sizesum);
	if (!ptr)
		return (ptr);
	if (ptr)
		ft_bzero(ptr, sizesum);
	return (ptr);
}
