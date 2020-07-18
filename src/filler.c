/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:20:21 by bedavis           #+#    #+#             */
/*   Updated: 2020/07/16 20:34:34 by maxim            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void        put_coord(t_filler *f, int x, int y)
{
    ft_putnbr(x);
    ft_putchar(' ');
    ft_putnbr(y);
    ft_putchar('\n');
}

void        force_exit(t_filler *f)
{
    f->over = 1;
    put_coord(f, 0, 0);
}

void        play(t_filler *f)
{
    char    *line;
    int     res = 1;

    while ((ft_get_next_line(0, &line)) > -1 && !f->over)
    {
        if (!ft_strncmp(line, "Plateau ", 7))
        {
            line = &line[8];
            parse_map(f, ft_atoi(line), ft_atoi(ft_strchr(line, ' ')));
        }
        if (!ft_strncmp(line, "Piece ", 5))
        {
            line = &line[6];
            parse_piece(f, ft_atoi(line), ft_atoi(ft_strchr(line, ' ')));
        }
        if (!f->over)
            put_coord(f, 2 ,2);
        else
            force_exit(f);
    }
}

int			main(void)
{
    char *s;
    int i = 0;
    int res;
    t_filler f;

    ft_bzero(&f, sizeof(t_filler));
    init(&f);
    if (ft_get_next_line(0, &s) && (!ft_strncmp(s, "$$$ exec p", 9)))
    {
        f.player = (s[10] == '1') ? 0 : 1;
        play(&f);
    }
	return (0);
}