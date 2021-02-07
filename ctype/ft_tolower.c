/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:09:40 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/07 02:00:13 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c) == 1)
		return (c + 32);
	return (c);
}
