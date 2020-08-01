#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define MYMAX_INT		2147483647

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
    int                 over;
    int                 map_created;
    char                **map;
    int                 **hmap;
    int                 h;
    int                 w;
    char                my;
    char                my_small;
    char                en;
    char                en_small;
}                       t_filler;

void                    init(t_filler *f);
int                     isnull(t_point x);
int                     parse_map(t_filler *f, int height, int width);
t_piece                 parse_piece(t_filler *f, int height, int width);
t_point                 place(t_filler *f, t_piece p);
int                    create_hmap(t_filler *f);
void                    make_hmap(t_filler *f);
void                    fill_hmap(t_filler *f);
void                    create_hmap_0(t_filler *f);
void                    free_map(t_filler *f);

#endif
