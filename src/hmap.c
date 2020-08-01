/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:56:47 by bedavis           #+#    #+#             */
/*   Updated: 2020/08/01 15:56:55 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Function fills hmap very first time
*/

void    hput_init(int y, t_filler *f)
{
    int x;

    x = 0;
    while (x < f->w)
    {
        if (f->map[y][x] == '.')
            f->hmap[y][x] = 0;
        else if (f->map[y][x] == f->my || f->map[y][x] == f->my_small)
            f->hmap[y][x] = -2;
        else if (f->map[y][x] == f->en || f->map[y][x] == f->en_small)
            f->hmap[y][x] = -1;
        x++;
    }
}

/*
** Function fills hmap very first time
*/

void    create_hmap_0(t_filler *f)
{
    int y;

    y = 0;
    while (y < f->h)
    {
        hput_init(y, f);
        y++;
    }
    make_hmap(f);
}

/*
** Function allocate memmory for heat map and starts first filling with 0
*/

int    create_hmap(t_filler *f)
{
    int y;

    y = 0;
    if (!(f->hmap = (int **)malloc(sizeof(int *) * (unsigned long)f->h)))
        return (1);
    while (y < f->h)
    {
        if (!(f->hmap[y] =
                (int *)malloc(sizeof(int) * (unsigned long)f->w)))
            return (1);
        y++;
    }
    create_hmap_0(f);
    return (0);
}

/*
** Function check the neighbours of x,y if they are enemy
*/

void    make_hmap_1(t_filler *f, int x, int y)
{
    if ((x - 1 >= 0 && y - 1 >= 0 && f->hmap[y - 1][x - 1] == -1) ||
        (y - 1 >= 0 && f->hmap[y - 1][x] == -1) ||
        (x + 1 < f->w && y - 1 >= 0 && f->hmap[y - 1][x + 1] == -1) ||
        (x - 1 >= 0 && f->hmap[y][x - 1] == -1) ||
        (x + 1 < f->w && f->hmap[y][x + 1] == -1) ||
        (x - 1 >= 0 && y + 1 < f->h && f->hmap[y + 1][x - 1] == -1) ||
        (y + 1 < f->h && f->hmap[y + 1][x] == -1) ||
        (x + 1 < f->w && y + 1 < f->h && f->hmap[y + 1][x + 1] == -1))
        f->hmap[y][x] = 1;
}

/*
** Function fill the hmap with first '1's
*/

void    make_hmap(t_filler *f)
{
    int	x;
    int	y;

    y = 0;
    while (y < f->h)
    {
        x = 0;
        while (x < f->w)
        {
            if (f->hmap[y][x] == 0)
                make_hmap_1(f, x, y);
            x++;
        }
        y++;
    }
    fill_hmap(f);
}
