/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:02:53 by jzeybel           #+#    #+#             */
/*   Updated: 2020/11/28 16:43:17 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa(int n)
{
	int		sign;
	int		size;
	char	*array;
	long	nn;
	long	p;

	sign = (n < 0) ? -1 : 1;
	size = (n < 0) ? 2 : 1;
	nn = n;
	p = 10;
	while (n /= 10)
	{
		p = p * 10;
		size++;
	}
	if (!(array = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	nn *= sign;
	size = (sign < 0) ? 1 : 0;
	while (p /= 10)
		array[size++] = ((nn / p) % 10) + '0';
	if (sign == -1)
		array[0] = '-';
	array[size] = 0;
	return (array);
}
