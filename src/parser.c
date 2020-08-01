/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 13:47:14 by bedavis           #+#    #+#             */
/*   Updated: 2020/08/01 00:37:40 by maxim            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Parsing the token
*/

t_piece    parse_piece(t_filler *f, int height, int width)
{
    int i;
    char *line;
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

/*
** Creating the map first time, 4 is the offset for coordinates
*/

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
        f->map[i] = line + 4;
        i++;
    }
    create_hmap(f);
}

/*
** Map parsing, 4 is the offset for coordinates
*/

void        parse_map(t_filler *f, height, width)
{
    char *line;
    int i;

    i = 0;
    ft_get_next_line(0, &line);
    if (!f->map_created)
        create_map(f, height, width);
    else
        {
            while (i < height)
            {
                ft_get_next_line(0, &line);
                f->map[i] = line + 4;
                i++;
            }
            create_hmap_0(f);
        }
    //write freeer map
}
