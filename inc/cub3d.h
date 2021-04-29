/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:17:48 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/29 16:45:09 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "parser.h"
# include "mlx.h"
# include "keycode.h"
# include <stdio.h>
# include <math.h>

typedef struct	s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		linelen;
	int 	endian;
}				t_img;

typedef struct	s_raycast
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		x;
	int		mapX;
	int		mapY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
}				t_raycast;

typedef struct	s_cub3d
{
	t_img		img;
	t_mlx		mlx;
	t_parse		parse;
	t_raycast	ray;
}				t_cub3d;

void	ft_pixel_put(t_cub3d *cub3d, int x, int y, int color);
void	ft_drawLine(t_cub3d *cub3d, int x1, int y1, int x2, int y2, int color);
void	ft_rect(t_cub3d *cub3d, int px, int py, int dx, int dy, int color);
void	ft_fill_rect(t_cub3d *cub3d, int x1, int y1, int x2, int y2, int color);
void	ft_fill(t_cub3d *cub3d, int x, int y,int color);
void	ft_circle_points(t_cub3d *cub3d, int xc, int yc, int x, int y, int color);
void	ft_circle(t_cub3d *cub3d, int xc, int yc, int r, int color);
void	ft_fill_circle(t_cub3d *cub3d, int xc, int yc, int r, int color);
void	ft_minimap(t_cub3d *cub3d);
int		create_trgb(int t, int r, int g, int b);
int		ft_get_r(int trgb);
int		key_hook(int keycode, t_cub3d *cub3d);
int		close_win(t_cub3d *cub3d);
int		move_player(int keycode, t_cub3d *cub3d);
int		cub2d(t_cub3d *cub3d);
void	ft_hooks(t_cub3d *cub3d);
void	ft_raycasting(t_cub3d *cub3d, t_raycast *ray, t_parse *parse);
void	init_player(t_cub3d *cub3d);

#endif
