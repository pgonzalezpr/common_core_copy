#include "../include/utils.h"

int     *zero_array(int len)
{
    int *arr;

    if (len <= 0)
        return (NULL);
    arr = malloc(len * sizeof(int));
    if (!arr)
        return (NULL);
    while (len > 0)
        arr[--len] = 0;
    return (arr);
}