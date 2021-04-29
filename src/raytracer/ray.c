/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:24:51 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/29 18:19:06 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pixel_put(t_cub3d *cub3d, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > cub3d->parse.res[0] || y < 0 || y > cub3d->parse.res[1])
		return ;
	dst = cub3d->img.addr + (y * cub3d->img.linelen + x * (cub3d->img.bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_drawLine(t_cub3d *cub3d, int x1, int y1, int x2, int y2, int color)
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
		ft_pixel_put(cub3d, x, y, color);
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

void	ft_verLine(t_cub3d *cub3d, int x, int y1, int y2, int color)
{
	while (y1 != y2)
	{
		if (y1 < y2)
			y1++;
		else
			y1--;
		ft_pixel_put(cub3d, x, y1, color);
	}
}

void	ft_rect(t_cub3d *cub3d, int px, int py, int dx, int dy, int color)
{
	ft_drawLine(cub3d, px, py, dx, py, color);
	ft_drawLine(cub3d, px, py, px, dy, color);
	ft_drawLine(cub3d, px, dy, dx, dy, color);
	ft_drawLine(cub3d, dx, py, dx, dy, color);
}

void	ft_fill_rect(t_cub3d *cub3d, int x1, int y1, int x2, int y2, int color)
{
	int	dx;

	dx = x2 - x1;
	while (dx--)
		ft_rect(cub3d, x1++, y1++, x2--, y2--, color);
}

void	ft_circle_points(t_cub3d *cub3d, int xc, int yc, int x, int y, int color)
{
	ft_pixel_put(cub3d, xc + x, yc + y, color);
	ft_pixel_put(cub3d, xc + x, yc - y, color);
	ft_pixel_put(cub3d, xc - x, yc + y, color);
	ft_pixel_put(cub3d, xc - x, yc - y, color);
	ft_pixel_put(cub3d, xc + y, yc + x, color);
	ft_pixel_put(cub3d, xc - y, yc + x, color);
	ft_pixel_put(cub3d, xc + y, yc - x, color);
	ft_pixel_put(cub3d, xc - y, yc - x, color);
}

void	ft_circle(t_cub3d *cub3d, int xc, int yc, int r, int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = 3 - (2 * r);
	ft_circle_points(cub3d, xc, yc, x, y, color);
	while (x <= y)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		ft_circle_points(cub3d, xc, yc, x, y, color);
	}
}

void	ft_fill_circle(t_cub3d *cub3d, int xc, int yc, int r, int color)
{
	while (r--)
		ft_circle(cub3d, xc, yc, r, color);
}

void	ft_fill(t_cub3d *cub3d, int x, int y, int color)
{
	int	ix;
	int	iy;

	iy = 0;
	while (y--)
	{
	ix = 0;
		while (ix < x)
			ft_pixel_put(cub3d, ix++, iy, color);
		iy++;
	}
}

void	ft_minimap(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	while (cub3d->parse.map && (++i < cub3d->parse.mapheight))
	{
		x = 0;
		j = -1;
		while (++j < cub3d->parse.mapwidth)
		{
			if (cub3d->parse.map[i][j] == '1')
				ft_fill_rect(cub3d, x, y, x + 20, y + 20, create_trgb(0, 82, 75, 75));
			else if (cub3d->parse.map[i][j] == '0')
				ft_fill_rect(cub3d, x, y, x + 20, y + 20, create_trgb(0, 255, 255, 255));
			else if (cub3d->parse.map[i][j] == 'N')
			{
				ft_fill_rect(cub3d, x, y, x + 20, y + 20, create_trgb(0, 255, 0, 0));
			}
			x += 20;
		}
		y += 20;
	}
}

int	key_hook(int keycode, t_cub3d *cub3d)
{
	printf("keycode = %d\tposx = %f\tposy = %f\n", keycode, cub3d->ray.posX, cub3d->ray.posY);
	move_player(keycode, cub3d);
	if (keycode == ESC)
		close_win(cub3d);
	return (0);
}

int	close_win(t_cub3d *cub3d)
{
	printf("See you soon Samurai !\n");
	ft_freeparse(&cub3d->parse);
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->img.img);
	mlx_destroy_window(cub3d->mlx.mlx, cub3d->mlx.win);
	mlx_destroy_display(cub3d->mlx.mlx);
	ft_freewindow(&cub3d->mlx);
	exit (0);
	return (0);
}

