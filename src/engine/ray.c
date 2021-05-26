/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:24:51 by jzeybel           #+#    #+#             */
/*   Updated: 2021/05/26 02:27:22 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = -1;
	cub3d->ray.planeX = 0;
	cub3d->ray.planeY = 0.66;
	cub3d->ray.dirX = -1;
	cub3d->ray.dirY = 0;
	cub3d->ray.movespeed = 0.1;
	cub3d->ray.rotspeed = 0.2;
	while (++i < cub3d->parse.mapheight)
	{
		j = -1;
		while (++j < cub3d->parse.mapwidth)
		{
			if (cub3d->parse.map[i][j] == 'N')
			{
				cub3d->ray.posX = j;
				cub3d->ray.posY = i;
			}
		}
	}

}

static void	init_ray(t_raycast *r, int x, double w)
{
	r->cameraX = 2 * x / w - 1;
	r->rayDirX = r->dirX + r->planeX * r->cameraX;
	r->rayDirY = r->dirY + r->planeY * r->cameraX;
}

static void	dist_calc(t_raycast *r)
{
	r->mapX = (int)r->posX;
	r->mapY = (int)r->posY;
	r->deltaDistX = sqrt(1 + pow(r->rayDirY, 2) / pow(r->rayDirX, 2));
	r->deltaDistY = sqrt(1 + pow(r->rayDirX, 2) / pow(r->rayDirY, 2));
	r->hit = 0;

}

static void	step_calc(t_raycast *r)
{
	if (r->rayDirX < 0)
	{
		r->stepX = -1;
		r->sideDistX = (r->posX - r->mapX) * r->deltaDistX;
	}
	else
	{
		r->stepX = 1;
		r->sideDistX = (r->mapX + 1 - r->posX) * r->deltaDistX;
	}
	if (r->rayDirY < 0)
	{
		r->stepY = -1;
		r->sideDistY = (r->posY - r->mapY) * r->deltaDistY;
	}
	else
	{
		r->stepY = 1;
		r->sideDistY = (r->mapY + 1 - r->posY) * r->deltaDistY;
	}

}

static void	DDA_algorithm(t_raycast *r, t_parse *p)
{
	while(!r->hit)
	{
		if (r->sideDistX < r->sideDistY)
		{
			r->sideDistX += r->deltaDistX;
			r->mapX += r->stepX;
			r->side = 0;
		}
		else
		{
			r->sideDistY += r->deltaDistY;
			r->mapY += r->stepY;
			r->side = 1;
		}
		if (p->map[r->mapX][r->mapY] == '1')
			r->hit = 1;
	}
}

void	ft_raycasting(t_img *img, t_raycast *r, t_parse *p)
{
	int	x;
	int	w;
	int	h;
	int	color;
	double	shade;

	shade = 0;
	//x = -1;
	x = (p->res[0] / 2) - 1;
	w = p->res[0];
	h = p->res[1];
	while (++x < w)
	{
		color = add_shade(shade, GREEN);
		init_ray(r, x, w);
		dist_calc(r);
		step_calc(r);
		DDA_algorithm(r, p);
		if (!r->side)
			r->perpWallDist = (r->mapX - r->posX + (1 - r->stepX) / 2) / r->rayDirX;
		else
			r->perpWallDist = (r->mapY - r->posY + (1 - r->stepY) / 2) / r->rayDirY;
		r->lineHeight = (int)(h / r->perpWallDist);
		r->drawStart = -r->lineHeight / 2 + h / 2;
		if (r->drawStart < 0)
			r->drawStart = 0;
		r->drawEnd = r->lineHeight / 2 + h / 2;
		if (r->drawEnd >= h)
			r->drawEnd = h - 1;
		if (r->side)
			color = add_shade(0.5, color);
		ft_verLine(img, x, r->drawStart, r->drawEnd, color);
	}
}

int	frame(t_cub3d *cub3d)
{
	t_parse *p;

	p = &cub3d->parse;
	ft_cls(cub3d, (t_point){0, 0}, (t_point){p->res[0], p->res[1]}, BLACK);
	ft_cls(cub3d, (t_point){p->res[0] / 2, 0}, (t_point){p->res[0], p->res[1] / 2}, create_trgb(0, p->C[0], p->C[1], p->C[2]));
	ft_cls(cub3d, (t_point){p->res[0] / 2, p->res[1] / 2}, (t_point){p->res[0], p->res[1]}, create_trgb(0, p->F[0], p->F[1], p->F[2]));
	ft_minimap(cub3d, 0, 0, 64);
	ft_raycasting(&cub3d->img, &cub3d->ray, &cub3d->parse);
	mlx_put_image_to_window(cub3d->mlx.mlx, cub3d->mlx.win, cub3d->img.img, 0, 0);
	return (0);
}
