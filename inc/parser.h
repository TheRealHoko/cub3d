/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:43:48 by jzeybel           #+#    #+#             */
/*   Updated: 2021/03/23 00:08:12 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# define DELIM " \t,"
# define INT_MAX (ft_pow(2, 31) - 1)

typedef struct s_parse
{
	int		res[2];
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*S;
	int		F[3];
	int		C[3];
	t_list	*map;
	int		save;
}				t_parse;

int		ft_parse(char *path, t_parse *parse);
int		ft_resolution(char *line, t_parse *parse);
int		ft_sprites_textures(char *line, t_parse *parse);
int		ft_colors(char *line, t_parse *parse);
void	init_parse(t_parse *parse);
int		ft_checkres(int *tmp, int size);
int 	ft_checkcolor(int *tmp, int size);
int 	ft_checktextures(char *line, size_t len);

#endif
