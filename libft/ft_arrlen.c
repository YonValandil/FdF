#include "libft.h"

size_t ft_arrlen(void **arr)
{
    size_t  i;
    i = 0;

    while ((unsigned char*)arr[i])
        ++i;
    return (i);
}
