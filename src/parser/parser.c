/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:06:19 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/21 19:54:21 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	*resparse(char	*s)
{
	int			fd;
	static int	res[2];
	char		*f;
	char		**line;
	int			ret;

	fd = open(s, O_RDONLY);
	while (ret == 1)
	{
		if (ft_strchri(f, 0) == 'R')
		{
			line = ft_split(f, ' ');
			res[0] = ft_atoll(line[0]);
			res[1] = ft_atoll(line[1]);
		}
		ret = get_next_line(fd, &f);
	}
	close(fd);
	return (res);
}
