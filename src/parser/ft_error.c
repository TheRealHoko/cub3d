/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:21:59 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/28 01:35:35 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_error(t_parse *parse)
{
	if (!ft_checkres(parse->res, 2))
		return (ft_freeparse(parse));
	if (!ft_checkcolor(parse->F, 3))
		return (ft_freeparse(parse));
	if (!ft_checkcolor(parse->C, 3))
		return (ft_freeparse(parse));
	if (!parse->NO)
		return (ft_freeparse(parse));
	if (!parse->SO)
		return (ft_freeparse(parse));
	if (!parse->WE)
		return (ft_freeparse(parse));
	if (!parse->EA)
		return (ft_freeparse(parse));
	if (!parse->map)
		return (ft_freeparse(parse));
	return (0);
}

int	ft_freeparse(t_parse *parse)
{
	if (parse->NO)
		free(parse->NO);
	if (parse->SO)
		free(parse->SO);
	if (parse->WE)
		free(parse->WE);
	if (parse->EA)
		free(parse->EA);
	if (parse->map)
		ft_freetab(parse->map, ft_tablen(parse->map));
	if (parse->S)
		free(parse->S);
	return (1);
}

int	ft_freewindow(t_mlx *mlx)
{
	if (mlx->mlx)
		free(mlx->mlx);
	return (0);
}
