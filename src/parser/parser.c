/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:06:19 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/22 16:56:22 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdio.h>

void	free_line(char **line)
{
	while (line)
		free(*line);
	line = 0;
}

void	*ft_parse(char *s, t_parse *parse)
{
	int			fd;
	char		*f;
	char		**line;
	int			ret;

	fd = open(s, O_RDONLY);
	ret = get_next_line(fd, &f);
	while (ret == 1)
	{
		if (ft_strisset(f, "R"))
		{
			line = ft_split(f, ' ');
			parse->res[0] = ft_atoll(line[1]);
			parse->res[1] = ft_atoll(line[2]);
			//free_line(line);
		}
		if (ft_strisset(f, "NO"))
		{
			line = ft_split(f, ' ');
			parse->NO = line[1];
			//free_line(line);
		}
		/*if (ft_strisset(f, "SO"))
			return ;
		if (ft_strisset(f, "WE"))
			return ;
		if (ft_strisset(f, "EA"))
			return ;
		if (ft_strisset(f, "S"))
			return ;
		if (ft_strisset(f, "F"))
			return ;
		if (ft_strisset(f, "C"))
			return ;*/
		ret = get_next_line(fd, &f);
	}
	close(fd);
	return (0);
}
