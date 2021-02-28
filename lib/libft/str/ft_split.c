/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:57:34 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/28 15:31:01 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	count_tab(char const *s, char *delim)
{
	int	count;
	int	s_witch;

	s_witch = 0;
	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (s_witch == 1 && ft_ischarset(*s, delim))
			s_witch = 0;
		if (s_witch == 0 && !ft_ischarset(*s, delim))
		{
			count++;
			s_witch = 1;
		}
		s++;
	}
	return (count);
}

static int	count_words(char const *s, char *delim)
{
	int	count;

	count = 0;
	while (!ft_ischarset(*s, delim) && (*s != '\0'))
	{
		count++;
		s++;
	}
	return (count);
}

static char	**free_tab(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char		**ft_split(char const *s, char *delim)
{
	int		i;
	int		k;
	char	**new_s;

	i = 0;
	k = count_tab(s, delim);
	new_s = malloc(sizeof(new_s) * (k + 1));
	if (!new_s)
		return (NULL);
	while (k--)
	{
		while (ft_ischarset(*s, delim))
			s++;
		new_s[i] = ft_substr(s, 0, count_words(s, delim));
		if (!new_s[i])
			return (free_tab(new_s, i));
		i++;
		s += count_words(s, delim);
	}
	new_s[i] = 0;
	return (new_s);
}
