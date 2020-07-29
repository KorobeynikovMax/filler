//
// Created by Макс Коробейников on 20/07/2020.
//

#include "filler.h"
#include <stdio.h>

/*
 * function checks if the piece is valid for this position
 */

int     check(t_filler *f, t_piece p, int y, int x)
{
    int i;
    int j;
    int cross;

    if (x + p.width > f->w || y + p.height > f->h)
        return (0);
    i = 0;
    cross = 0;
    while (i < p.height)
    {
        j = 0;
        while (j < p.width)
        {
            if (p.body[i][j] == '*')
            {
                if (f->map[i + y][j + x] == f->en ||
                    f->map[i + y][j + x] == f->en_small)
                    return (0);
                else if (f->map[i + y][j + x] == f->my || f->map[i + y][j + x] == f->my_small)
                    cross++;
            }
            j++;
        }
        i++;
    }
    return (cross == 1 ? 1 : 0);
}

/*
 * function notnull return 1 if position is not 0,0
 */

int isnull(t_point x)
{
    if (x.y == 0 && x.x == 0)
        return 1;
    return 0;
}

int     get_sum(t_filler *f, t_piece p, int y, int x)
{
    int i;
    int j;
    int res;

    i = 0;
    res = 0;
    while (i < p.height)
    {
        j = 0;
        while (j < p.width)
        {
            if (p.body[i][j] == '*')
            {
                res += (f->hmap[i + y][j + x] > 0) ? f->hmap[i + y][j + x] : 0;
            }
            j++;
        }
        i++;
    }
    return (res);
}

t_point place(t_filler *f, t_piece p)
{
    t_point res;
    int i;
    int j;
    int min;

    res.x = 0;
    res.y = 0;
    min = 1000000000;
    i = 0;
    while (i <= f->h - p.height)
    {
        j = (i == 0) ? 1 : 0;
        while (j <= f->w - p.width)
        {
            if (check(f, p, i, j) && get_sum(f, p, i, j) < min)
            {
                min = get_sum(f, p, i, j);
                res.y = i;
                res.x = j;
            }
            j++;
        }
        i++;
    }
    f->over = isnull(res);
    return res;
}