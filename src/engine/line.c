/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:58:11 by jzeybel           #+#    #+#             */
/*   Updated: 2021/05/25 23:07:38 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_verLine(t_img *img, int x, int y1, int y2, int color)
{
	if (y1 == y2)
		ft_pixel_put(img, x, y1, color);
	while (y1 != y2)
	{
		if (y1 < y2)
			y1++;
		else
			y1--;
		ft_pixel_put(img, x, y1, color);
	}
}

void	ft_cls(t_cub3d *cub3d, t_point p1, t_point p2, int color)
{
	int	w;
	int	h;
	int	x1;
	int	y1;

	w = p2.x;
	h = p2.y;
	x1 = p1.x - 1;
	y1 = p1.y - 1;
	while (++y1 < h)
	{
		x1 = p1.x - 1;
		while (++x1 < w)
			ft_pixel_put(&cub3d->img, x1, y1, color);
	}
}

void	ft_square(t_img *img, int x, int y, int size, int color)
{
	int	i;
	int	j;
	int	oldX;

	i = -1;
	oldX = x;
	while (++i < size)
	{
		j = -1;
		x = oldX;
		while (++j < size)
			ft_pixel_put(img, x++, y, color);
		y++;
	}
}

void	ft_drawLine(t_img *img, int x1, int y1, int x2, int y2, int color)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;
	int	derror;

	x = x1;
	y = y1;
	dx = x1 - x2;
	dy = y2 - y1;
	sx = -1;
	sy = -1;
	if (x2 >= x1)
		dx = x2 - x1;
	if (y2 >= y1)
		dy = y1 - y2;
	if (x1 < x2)
		sx = 1;
	if (y1 < y2)
		sy = 1;
	error = dx + dy;;
	while (1)
	{
		ft_pixel_put(img, x, y, color);
		if ((x == x2) && (y == y2))
			break;
		derror = 2 * error;
		if (derror >= dy)
		{
			error += dy;
			x += sx;
		}
		if (derror <= dx)
		{
			error += dx;
			y += sy;
		}
	}
}

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < 0 || y < 0)
		return ;
	i = img->bpp - 8;
	pixel= img->addr + (y * img->linelen + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}

}
