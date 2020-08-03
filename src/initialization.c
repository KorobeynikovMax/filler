/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:58:16 by maxim             #+#    #+#             */
/*   Updated: 2020/08/03 04:06:27 by maxim            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Initializer
*/

void    init(t_filler *f)
{
    f->over = 0;
    f->map_created = 0;
}

/*
** function notnull return 1 if position is not 0,0
*/

int     isnull(t_point x)
{
    if (x.y == 0 && x.x == 0)
        return (1);
    return (0);
}

void    free_map2(t_filler *f)
{
    int		i;

    if (!f->map)
        return ;
    i = 0;
    while (i < f->h)
    {
        ft_strdel(&f->map[i]);
        i++;
    }
    ft_memdel((void **)&f->map);
}

void    free_map(t_filler *f)
{
    int i;

    i = 0;
    if (f->hmap)
    {
        while (i < f->h)
        {
            free(f->hmap[i++]);
        }
        free(f->hmap);
        f->hmap = NULL;
    }
    free_map2(f);
}