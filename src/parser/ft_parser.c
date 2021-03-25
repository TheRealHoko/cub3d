/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:06:19 by jzeybel           #+#    #+#             */
/*   Updated: 2021/03/25 23:13:30 by jzeybel          ###   ########.fr       */
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
}

void	ft_map(char	*line, t_parse *parse)
{
	int		len;

	len = ft_strlen(line);
	if (!ft_strncmp(line + (len - 1), "1", 1))
	{
		printf("inmap\n");
		ft_lstadd_back(&parse->map, ft_lstnew(ft_strdup(line)));
	}
}

int	ft_parse(char *path, t_parse *parse)
{
	int			fd;
	char		*line;
	int			ret;
	int			done;

	fd = open(path, O_RDONLY);
	ret = 1;
	done = 0;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		done += ft_resolution(line, parse);
		done += ft_sprites_textures(line, parse);
		done += ft_colors(line, parse);
		if (done == 8)
			ft_map(line, parse);
		free(line);
	}
	close(fd);
	return (0);
}
