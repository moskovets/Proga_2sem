#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "write.h"
#include "func.h"

/*

*/
//Параметры командной строки: имя входного, выходного файла, строка, строка-замена
int main(int argc, char const **argv)
{
    if (argc < 5)
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
        FILE * f_out;
        f_out = fopen(argv[2], "r");
        if (f_out == NULL)
        {
            printf("Cannot open file for output\n");
            return 0; //diff cod
        }

        char str* = NULL;
        while(str = from_file_to_string(f_inp))
        {
            str = replace_all(str, argv[3], ardv[4]);
            fprintf(f, "%s", str);
            free(str);
        }
        fclose(f_inp);
        fclose(f_out);
    }
    return 0;
}

