/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:08:53 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/21 04:19:44 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	conv_c;
	int		i;

	i = ft_strlen(s) + 1;
	conv_c = (char)c;
	while (i--)
		if (s[i] == conv_c)
			return ((char *)s + i);
	return (NULL);
}
