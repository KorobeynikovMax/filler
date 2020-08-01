/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:53:33 by bedavis           #+#    #+#             */
/*   Updated: 2020/08/01 15:53:36 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Checking neighbours for == to i
*/

void    hmap_put(int i, int x, int y, t_filler *f)
{
    if ((x - 1 >= 0 && y - 1 >= 0 && f->hmap[y - 1][x - 1] == i) ||
        (y - 1 >= 0 && f->hmap[y - 1][x] == i) ||
        (x + 1 < f->w && y - 1 >= 0 && f->hmap[y - 1][x + 1] == i) ||
        (x - 1 >= 0 && f->hmap[y][x - 1] == i) ||
        (x + 1 < f->w && f->hmap[y][x + 1] == i) ||
        (x - 1 >= 0 && y + 1 < f->h && f->hmap[y + 1][x - 1] == i) ||
        (y + 1 < f->h && f->hmap[y + 1][x] == i) ||
        (x + 1 < f->w && y + 1 < f->h && f->hmap[y + 1][x + 1] == i))
        f->hmap[y][x] = i + 1;
}

/*
** The function is fighting with 0s on heat map,
** regions that could be after the map was divided by players.
*/

void    fight_zeros(t_filler *f, int i)
{
    int y;
    int x;

    y = 0;
    while (y < f->h)
    {
        x = 0;
        while (x < f->w)
        {
            if (f->hmap[y][x] == 0)
                f->hmap[y][x] = i + 1;
            x++;
        }
        y++;
    }
}

/*
** filling the heat map with 2, 3, 4 ... to width + height
*/

void    fill_hmap(t_filler *f)
{
    int	x;
    int	y;
    int	i;

    i = 1;
    while (i < (f->w + f->h))
    {
        y = 0;
        while (y < f->h)
        {
            x = 0;
            while (x < f->w)
            {
                if (f->hmap[y][x] == 0)
                    hmap_put(i, x, y, f);
                x++;
            }
            y++;
        }
        i++;
    }
    fight_zeros(f, i);
}
