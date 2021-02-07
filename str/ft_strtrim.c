/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:09:13 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/07 01:55:47 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1) - 1;
	while (ft_ischarset(s1[i], set))
		i++;
	while (ft_ischarset(s1[j], set) && j > 0)
		j--;
	if (i >= j)
		return (ft_strdup(""));
	return (ft_substr(s1, i, j - i + 1));
}
