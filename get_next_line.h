#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

#include <stdlib.h>
#include <stdio.h>

typedef struct          s_list
{
    int                 file;
    int                 pos;
    struct s_list       *next;
}                       t_list;

#endif