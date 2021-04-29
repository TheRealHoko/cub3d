/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issetdiff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:45:33 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/05 19:04:17 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issetdiff(char *s, char *set, int len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < len)
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				k++;
			j++;
		}
		i++;
	}
	if (k == len)
		return (k);
	return (0);
}
