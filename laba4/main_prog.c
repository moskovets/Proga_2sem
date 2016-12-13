#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "func.h"

/*
операция
1 - сложение
2 - умножение
3 - обратная матрица
*/
//Параметры командной строки: операций, файл с первой матрицей, (по необходимости со второй матрицей), файл для результирующей матрицы
int main(int argc, char const **argv)
{
    if (argc < 4)
    {
        printf("Enter arguments!\n");
        return 0;
    }
    int nres = 0, mres = 0;
    double **res = NULL;
    int n1, n2, m1, m2;
    double **arr1 = NULL, **arr2 = NULL;
    FILE *f_inp1, *f_inp2, *f_out;
    int operations = 0;
    char *ch;
    int out = 3;
    operations = strtol(argv[1], &ch, 0);

    switch(operations)
    {
    case 1:
    case 2:
        if (argc < 5)
        {
            printf("Enter arguments!\n");
            break;
        }
        out = 4;
        f_inp1 = fopen(argv[2], "r");
        f_inp2 = fopen(argv[3], "r");
        if (f_inp1 == NULL || f_inp2 == NULL)
        {
            printf("Cannot open file for input\n");
            return 0; //diff cod
        }
        arr1 = from_file_to_arr(f_inp1, &n1, &m1);
        arr2 = from_file_to_arr(f_inp2, &n2, &m2);
        fclose(f_inp1);
        fclose(f_inp2);
        if(!arr1 || !arr2) {
            printf("Error in reading");
            return 0;
        }
        if((operations == 1 && (n1 != n2 || m1 != m2)) || (operations == 2 && n2 != m1))
        {
            printf("Arrays have different size\n");
            free_matrix_rows(arr1, n1);
            free_matrix_rows(arr2, n2);
            return 0;
        }
        if(operations == 1)
        {
            res = add((const double**) arr1, (const double**) arr2, n1, m1);
        }
        else
        {
            res = mult((const double**) arr1, (const double**) arr2, n1, m1, m2);
        }
        nres = n1;
        mres = m2;
        break;
    case 3:
        out = 3;
        f_inp1 = fopen(argv[2], "r");
        if (f_inp1 == NULL)
        {
            printf("Cannot open file for input\n");
            return 0; //diff cod
        }
        arr1 = from_file_to_arr(f_inp1, &n1, &m1);
        fclose(f_inp1);
        if(!arr1)
        {
            printf("Error in reading");
            return 0;
        }
        if(n1 != m1)
        {
            printf("Matrix is not kvadrat");
            free_matrix_rows(arr1, n1);
            return 0;
        }
        res = inverse_matrix((const double**) arr1, n1);
        nres = n1;
        mres = n1;
        break;
    default:
            printf("Error operation!\n");
            return 0;
        }
    free_matrix_rows(arr1, n1);
    free_matrix_rows(arr2, n2);
    f_out = fopen(argv[out], "w");
    if (f_out == NULL)
    {
        printf("Cannot open file for output\n");
        return 0; //diff cod
    }
    from_matrix_to_file(f_out, (const double**) res, nres, mres);
    free_matrix_rows(res, nres);
    fclose(f_out);
    return 0;
}

