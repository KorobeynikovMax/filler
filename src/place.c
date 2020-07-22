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

/*
 * function notnull return 1 if position is not 0,0
 */

int notnull(t_point x)
{
    if (x.y == 0 && x.x == 0)
        return 0;
    return 1;
}

/*
 * function perebor place the piece in all variants around the point
 */

t_point     perebor(t_filler *f, t_piece p, t_point pos)
{
    int start_j;
    int start_i;
    int fin_j;
    int fin_i;
    t_point result;

    start_i = (pos.y - p.height + 1) >= 0 ? (pos.y - p.height + 1) : 0;
    //start_j = (pos.x - p.width) >= 0 ? (pos.x - p.width) : 0;
    fin_i = (pos.y + p.height) < f->h ? (pos.y) : (f->h - p.height);
    fin_j = (pos.x + p.width) < f->w ? (pos.x) : (f->w - p.width);
    while (start_i <= fin_i)
    {
        start_j = (pos.x - p.width + 1) >= 0 ? (pos.x - p.width + 1) : 0;
        while (start_j <= fin_j)
        {
            result.x = start_j;
            result.y = start_i;
            if (check(f, p, result))
                return result;
            start_j++;
        }
        start_i++;
    }
    result.x = 0;
    result.y = 0;
    return result;
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
            /*if ((f->map[i][j] == 'O' || f->map[i][j] == 'o') && check(f, p, res))
                return res;*/
            if ((f->map[i][j] == 'O' || f->map[i][j] == 'o') && (notnull(perebor(f, p, res))))
                return perebor(f, p, res);
            j++;
        }
        i++;
    }
    res.x = 0;
    res.y = 0;
    f->over = 1;
    return res;
}