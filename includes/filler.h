#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define BUF_SIZE		64

typedef struct          s_point
{
    int                 x;
    int                 y;
}                       t_point;

typedef struct          s_piece
{
    int                 width;
    int                 height;
    char                **body;
}                       t_piece;

typedef struct          s_filler
{
    t_point             coord;
    int                 player;
    int                 over;
    int                 map_created;
    char                **map;
    char                **hmap;
    int                 h;
    int                 w;
}                       t_filler;

void                    init(t_filler *f);
void                    parse_map(t_filler *f, int height, int width);
t_piece                 parse_piece(t_filler *f, int height, int width);
t_point                 place(t_filler *f, t_piece p);

#endif
