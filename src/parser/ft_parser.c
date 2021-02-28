/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:06:19 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/28 15:35:02 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

void	init_t_parse(t_parse *parse)
{
	parse->res = malloc(sizeof(int) * 2);
	parse->F = malloc(sizeof(int) * 3);
	parse->C = malloc(sizeof(int) * 3);
}

void	ft_parse(char *s, t_parse *parse)
{
	int			fd;
	char		*delim;
	char		**line;
	char		*f;
	int			ret;

	fd = open(s, O_RDONLY);
	ret = get_next_line(fd, &f);
	delim = " \t,";
	while (ret == 1)
	{
		line = ft_split(f, delim);
		if (ft_strnstr(f, "R", ft_strlen(f)))
		{
			parse->res[0] = ft_atoll(line[1]);
			parse->res[1] = ft_atoll(line[2]);
		}
		else if (ft_strnstr(f, "NO", ft_strlen(f)))
			parse->NO = line[1];
		else if (ft_strnstr(f, "SO", ft_strlen(f)))
			parse->SO = line[1];
		else if (ft_strnstr(f, "WE", ft_strlen(f)))
			parse->WE = line[1];
		else if (ft_strnstr(f, "EA", ft_strlen(f)))
			parse->EA = line[1];
		else if (ft_strnstr(f, "S", ft_strlen(f)))
			parse->S = line[1];
		else if (ft_strnstr(f, "F", ft_strlen(f)))
		{
			parse->F[0] = ft_atoll(line[1]);
			parse->F[1] = ft_atoll(line[2]);
			parse->F[2] = ft_atoll(line[3]);
		}
		else if (ft_strnstr(f, "C", ft_strlen(f)))
		{
			parse->C[0] = ft_atoll(line[1]);
			parse->C[1] = ft_atoll(line[2]);
			parse->C[2] = ft_atoll(line[3]);
		}
		else if (ft_strisset(f, "1"))
		{
			printf("map");
		}
		free(f);
		free(line);
		ret = get_next_line(fd, &f);
	}
	free(f);
	close(fd);
}