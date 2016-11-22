#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "write.h"
#include "func.h"


//Параметры командной строки: имя входного, выходного файла, 1 если фильтр нужен
int main(int argc, char const **argv)
{
    if (argc < 4)
        printf("Enter name of file!\n");
    else
    {
        FILE * f_inp;
        f_inp = fopen(argv[1], "r");
        if (f_inp == NULL)
        {
            printf("Cannot open file for input\n");
            return 0;
        }

        int n = scan_file_for_amount(f_inp);

        if (n == 0)
        {
            printf("File is empty\n");
            fclose(f_inp);
            return 0;
        }

        rewind(f_inp);

        int *arr = (int *) malloc(n * sizeof(int));
        if (arr == NULL)
        {
            printf("Cannot allocate mamory for array\n");
            fclose(f_inp);
            return 0;
        }

        if (scan_to_arr(f_inp, n, arr) != 0)
        {
            printf("Error with reading into arr\n");
            free(arr);
            fclose(f_inp);
            return 0;
        }
        fclose(f_inp);

        char *ch;
        int* arr_copy = arr;

        if (strtol(argv[3], &ch, 0) == 1)
        {
            arr = filter(arr, &n);
        }
        ch = NULL;

        my_qsort(arr, n, sizeof(int), &funccmp_int);

        FILE * f_out;
        f_out = fopen(argv[2], "w");

        if (f_out == NULL)
        {
            printf("Cannot open file for output\n");
            free(arr);
            if (arr)
                free(arr);
            if (arr != arr_copy)
                free(arr_copy);
            return 0;
        }

        print_to_file(f_out, n, arr);
        //printf("n = %d\n", n);

        if (arr)
            free(arr);
        if (arr != arr_copy)
            free(arr_copy);
        fclose(f_out);
    }
    return 0;
}

