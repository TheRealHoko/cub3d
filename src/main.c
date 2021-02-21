/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:14:21 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/21 20:35:36 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

int	main(int ac, char	**av)
{
	int		*res;
	void	*mlx;
	void	*window;

	window = NULL;
	if (ac == 2)
		res = resparse(av[1]);
	else
		return (1);
	mlx = mlx_init();
	window = mlx_new_window(mlx, res[0], res[1], "cub3d");
	mlx_loop(mlx);
	return (0);
}
