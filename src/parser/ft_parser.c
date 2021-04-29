/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:06:19 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/29 15:39:59 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_parse(t_parse *parse)
{
	parse->res[0] = -1;
	parse->res[1] = -1;
	parse->NO = NULL;
	parse->SO = NULL;
	parse->WE = NULL;
	parse->EA = NULL;
	parse->S = NULL;
	parse->F[0] = -1;
	parse->F[1] = -1;
	parse->F[2] = -1;
	parse->C[0] = -1;
	parse->C[1] = -1;
	parse->C[2] = -1;
	parse->map = NULL;
	parse->mapwidth = 0;
	parse->mapheight = 0;
}

int	ft_tmpmap(char	*line, t_parse *parse, t_list **map)
{
	if (ft_checkmap(line, parse))
	{
		ft_lstadd_back(map, ft_lstnew(ft_strdup(line)));
		return (1);
	}
	return (0);
}

int	ft_map(t_list *map, t_parse *parse)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	parse->map = malloc(sizeof(char *) * (parse->mapheight + 1));
	while (++i < parse->mapheight)
	{
		tmp = map->data;
		parse->map[i] = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
		j = -1;
		while (tmp[++j])
		{
			if ((tmp[j] == ' ') || (tmp[j] == '1'))
				parse->map[i][j] = '1';
			else
				parse->map[i][j] = tmp[j];
		}
		parse->map[i][j] = 0;
		map = map->next;
	}
	parse->map[i] = 0;
	return (0);
}

int	ft_parse(char *path, t_parse *parse)
{
	int			fd;
	char		*line;
	int			ret;
	t_list		*map;

	fd = open(path, O_RDONLY);
	ret = 1;
	map = NULL;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		ft_resolution(line, parse);
		ft_sprites_textures(line, parse);
		ft_colors(line, parse);
		ft_tmpmap(line, parse, &map);
		ft_free((void **)&line);
	}
	close(fd);
	parse->mapheight = ft_lstsize(map);
	parse->mapwidth = ft_lstlencmp(map);
	ft_map(map, parse);
	ft_lstclear(&map, ft_del);
	return (0);
}
