#include "func.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

const int* find_start_and_filter(const int* arr, int n, int* len)
{
    const int *i = arr;
    const int *pmin = arr;
    const int *pmax = arr;
    while (i < arr + n)
    {
        if (*pmin > *i)
            pmin = i;
        if (*pmax <= *i)
            pmax = i;
        i++;
    }
    if (pmax > pmin)
    {
        *len = pmax - pmin - 1;
        return pmin;
    }
    *len = pmin - pmax - 1;
    return pmax;
}
/*
¬ массиве остаютс€ элементы расположенные между минимальным и максимальным элементами массива
*/
int* filter(const int *arr, int *n)
{
    const int *i = NULL;
    int len = 0;
    const int *p_start = find_start_and_filter(arr, *n, &len);

    int *new_arr = malloc(sizeof(int) * (len > 1 ? len : 1)); //memory check
    if (!new_arr)
    {
        return NULL;
    }
    int *j = new_arr;
    for (i = p_start + 1; i <= p_start + len; i++)
    {
        *j = *i;
        j++;
    }
    *n = len > 0 ? len : 0;
    return new_arr;
}

int find_place(void *a, int l, int r, size_t size, const void *elem, int (*comparator)(const void *, const void *))
{
    int m = l + ((r - l) / 2);
    if (m == l)
    {
        return m;
    }
    if (comparator((char *)a + m * size, elem) > 0)
        return find_place(a, l, m, size, elem, comparator);
    else
        return find_place(a, m, r, size, elem, comparator);
}
/*≈сли val1 меньше, равен или больше, чем val2, функци€ должна вернуть отрицательное значение, ноль или положительное значение, соответственно.*/
int funccmp_int(const void *val1, const void *val2)
{
    int *a = (int *) val1;
    int *b = (int *) val2;
    return *a - *b;
}
int funccmp_int_less(const void *val1, const void *val2)
{
    int *a = (int *) val1;
    int *b = (int *) val2;
    return *b - *a;
}

void my_qsort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *))
{
    char *f = (char *) first;
    char tmp[size];
    for (char *i = f; i < f + number * size; i += size)
    {
        int index = find_place(f, 0, (i - f) / size, size, i, comparator);
        //char *tmp = malloc(size); //memory, за цикл вынести, char[size]
        memcpy(tmp, i, size);
        char *j;
        memmove(f + (index + 1)* size, f + index * size, (i - f + index));
        /*for (j = i; j > f + index * size; j -= size) //memmove
        {
            memcpy(j, j - size, size);
        }*/
        j = f + index * size;
        if (comparator(j, tmp) >= 0)
            memcpy(j, tmp, size);
        else
            memcpy(j + size, tmp, size);
        //free(tmp);
    }
}
