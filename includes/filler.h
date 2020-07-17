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
}                       t_filler;

void                    init(t_filler *f);

#endif
