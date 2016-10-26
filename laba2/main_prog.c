#include <stdio.h>
#include <stdlib.h>
#include "write.h"
//#include "mylist.h"
/*
Вариант 6
Разработайте программу, которая вводит из файла, имя которого определяется в командной строке,
числа и помещает их в линейный односвязный список так, чтобы элементы его составляли убывающую последовательность.
Из списка удаляются все элементы, попадающие в интервал, определенный числами, указанными в командной строке.
Числа из списка записать в файл, имя которого определяется в командной строке.
*/
/*file_input | file_output | left | right  - имена файлов + границы интервала*/
int main(int argc, char const **argv)
{
    if (argc < 5)
        printf("Enter param in command line!\n");
    else
    {
        FILE * f_inp;
        f_inp = fopen(argv[1], "r");
        if (f_inp == NULL)
        {
            printf("Cannot open file for input\n");
            return 0; //diff cod
        }
        int l, r;
        l = atoi(argv[3]); //strtol()
        r = atoi(argv[4]);
        if (l > r)
        {
            fclose(f_inp);
            printf("l > r!\n");
            return 0;
        }

        list *head = from_file_to_list(f_inp);
        fclose(f_inp);
        if (!head)
        {
            printf("File is empty or cannot allocate memory for list\n");
            return 0;
        }

        head = del_interval(head, l, r);
        if (!head)
        {
            printf("list is empty\n");
        }

        FILE * f_out;
        f_out = fopen(argv[2], "w");
        if (f_out == NULL)
        {
            printf("Cannot open file for writting\n");
            free_all(head);
            return 0;
        }
        write_from_list_to_file(f_out, head);
        fclose(f_out);
        free_all(head);
    }
    return 0;
}
