/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:52:43 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/18 01:28:54 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lastline(char **buffer, char **line)
{
	if (*buffer)
	{
		*line = ft_strdup(*buffer);
		if (!*line)
			return (-1);
	}
	else
	{
		*line = malloc(1);
		if (!*line)
			return (-1);
		*line[0] = 0;
	}
	ft_free((void **)&(*buffer));
	return (0);
}

static int	readline(int newline, char **buffer, char **line)
{
	*line = ft_substr(*buffer, 0, newline);
	if (!*line)
		return (-1);
	*buffer = ft_substrfree(*buffer, newline + 1, BUFFER_SIZE);
	if (!*buffer)
		return (-1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer[FD];
	char		buf[BUFFER_SIZE];
	int			ret;
	int			newline;

	if (!line || fd < 0 || read(fd, 0, 0) || BUFFER_SIZE < 1)
		return (-1);
	newline = ft_strchri(buffer[fd], '\n');
	ret = 1;
	while ((newline < 0) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = 0;
		buffer[fd] = ft_strjoinfree(buffer[fd], buf);
		if (!buffer[fd])
			return (-1);
		newline = ft_strchri(buffer[fd], '\n');
	}
	if (newline >= 0)
		return (readline(newline, &buffer[fd], line));
	return (lastline(&buffer[fd], line));
}
