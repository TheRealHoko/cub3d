/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdelim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:52:43 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/28 20:16:19 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	get_line(char **buf, char **line)
{
	if (*buf)
		*line = *buf;
	else
	{
		*line = malloc(sizeof(char) * 1);
		if (!*line)
			return (0);
		*line[0] = '\0';
	}
	*buf = NULL;
	return (1);
}

static int	retline(int chr, char **buf, char **line)
{
	*line = ft_substrfree(*buf, 0, chr, 0);
	if (!*line)
		return (0);
	*buf = ft_substrfree(*buf, chr + 1, ft_strlen(*buf) - chr, 1);
	if (!*buf)
		return (0);
	return (1);
}

int	ft_getdelim(int fd, char **line, int delim)
{
	static char	*buf[FD];
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	int			chr;

	ret = 1;
	if (!line || fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (-1);
	chr = ft_strchri(buf[fd], delim);
	while ((chr == -1) && (ret))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		buf[fd] = ft_strjoinfree(buf[fd], buffer);
		if (!buf[fd])
			return (-1);
		chr = ft_strchri(buf[fd], delim);
	}
	if (chr > -1)
		return (retline(chr, &buf[fd], line));
	if (!get_line(&buf[fd], line))
		return (-1);
	return (0);
}
