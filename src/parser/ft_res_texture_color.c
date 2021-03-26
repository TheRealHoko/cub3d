/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res_texture_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:10:13 by jzeybel           #+#    #+#             */
/*   Updated: 2021/03/26 01:08:25 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	ft_resolution(char *line, t_parse *parse)
{
	int	tmp[2];
	char	**split;
	int		tablen;

	split = ft_split(line, DELIM);
	tablen = ft_tablen(split);
	if ((tablen == 3) && !ft_strncmp(*split, "R", 1) && !ft_checkres(parse->res, 2))
	{
		tmp[0] = ft_atoll(split[1]);
		tmp[1] = ft_atoll(split[2]);
		if (ft_checkres(tmp, 2))
		{
			parse->res[0] = tmp[0];
			parse->res[1] = tmp[1];
		}
		ft_freetab(split, tablen);
		return (1);
	}
	ft_freetab(split, tablen);
	return (0);
}

int	ft_sprites_textures(char *line, t_parse *parse)
{
	char	**split;
	int		len;

	split = ft_split(line, DELIM);
	len = 2;
	if (ft_checktextures(*split, len))
	{
		if(!ft_strncmp(*split, "NO", len))
			parse->NO = ft_strdup(split[1]);
		if(!ft_strncmp(*split, "SO", len))
			parse->SO = ft_strdup(split[1]);
		if(!ft_strncmp(*split, "EA", len))
			parse->EA = ft_strdup(split[1]);
		if(!ft_strncmp(*split, "WE", len))
			parse->WE = ft_strdup(split[1]);
		if(!ft_strncmp(*split, "S", len))
			parse->S = ft_strdup(split[1]);
		ft_freetab(split, ft_tablen(split));
		return (1);
	}
	ft_freetab(split, ft_tablen(split));
	return (0);
}

int	ft_colors(char *line, t_parse *parse)
{
	int	tmp[3];
	char	**split;
	int		len;

	split = ft_split(line, DELIM);
	len = ft_strlen(*split);
	if ((!ft_strncmp(*split, "F", len) || !ft_strncmp(*split, "C", len)) \
		&& (!ft_checkres(parse->F, 3) \
		|| !ft_checkres(parse->C, 3)))
	{
		tmp[0] = ft_atoll(split[1]);
		tmp[1] = ft_atoll(split[2]);
		tmp[2] = ft_atoll(split[3]);
		if (!ft_strncmp(*split, "F", len) && ft_checkcolor(tmp, 3))
		{
			parse->F[0] = tmp[0];
			parse->F[1] = tmp[1];
			parse->F[2] = tmp[2];
		}
		if (!ft_strncmp(*split, "C", len) && ft_checkcolor(tmp, 3))
		{
			parse->C[0] = tmp[0];
			parse->C[1] = tmp[1];
			parse->C[2] = tmp[2];
		}
		ft_freetab(split, ft_tablen(split));
		return (1);
	}
	ft_freetab(split, ft_tablen(split));
	return (0);
}
