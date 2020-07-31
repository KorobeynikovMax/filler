//
// Created by Benjen Davis on 7/29/20.
//

#include "filler.h"
#include <stdio.h>

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

void    create_hmap(t_filler *f)
{
    int x;
    int y;

    x = 0;
    y = 0;
    if (!(f->hmap = (int **)malloc(sizeof(int *) * (unsigned long)f->h)))
        printf("Error h!");
    while (y < f->h)
    {
        if (!(f->hmap[y] = (int *)malloc(sizeof(int) * (unsigned long)f->w)))
            printf("Error w!");
        y++;
    }
    create_hmap_0(f);
}

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

void    fill_hmap(t_filler *f)
{
    int	x;
    int	y;
    int	i;

    i = 1;
    while (i < (f->w * f->h))
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