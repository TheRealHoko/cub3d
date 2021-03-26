/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:14:21 by jzeybel           #+#    #+#             */
/*   Updated: 2021/03/25 23:27:41 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	main(int ac, char	**av)
{
	t_parse	parse;
	void	*mlx;
	void	*window;

	parse.save = ft_checksave(av[2]);
	if ((ac == 2 && ft_checkext(av[1], ".cub")) \
		|| (ac == 3 && parse.save))
	{
		init_parse(&parse);
		ft_parse(av[1], &parse);
	}
	else
		return (printf("Error : usage ./cub3d <map>.cub (--save)"));
	mlx = mlx_init();
	printf("save : %s\n", (parse.save) ? "yes" : "no");
	printf("RES = %d %d\n", parse.res[0], parse.res[1]); 
	printf("NO = %s\n", parse.NO); 
	printf("SO = %s\n", parse.SO); 
	printf("WE = %s\n", parse.WE); 
	printf("EA = %s\n", parse.EA);
	printf("S = %s\n", parse.S);
	printf("F = R[%d] G[%d] B[%d]\n", parse.F[0], parse.F[1], parse.F[2]); 
	printf("C = R[%d] G[%d] B[%d]\n", parse.C[0], parse.C[1], parse.C[2]); 
	ft_lstprint(parse.map);
	window = mlx_new_window(mlx, parse.res[0], parse.res[1], "cub3d");
	free(parse.NO);
	free(parse.SO);
	free(parse.WE);
	free(parse.EA);
	ft_lstclear(&parse.map, &ft_del);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	free(mlx);
	return (0);
}
