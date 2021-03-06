/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:55:22 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/19 14:55:31 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_tablen(char **tab)
{
    size_t    i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}
