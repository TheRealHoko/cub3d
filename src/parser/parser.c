/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:06:19 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/24 18:41:52 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdio.h>

void	init_t_parse(t_parse *parse)
{
	parse->res = malloc(sizeof(int) * 2);
	parse->F = malloc(sizeof(int) * 3);
	parse->C = malloc(sizeof(int) * 3);
}

void	*ft_parse(char *s, t_parse *parse)
{
	int			fd;
	char		*f;
	int			ret;

	fd = open(s, O_RDONLY);
	ret = get_next_line(fd, &f);
	while (ret == 1)
	{
		if (ft_strnstr(f, "R", ft_strlen(f)))
		{
			parse->res[0] = ft_atoll(ft_split(f, " ")[1]);
			parse->res[1] = ft_atoll(ft_split(f, " ")[2]);
		}
		else if (ft_strnstr(f, "NO", ft_strlen(f)))
			parse->NO = ft_split(f, " ")[1];
		else if (ft_strnstr(f, "SO", ft_strlen(f)))
			parse->SO = ft_split(f, " ")[1];
		else if (ft_strnstr(f, "WE", ft_strlen(f)))
			parse->WE = ft_split(f, " ")[1];
		else if (ft_strnstr(f, "EA", ft_strlen(f)))
			parse->EA = ft_split(f, " ")[1];
		else if (ft_strnstr(f, "S", ft_strlen(f)))
			parse->S = ft_split(f, " ")[1];
		else if (ft_strnstr(f, "F", ft_strlen(f)))
		{
			parse->F[0] = ft_atoll(ft_split(f, " ,")[1]);
			parse->F[1] = ft_atoll(ft_split(f, " ,")[2]);
			parse->F[2] = ft_atoll(ft_split(f, " ,")[3]);
		}
		else if (ft_strnstr(f, "C", ft_strlen(f)))
		{
			parse->C[0] = ft_atoll(ft_split(f, " ,")[1]);
			parse->C[1] = ft_atoll(ft_split(f, " ,")[2]);
			parse->C[2] = ft_atoll(ft_split(f, " ,")[3]);
		}
		ret = get_next_line(fd, &f);
	}
	close(fd);
	return (0);
}
