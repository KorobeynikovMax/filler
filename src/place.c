//
// Created by Макс Коробейников on 20/07/2020.
//

#include "filler.h"
#include <stdio.h>

void    create_hmap(t_filler *f)
{

}

/*
 * function checks if the piece is valid for this position
 */

int     check(t_filler *f, t_piece p, t_point pos)
{
    int res;
    int i;
    int j;
    int cross;

    res = 1;
    if (pos.x + p.width > f->w || pos.y + p.height > f->h)
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
                if (f->map[i + pos.y][j + pos.x] == 'X' ||
                    f->map[i + pos.y][j + pos.x] == 'x')
                    return (0);
                else if (f->map[i + pos.y][j + pos.x] == 'O' || f->map[i + pos.y][j + pos.x] == 'o')
                    cross++;
            }
            j++;
        }
        i++;
    }
    return (cross == 1 ? 1 : 0);
}

t_point place(t_filler *f, t_piece p)
{
    t_point res;
    int i;
    int j;

    res.x = 0;
    res.y = 0;
    //tut algoritm

    //create heatmap
    create_hmap(f);

    //perebor po vsem
    i = 0;
    while (i < f->h)
    {
        j = 0;
        while (j < f->w)
        {
            res.x = j;
            res.y = i;
            if ((f->map[i][j] == 'O' || f->map[i][j] == 'o') && check(f, p, res))
                return res;
            j++;
        }
        i++;
    }
    res.x = 0;
    res.y = 0;
    f->over = 1;
    return res;
}