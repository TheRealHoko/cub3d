/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:14:21 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/25 14:06:48 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "parser.h"

int	main(int ac, char	**av)
{
	t_parse	parse;
	void	*mlx;
	void	*window;

	if (ac == 2)
	{
		init_t_parse(&parse);
		ft_parse(av[1], &parse);
	}
	else
		return (1);
	mlx = mlx_init();
	printf("RES = %d %d\n", parse.res[0], parse.res[1]); 
	printf("NO = %s\n", parse.NO); 
	printf("SO = %s\n", parse.SO); 
	printf("WE = %s\n", parse.WE); 
	printf("EA = %s\n", parse.EA);
	printf("S = %s\n", parse.S);
	printf("F = R[%d] G[%d] B[%d]\n", parse.F[0], parse.F[1], parse.F[2]); 
	printf("C = R[%d] G[%d] B[%d]\n", parse.C[0], parse.C[1], parse.C[2]); 
	window = mlx_new_window(mlx, parse.res[0], parse.res[1], "cub3d");
	/*free(parse.res);
	free(parse.NO);
	free(parse.SO);
	free(parse.WE);
	free(parse.EA);
	free(parse.F);
	free(parse.C);*/
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	return (0);
}
