/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:32:47 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/18 03:11:02 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_len(unsigned long long n, int size)
{
	int i;
	
	i = 1;
	while (n /= size)
		i++;
	return (i);
}

char	*ft_ulltoa_base(unsigned long long n, char *base)
{
	int	lenb;
	int len;
	int i;
	char	*array;

	if ((long long)n < 0)
		n *= -1;
	lenb = ft_strlen(base);
	len = ft_len(n, lenb);
	if (!(array = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = len;
	array[i] = 0;
	while (i >= 0)
	{
		array[--i] = base[n % lenb];
		n /= lenb;
	}
	return (array);
}
/*
#include <stdio.h>
#include <limits.h>

int main()
{
	long i;

	i = 2147483648;
	//printf("i = %d\n", i);

	printf("ft_ulltoa_base de i = %s\n", ft_ulltoa_base(i, "0123456789abcdef"));
}*/
