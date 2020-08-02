/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 14:01:43 by bedavis           #+#    #+#             */
/*   Updated: 2020/08/03 01:27:36 by maxim            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Function checks if the piece is valid for this position
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
** Counting the sum of heat weights for this piece
*/

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


void free_piece(t_piece *p)
{
    int		i;
    char	*str;

    if (!p->body)
        return ;
    i = 0;
    while (i < p->height)
    {
        str = p->body[i];
        ft_strdel(&str);
        i++;
    }
    ft_memdel((void **)&p->body);
}

/*
** Function returns the t_point with final decision
*/

t_point place(t_filler *f, t_piece p)
{
    t_point res;
    int i;
    int j;
    int min;

    res.x = 0;
    res.y = 0;
    min = MYMAX_INT;
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
    free_piece(&p);
    return (res);
}
