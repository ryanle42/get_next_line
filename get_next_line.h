#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

#include <stdlib.h>
#include <stdio.h>
#include "./Libft/libft.h"

typedef struct          a_list
{
    int                 file;
    int                 pos;
    struct a_list       *next;
}                       b_list;

#endif