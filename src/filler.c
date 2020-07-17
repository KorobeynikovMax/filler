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

void        put_coord(t_filler *f)
{
    ft_putnbr(f->coord.x);
    ft_putchar(' ');
    ft_putnbr(f->coord.y);
    ft_putchar('\n');
}

void        play(t_filler *f)
{
    char    *line;
    int     res;

    res = ft_get_next_line(0, &line);
    ft_putstr(line);
    ft_putnbr(res);
    put_coord(f);
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
        printf("!!%d!!!", f.player);
        play(&f);
    }
	return (0);
}