/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 13:47:14 by bedavis           #+#    #+#             */
/*   Updated: 2020/07/27 16:44:46 by maxim            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "filler.h"
#include <stdio.h>

t_piece    parse_piece(t_filler *f, int height, int width)
{
    int i;
    char *line;

    i = 0;
    t_piece p;
    p.width = width;
    p.height = height;
    p.body = ft_memalloc(height * sizeof(char *));
    i = 0;
    while (i < height)
    {
        ft_get_next_line(0, &line);
        p.body[i] = line;
        i++;
    }
    return p;
}

void    make_koef(t_filler *f)
{
    int i;
    int j;
    int i_O;
    int j_O;

    i = 0;
    while (i < f->h)
    {
        j = 0;
        while (j < f->w)
        {
            if (f->map[i][j] == f->my)
            {
                i_O = i;
                j_O = j;
            }
            j++;
        }
        i++;
    }
    f->k_i = (i_O < f->h / 2) ? -1 : 1;
    f->k_j = (j_O < f->w / 2) ? -1 : 1;
}

void        create_map(t_filler *f, int height, int width)
{
    int i;
    char *line;

    i = 0;
    f->h = height;
    f->w = width;
    f->map_created = 1;

    f->map = ft_memalloc(height * sizeof(char *));
    while (i < height)
    {
        ft_get_next_line(0, &line);
        f->map[i] = line + 4; //сдвиг для координат
        i++;
    }
    //make_koef(f);
    create_hmap(f);
}

void        parse_map(t_filler *f, height, width)
{
    int res;
    char *line;
    int i;
    int j;

    i = 0;
    j = 0;
    res = ft_get_next_line(0, &line);
    //over here is working

    if (!f->map_created)
        create_map(f, height, width);
    else
        {
        while (i < height) {
            ft_get_next_line(0, &line);
            f->map[i] = line + 4; //сдвиг для координат
            i++;
        }
        create_hmap_0(f);
    }
    //write freeer map
}
