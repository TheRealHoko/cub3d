/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:50:15 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/22 17:01:45 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strisset(const char *s, const char *set)
{
	while (s && *set)
	{
		if (ft_ischarset(*set, s))
			return (1);
		set++;
	}
	return (0);
}
