/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:14:21 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/16 18:22:50 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char	**av)
{
	void	*mlx;
	void	*window;

	if (ac == 2)
		parser(av[1]);
	else
		return (0);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 400, 400, "cub3d");
	mlx_loop(mlx);
	return (0);
}
