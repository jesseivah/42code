/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebitrus <jebitrus@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:57:05 by jebitrus          #+#    #+#             */
/*   Updated: 2024/01/21 14:57:07 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		max(int *tab, unsigned int len)
{
    int max;

    if(len <= 0 || len == NULL)
        return(0);
    max = tab[--len];
    while(len--)
    {
        if(tab [len] > max)
        {
            max = tab[len];
        }
    }
    return(max);
}