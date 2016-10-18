#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "write.h"
#include "func.h"

/*
¬ычислить значение x[0]*y[0]+x[1]*y[1]+ ... + x[k]*y[k], где x[i] Ц отрицательные элементы массива a из n элементов,
 вз€тые в пор€дке их следовани€; y[i] Ц положительные элементы этого массива, вз€тые в обратном пор€дке;
  k = min(p,q), где p Ц количество положительных элементов массива a, q Ц количество отрицательных элементов этого массива.
*/
int main(int argc, char const **argv)
{
    if (argc < 2)
        printf("Enter name of file!\n");
    else
    {
        FILE * f_inp;
        f_inp = fopen(argv[1], "r");
        if (f_inp == NULL)
        {
            printf("Cannot open file for input\n");
            return 0; //diff cod
        }

        int n = scan_file_for_amount(f_inp);

        if (n == 0)
        {
            printf("File is empty\n");
            fclose(f_inp);
            return 0; //diff cod
        }

        /*if (fseek(f_inp, 0L, SEEK_SET) != 0)
        {
            printf("Cannot move pointer into begin\n");
            return 0;
        }*/
        rewind(f_inp);

        int *arr = (int *) malloc(n * sizeof(int));
        if (arr == NULL)
        {
            printf("Cannot allocate mamory for array\n");
            fclose(f_inp);
            return 0;
        }

        if(scan_to_arr(f_inp, n, arr) != 0)
        {
            printf("Error with reading into arr\n");
            free(arr);
            fclose(f_inp);
            return 0;
        }

        int res = result(arr, arr + n);
        printf("Mult of positive and negatve numbers is %d", res);

        fclose(f_inp);
        free(arr);
    }
    return 0;
}

