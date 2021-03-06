/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:38:31 by bedavis           #+#    #+#             */
/*   Updated: 2020/08/03 16:49:31 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** The only one print function
*/

void			put_coord(t_point p)
{
	ft_putnbr(p.y);
	ft_putchar(' ');
	ft_putnbr(p.x);
	ft_putchar('\n');
}

/*
** Main loop function
*/

void			play(t_filler *f)
{
	char		*line;
	char		*str;

	while ((ft_get_next_line(0, &line)) > -1 && !f->over)
	{
		str = line;
		if (!ft_strncmp(line, "Plateau ", 7))
		{
			line = &line[8];
			if (parse_map(f, ft_atoi(line), ft_atoi(ft_strchr(line, ' '))))
				break ;
		}
		else if (!ft_strncmp(line, "Piece ", 5))
		{
			line = &line[6];
			put_coord(place(f, parse_piece(f, ft_atoi(line),
							ft_atoi(ft_strchr(line, ' ')))));
		}
		free(str);
		if (f->over)
			break ;
	}
	free_map(f);
}

/*
** Main, start point, check the x or o
*/

int				main(void)
{
	char		*s;
	t_filler	f;

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
	free(s);
	return (0);
}
