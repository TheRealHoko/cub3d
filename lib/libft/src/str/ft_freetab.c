/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:04:21 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/19 15:16:43 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_freetab(char **tab, size_t size)
{
    size_t i;

    i = 0;
    if (tab)
    {
        while (i < size)
            free(tab[i++]);
        free(tab);
        return (i);
    }
    return (0);
}
