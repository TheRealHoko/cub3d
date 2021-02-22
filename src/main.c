/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:14:21 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/22 04:41:19 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

int	main(int ac, char	**av)
{
	t_parse	parse;
	void	*mlx;
	void	*window;

	if (ac == 2)
		ft_parse(av[1], &parse);
	else
		return (1);
	mlx = mlx_init();
	printf("----------%d-----%d------\n",parse.res[0], parse.res[1]); 
	printf("--%s--\n", parse.NO); 
	window = mlx_new_window(mlx, parse.res[0], parse.res[1], "cub3d");
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	return (0);
}
