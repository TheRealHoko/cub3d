/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:58:51 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/05 20:18:59 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef FD
#  define FD 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char const *s);
int		ft_strchr(char *s, int c);
char	*ft_substr(char *s, size_t start, size_t len, int tofree);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char const *s1);
#endif
