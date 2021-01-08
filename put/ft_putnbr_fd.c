/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:27:22 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/08 16:04:43 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(long long int n, int fd)
{
	unsigned long long int nn;

	if (n >= 0 && n < 10)
		ft_putchar_fd(n + 48, fd);
	else if (n < 0)
	{
		nn = n * (-1);
		if (nn == 9223372036854775808u)
		{
			write(fd, "-9223372036854775808", 21);
			return ;
		}
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(nn, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
