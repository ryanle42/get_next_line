#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

#include <stdlib.h>
#include <stdio.h>
#include "./Libft/includes/libft.h"

typedef struct          a_list
{
    int                 file;
    int                 ret;
    char                *extra;
    struct a_list       *next;
}                       b_list;

#endif