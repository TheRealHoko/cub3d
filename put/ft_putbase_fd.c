/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:43:21 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/09 23:11:58 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_putbase_fd(unsigned long n, char *base, size_t size, int fd)
{
	if (n / (unsigned long)size > 0)
		ft_putbase_fd(n / (unsigned long)size, base, (unsigned long)size, fd);
	return (ft_putchar_fd(base[n % (unsigned long)size], fd));
}
