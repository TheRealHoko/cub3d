/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:53:13 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/17 17:53:15 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*conv_b;
	char	conv_c;
	size_t	i;

	conv_b = b;
	conv_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		conv_b[i] = conv_c;
		i++;
	}
	return (conv_b);
}
