/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:10:11 by jzeybel           #+#    #+#             */
/*   Updated: 2021/05/23 18:24:20 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_raycast *r, t_parse *p, int keycode)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = r->dirX;
	oldPlaneX = r->planeX;
	if (keycode == KEY_Z)
	{
		if (p->map[(int)(r->posX + r->dirX * r->movespeed)][(int)r->posY] != '1')
			r->posX += r->dirX * r->movespeed;
		if (p->map[(int)r->posX][(int)(r->posY + r->dirY * r->movespeed)] != '1')
			r->posY += r->dirY * r->movespeed;
	}
	if (keycode == KEY_S)
	{
		if (p->map[(int)(r->posX - r->dirX * r->movespeed)][(int)r->posY] != '1')
			r->posX -= r->dirX * r->movespeed;
		if (p->map[(int)r->posX][(int)(r->posY - r->dirY * r->movespeed)] != '1')
			r->posY -= r->dirY * r->movespeed;
	}
	if (keycode == KEY_D)
	{
		r->dirX = r->dirX * cos(-r->rotspeed) - r->dirY * sin(-r->rotspeed);
		r->dirY = oldDirX * sin(-r->rotspeed) + r->dirY * cos(-r->rotspeed);
		r->planeX = r->planeX * cos(-r->rotspeed) - r->planeY * sin(-r->rotspeed);
		r->planeY = oldPlaneX * sin(-r->rotspeed) + r->planeY * cos(-r->rotspeed);
	}
	if (keycode == KEY_Q)
	{
		r->dirX = r->dirX * cos(r->rotspeed) - r->dirY * sin(r->rotspeed);
		r->dirY = oldDirX * sin(r->rotspeed) + r->dirY * cos(r->rotspeed);
		r->planeX = r->planeX * cos(r->rotspeed) - r->planeY * sin(r->rotspeed);
		r->planeY = oldPlaneX * sin(r->rotspeed) + r->planeY * cos(r->rotspeed);
	}

}
int	key_hook(int keycode, t_cub3d *cub3d)
{
	printf("keycode = %d\tposx = %f\tposy = %f\n", keycode, cub3d->ray.posX, cub3d->ray.posY);
	printf(" dirx= %f\t diry= %f\n", cub3d->ray.dirX, cub3d->ray.dirY);
	move_player(&cub3d->ray, &cub3d->parse, keycode);
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

void	ft_hooks(t_cub3d *cub3d)
{
	mlx_hook(cub3d->mlx.win, 33, 0, close_win, cub3d);
	mlx_hook(cub3d->mlx.win, 2, 1L << 0, key_hook, cub3d);
	mlx_loop_hook(cub3d->mlx.mlx, frame, cub3d);
}
