/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:31:53 by jzeybel           #+#    #+#             */
/*   Updated: 2021/05/20 15:17:08 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_minimap(t_cub3d *cub3d, int xoff, int yoff, int size)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = yoff;
	if (yoff)
		y = yoff - ((cub3d->parse.mapheight / 2) * size);
	while (cub3d->parse.map && (++i < cub3d->parse.mapheight))
	{
		x = xoff;
		if (xoff)
			x = xoff - ((cub3d->parse.mapwidth / 2) * size);
		j = -1;
		while (++j < cub3d->parse.mapwidth)
		{
			if (cub3d->parse.map[i][j] == '1')
				ft_square(&cub3d->img, x, y, size - 1, create_trgb(0, 82, 75, 75));
			else
				ft_square(&cub3d->img, x, y, size - 1, create_trgb(0, 255, 255, 255));
			x += size;
		}
		y += size;
	}
}

void	ft_minimap(t_cub3d *cub3d, int xoff, int yoff, int size)
{
	int	x;
	int	y;

	x = cub3d->ray.posX * size;
	y = cub3d->ray.posY * size;
	ft_draw_minimap(cub3d, xoff, yoff, size);
	ft_square(&cub3d->img, x, y, size, create_trgb(0, 255, 0, 0));
}
