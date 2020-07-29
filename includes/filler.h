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
    /* koeficents main loop */
    int                 k_i;
    int                 k_j;
}                       t_filler;

void                    init(t_filler *f);
void                    parse_map(t_filler *f, int height, int width);
t_piece                 parse_piece(t_filler *f, int height, int width);
t_point                 place(t_filler *f, t_piece p);
void                    create_hmap(t_filler *f);
void                    make_hmap(t_filler *f);
void                    fill_hmap(t_filler *f);


#endif
