/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:56:41 by bedavis           #+#    #+#             */
/*   Updated: 2020/08/03 15:59:52 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Initializer
*/

void		init(t_filler *f)
{
	f->over = 0;
	f->map_created = 0;
	f->hmap = NULL;
	f->map = NULL;
	f->h = 0;
	f->w = 0;
	f->my = 'O';
	f->my_small = 'o';
	f->en = 'X';
	f->en_small = 'x';
}

/*
** function notnull return 1 if position is not 0,0
*/

int			isnull(t_point x)
{
	if (x.y == 0 && x.x == 0)
		return (1);
	return (0);
}

/*
** Function for getting free memory of map
*/

void		free_map2(t_filler *f)
{
	int		i;

	if (!f->map)
		return ;
	i = 0;
	while (i < f->h)
	{
		ft_strdel(&f->map[i]);
		i++;
	}
	ft_memdel((void **)&f->map);
}

/*
** function for fet free memory of heat map
*/

void		free_map(t_filler *f)
{
	int		i;

	i = 0;
	if (f->hmap)
	{
		while (i < f->h)
		{
			free(f->hmap[i++]);
		}
		free(f->hmap);
		f->hmap = NULL;
	}
	free_map2(f);
}
