#include <stdio.h>
#include <stdlib.h>
#include "write.h"
/*
1 - сортировка списка
2 - разворот списка
*/
//operations, in_file, out_file
int main(int argc, char const **argv)
{
    if (argc < 4)
    {
        printf("Enter arguments!\n");
        return 0;
    }
    FILE *f_inp, *f_out;
    int operations = 0;
    char *ch;
    operations = strtol(argv[1], &ch, 0);
    f_inp = fopen(argv[2], "r");
    if(!f_inp)
    {
        printf("Cannot open file for input\n");
        return 0; //diff cod
    }
    Data *arr;
    int arr_size;
    if(fscanf(f_inp, "%d", &arr_size) != 1)
    {
        printf("Error in data\n");
        fclose(f_inp);
        return 0;
    }
    arr = malloc(arr_size * sizeof(Data));
    if(!arr)
    {
        printf("Error with memory\n");
        fclose(f_inp);
        return 0;
    }
    if(from_file_to_database(f_inp, &arr, arr_size) == 1)
    {
        printf("Error in data\n");
        fclose(f_inp);
        free(arr);
        return 0;
    }
    fclose(f_inp);
    list *head = from_database_to_list(arr, arr_size);
    switch(operations)
    {
    case 1:
        merge_sort(&head, &funccmp_Data);
        break;
    case 2:
        reverse(&head);
        break;
    default:
            printf("Error operation!\n");
            return 0;
    }
    f_out = fopen(argv[3], "w");
    if (f_out == NULL)
    {
        printf("Cannot open file for output\n");
        free(arr);
        return 0; //diff cod
    }
    write_from_list_to_file(f_out, head);
    free_all(head);
    fclose(f_out);
    free(arr);
    return 0;
}
