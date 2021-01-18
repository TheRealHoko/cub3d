/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:43:21 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/12 19:48:25 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putbase_fd(unsigned long n, char *base, size_t size, int fd)
{
	if (n / (unsigned long)size > 0)
		ft_putbase_fd(n / size, base, size, fd);
	write(fd, &base[n % size], 1);
}
