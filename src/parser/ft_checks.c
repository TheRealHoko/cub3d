/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:42:55 by jzeybel           #+#    #+#             */
/*   Updated: 2021/03/25 22:55:46 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	ft_checkres(int *tmp, int size)
{
	int i;
	int	j;
	
	i = -1;
	j = 0;
	while (tmp && (++i < size))
	{
		if ((tmp[i] >= 0) && (tmp[i] < INT_MAX))
			j++;
	}
	return (j);
}

int ft_checkcolor(int *tmp, int size)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (tmp && (++i < size))
	{
		if ((tmp[i] >= 0) && (tmp[i] < 255))
			j++;
	}
	return (j);
}

int ft_checktextures(char *line, size_t len)
{
    if (line && (!ft_strncmp(line, "NO", len) \
		|| !ft_strncmp(line, "SO", len) \
		|| !ft_strncmp(line, "EA", len) \
		|| !ft_strncmp(line, "WE", len) \
		|| !ft_strncmp(line, "S", len)))
        return (1);
    return (0);
}