/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:14:21 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/29 17:57:52 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	printf("save : %s\n", (cub3d->parse.save) ? "yes" : "no");
	printf("RES = %d %d\n", cub3d->parse.res[0], cub3d->parse.res[1]);
	printf("NO = %s\n", cub3d->parse.NO);
	printf("SO = %s\n", cub3d->parse.SO);
	printf("WE = %s\n", cub3d->parse.WE);
	printf("EA = %s\n", cub3d->parse.EA);
	printf("S = %s\n", cub3d->parse.S);
	printf("F = R[%d] G[%d] B[%d]\n", cub3d->parse.F[0], cub3d->parse.F[1], cub3d->parse.F[2]);
	printf("C = R[%d] G[%d] B[%d]\n", cub3d->parse.C[0], cub3d->parse.C[1], cub3d->parse.C[2]);
	while (++i < cub3d->parse.mapheight)
		printf("%s\n", cub3d->parse.map[i]);
	printf("map width = %d\n", cub3d->parse.mapwidth);
	printf("map height = %d\n", cub3d->parse.mapheight);
}

int	ft_checkext(char *path, char *ext)
{
	int	len;
	int	lenext;

	len = ft_strlen(path);
	lenext = ft_strlen(ext);
	if (!ft_strncmp(path + (len - lenext), ext, lenext))
		return (1);
	return (0);
}

int ft_checksave(char *param)
{
	int	len;

	len = ft_strlen(param);
	if (param && (!ft_strncmp(param, "-save", len) \
		|| !ft_strncmp(param, "--save", len)))
		return (1);
	return (0);
}

void	init_mlx(t_cub3d *cub3d)
{
	cub3d->mlx.mlx = mlx_init();
	cub3d->mlx.win = mlx_new_window(cub3d->mlx.mlx, cub3d->parse.res[0], cub3d->parse.res[1], "cub3d");
}

void	init_img(t_cub3d *cub3d)
{
	cub3d->img.img = mlx_new_image(cub3d->mlx.mlx, cub3d->parse.res[0], cub3d->parse.res[1]);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, &cub3d->img.bpp, &cub3d->img.linelen, &cub3d->img.endian);
}

int	main(int ac, char	**av)
{
	t_cub3d	cub3d;

	cub3d.parse.save = ft_checksave(av[2]);
	if ((ac == 2 && ft_checkext(av[1], ".cub")) \
		|| (ac == 3 && cub3d.parse.save))
	{
		init_parse(&cub3d.parse);
		ft_parse(av[1], &cub3d.parse);
	}
	else
		return (printf("Error : usage ./cub3d <map>.cub (--save)\n"));

	debug(&cub3d);

	if (ft_error(&cub3d.parse))
		return (printf("parse : map config is invalid\n"));
	cub3d.ray.posX = 3;
	cub3d.ray.posY = 3;
	init_mlx(&cub3d);
	init_img(&cub3d);
	ft_hooks(&cub3d);
	mlx_loop(cub3d.mlx.mlx);
	return (0);
}
