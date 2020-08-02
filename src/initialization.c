/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:58:16 by maxim             #+#    #+#             */
/*   Updated: 2020/08/03 01:15:12 by maxim            ###   ########lyon.fr   */
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
    char	*str;

    if (!f->map)
        return ;
    i = 0;
    while (i < f->h)
    {
        str = f->map[i] - 4;
        ft_strdel(&str);
        i++;
    }
    ft_memdel((void **)&f->map);
}

void    free_map(t_filler *f)
{
    int i;

    i = 0;
    while (i < f->h && (f->hmap))
        free(f->hmap[i++]);
    //free(f->map);
    free(f->hmap);
    //f->map = NULL;
    f->hmap = NULL;
    free_map2(f);
}