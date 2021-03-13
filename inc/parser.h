/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:43:48 by jzeybel           #+#    #+#             */
/*   Updated: 2021/03/05 13:45:25 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>

typedef struct s_parse
{
	char	**map;
	int		*res;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*S;
	int		*F;
	int		*C;
}				t_parse;

void	ft_parse(char *s, t_parse *parse);
void	init_t_parse(t_parse *parse);

#endif
