#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <stdlib.h>

const int* find_start_and_filter(const int* arr, int n, int* len);
int* filter(const int *arr, int *n);

int find_place(void *a, int l, int r, size_t size, const void *elem, int (*comparator)(const void *, const void *));
/*≈сли val1 меньше, равен или больше, чем val2, функци€ должна вернуть отрицательное значение, ноль или положительное значение, соответственно.*/
int funccmp_int(const void *val1, const void *val2);

void my_qsort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *));
int funccmp_int_less(const void *val1, const void *val2);


#endif // FUNC_H_INCLUDED


