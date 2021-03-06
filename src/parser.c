/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:00:56 by bedavis           #+#    #+#             */
/*   Updated: 2020/08/03 16:05:33 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Parsing the token
*/

t_piece		parse_piece(t_filler *f, int height, int width)
{
	int		i;
	char	*line;
	t_piece	p;

	p.width = width;
	p.height = height;
	if (!(p.body = ft_memalloc(height * sizeof(char *))))
	{
		f->over = 1;
		return (p);
	}
	i = 0;
	while (i < height)
	{
		ft_get_next_line(0, &line);
		p.body[i] = line;
		i++;
	}
	return (p);
}

/*
** Creating the map first time, 4 is the offset for coordinates
*/

int			create_map(t_filler *f, int height, int width)
{
	int		i;
	char	*line;

	i = 0;
	f->h = height;
	f->w = width;
	f->map_created = 1;
	if (!(f->map = (char **)ft_memalloc(height * sizeof(char *))))
		return (1);
	while (i < height)
	{
		if (!(f->map[i] = (char *)ft_memalloc((width + 1) * sizeof(char))))
			return (1);
		ft_get_next_line(0, &line);
		ft_strcpy(f->map[i], line + 4);
		ft_strdel(&line);
		i++;
	}
	return (create_hmap(f));
}

/*
** Map parsing, 4 is the offset for coordinates
*/

int			parse_map(t_filler *f, int height, int width)
{
	char	*line;
	int		i;

	i = 0;
	ft_get_next_line(0, &line);
	free(line);
	if (!f->map_created)
	{
		if (create_map(f, height, width))
			return (1);
	}
	else
	{
		while (i < height)
		{
			ft_get_next_line(0, &line);
			ft_strcpy(f->map[i], line + 4);
			ft_strdel(&line);
			i++;
		}
		create_hmap_0(f);
	}
	return (0);
}
