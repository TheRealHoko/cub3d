/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:17:48 by jzeybel           #+#    #+#             */
/*   Updated: 2021/05/25 23:07:45 by jzeybel          ###   ########.fr       */
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

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_raycast
{
	double	movespeed;
	double	rotspeed;
	double	posX;
	double	posY;
	int		mapX;
	int		mapY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
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
	double	cameraX;
}				t_raycast;

typedef struct	s_cub3d
{
	t_img		img;
	t_mlx		mlx;
	t_parse		parse;
	t_raycast	ray;
}				t_cub3d;

void	ft_pixel_put(t_img *img, int x, int y, int color);
void	ft_drawLine(t_img *img, int x1, int y1, int x2, int y2, int color);
void	ft_square(t_img *img, int x, int y, int size, int color);
void	ft_verLine(t_img *img, int x, int y1, int y2, int color);
void	ft_cls(t_cub3d *cub3d, t_point p1, t_point p2, int color);

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		add_shade(double distance, int color);

void	ft_draw_minimap(t_cub3d *cub3d, int xoff, int yoff, int size);
void	ft_minimap(t_cub3d *cub3d, int xoff, int yoff, int size);

void	ft_hooks(t_cub3d *cub3d);
int		key_hook(int keycode, t_cub3d *cub3d);
int		close_win(t_cub3d *cub3d);

void	init_player(t_cub3d *cub3d);
void	ft_raycasting(t_img *img, t_raycast *ray, t_parse *parse);
int		frame(t_cub3d *cub3d);

#endif
