#include "func.h"

#include <stdio.h>
#include <assert.h>
/*
¬ычислить значение x[0]*y[0]+x[1]*y[1]+ ... + x[k]*y[k], где x[i] Ц отрицательные элементы массива a из n элементов,
 вз€тые в пор€дке их следовани€; y[i] Ц положительные элементы этого массива, вз€тые в обратном пор€дке;
  k = min(p,q), где p Ц количество положительных элементов массива a, q Ц количество отрицательных элементов этого массива.
*/
int result(const int *l, const int *r)
{
    assert(l != NULL && r != NULL && l < r);
    int res = 0;

    const int *pos = r - 1;
    const int *neg = l;

    while (pos >= l && neg < r)
    {
        while (*pos <= 0 && pos > l)
            pos--;
        while (*neg >= 0 && neg < r - 1)
            neg++;

        if (*pos > 0 && *neg < 0)
            res += (*pos) * (*neg);
        //if (pos == l || neg == r - 1)
        //    break;
        pos--;
        neg++;
    }
    return res;
}