int	move_player(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_Z)
	{
		if (cub3d->parse.map[(int)(cub3d->ray.posX + cub3d->ray.dirX)][(int)cub3d->ray.posY] != '1')
			cub3d->ray.posX += cub3d->ray.dirX;
		if (cub3d->parse.map[(int)cub3d->ray.posX][(int)(cub3d->ray.posY + cub3d->ray.dirY)] != '1')
			cub3d->ray.posY += cub3d->ray.dirY;
	}
	if (keycode == KEY_S)
	{
		if (cub3d->parse.map[(int)(cub3d->ray.posX - cub3d->ray.dirX)][(int)cub3d->ray.posY] != '1')
			cub3d->ray.posX -= cub3d->ray.dirX;
		if (cub3d->parse.map[(int)cub3d->ray.posX][(int)(cub3d->ray.posY - cub3d->ray.dirY)] != '1')
			cub3d->ray.posY -= cub3d->ray.dirY;
	}
	//if (keycode == KEY_Q)
	//if (keycode == KEY_D)
	return (0);
}

void	ft_hooks(t_cub3d *cub3d)
{
	mlx_hook(cub3d->mlx.win, 33, 0, close_win, cub3d);
	mlx_hook(cub3d->mlx.win, 2, 1L << 0, key_hook, cub3d);
	mlx_loop_hook(cub3d->mlx.mlx, cub2d, cub3d);
}

void	ft_raycasting(t_cub3d *cub3d, t_raycast *ray, t_parse *parse)
{
	int	color;

	color = create_trgb(0, 255, 0, 0);
	ray->x = 0;
	ray->dirX = -1;
	ray->dirY = 0;
	ray->planeX = 0;
	ray->planeY = 0.66;
	while (ray->x < parse->res[0])
	{
		ray->cameraX = 2 * ray->x / (double)parse->res[0] - 1;
		ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
		ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
		ray->mapX = (int)ray->posX;
		ray->mapY = (int)ray->posY;
		ray->deltaDistX = ABS(1/ray->rayDirX);
		ray->deltaDistY = ABS(1/ray->rayDirY);
		ray->hit = 0;
		if (ray->rayDirX < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
		}
		else
		{
			ray->stepX = 1;
			ray->sideDistX = (ray->mapX + 1 - ray->posX) * ray->deltaDistX;
		}
		if (ray->rayDirY < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
		}
		else
		{
			ray->stepY = 1;
			ray->sideDistY = (ray->mapY + 1 - ray->posY) * ray->deltaDistY;
		}
		while (!ray->hit)
		{
			if (ray->sideDistX < ray->sideDistY)
			{
				ray->sideDistX += ray->deltaDistX;
				ray->mapX += ray->stepX;
				ray->side = 0;
			}
			else
			{
				ray->sideDistY += ray->deltaDistY;
				ray->mapY += ray->stepY;
				ray->side = 1;
			}
			if (parse->map[ray->mapX][ray->mapY] == '1')
				ray->hit = 1;
		}
		if (!ray->side)
			ray->perpWallDist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
		else
			ray->perpWallDist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->rayDirY;
		ray->lineHeight = (int)(parse->res[1] / ray->perpWallDist);
		ray->drawStart = -ray->lineHeight / 2 + parse->res[1] / 2;
		if (ray->drawStart < 0)
			ray->drawStart = 0;
		ray->drawEnd = ray->lineHeight / 2 + parse->res[1] / 2;
		if (ray->drawEnd >= parse->res[1])
			ray->drawEnd = parse->res[1] - 1;

		if (ray->side)
			color = color / 2;
		ft_verLine(cub3d, ray->x, ray->drawStart, ray->drawEnd, color);
		ray->x++;
	}

}

int	cub2d(t_cub3d *cub3d)
{
	ft_raycasting(cub3d, &cub3d->ray, &cub3d->parse);
	ft_minimap(cub3d);
	mlx_put_image_to_window(cub3d->mlx.mlx, cub3d->mlx.win, cub3d->img.img, 0, 0);
	return (0);
}
