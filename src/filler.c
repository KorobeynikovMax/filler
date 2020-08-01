/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:20:21 by bedavis           #+#    #+#             */
/*   Updated: 2020/07/31 14:34:52 by maxim            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** The only one print function
*/

void        put_coord(t_filler *f, t_point p)
{
    ft_putnbr(p.y);
    ft_putchar(' ');
    ft_putnbr(p.x);
    ft_putchar('\n');
}

/*
** Main loop function
*/

void        play(t_filler *f)
{
    char    *line;

    while ((ft_get_next_line(0, &line)) > -1 && !f->over)
    {
        if (!ft_strncmp(line, "Plateau ", 7))
        {
            line = &line[8];
            parse_map(f, ft_atoi(line), ft_atoi(ft_strchr(line, ' ')));
        }
        else if (!ft_strncmp(line, "Piece ", 5))
        {
            line = &line[6];
            put_coord(f, place(f,parse_piece(f, ft_atoi(line), ft_atoi(ft_strchr(line, ' ')))));
        }
        if (f->over)
            break;
    }
}

/*
** Main, start point, check the x or o
*/

int			main(void)
{
    char *s;
    t_filler f;

    ft_bzero(&f, sizeof(t_filler));
    init(&f);
    if (ft_get_next_line(0, &s) && (!ft_strncmp(s, "$$$ exec p", 9)))
    {
        f.my = 'X';
        f.my_small = 'x';
        f.en = 'O';
        f.en_small = 'o';
        if (s[10] == '1')
        {
            f.my = 'O';
            f.my_small = 'o';
            f.en = 'X';
            f.en_small = 'x';
        }
        play(&f);
    }
	return (0);
}
