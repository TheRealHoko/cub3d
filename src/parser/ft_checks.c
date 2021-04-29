/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:42:55 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/07 21:16:30 by jzeybel          ###   ########.fr       */
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
	if (j == 2)
		return (j);
	return (0);
}

int ft_checkcolor(int *tmp, int size)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (tmp && (++i < size))
	{
		if ((tmp[i] >= 0) && (tmp[i] <= 255))
			j++;
	}
	if (j == 3)
		return (j);
	return (0);
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

int	ft_checkmap(char *line, t_parse *parse)
{
	int	len;

	len = ft_strlen(line);
	if (!ft_strncmp(line + (len - 1), "1", 1) \
		&& ft_issetdiff(line, "012 NSEW", len) \
		&& parse->res && parse->NO && parse->SO \
		&& parse->EA && parse->WE && parse->F \
		&& parse->C)
		return (1);
	return (0);
}
