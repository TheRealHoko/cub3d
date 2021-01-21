/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:02:53 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/21 13:16:51 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_lltoa(long long n)
{
	int		sign;
	int		size;
	static char	array[50];
	unsigned long long	nn;
	unsigned long long	p;

	sign = (n < 0) ? -1 : 1;
	size = (n < 0) ? 2 : 1;
	nn = n;
	p = 10;
	while (n /= 10)
	{
		p = p * 10;
		size++;
	}
	nn *= sign;
	size = (sign < 0) ? 1 : 0;
	while (p /= 10)
		array[size++] = ((nn / p) % 10) + '0';
	if (sign == -1)
		array[0] = '-';
	array[size] = 0;
	return (array);
}
