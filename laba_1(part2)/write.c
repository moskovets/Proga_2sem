#include "write.h"

/*
    scanning file and return amount of numbers in it into
*/
int scan_file_for_amount(FILE *f)
{
    assert(f != NULL);

    int n = 0;
    int x;
    while (fscanf(f, "%d", &x) == 1)
        n++;
    return n;
}
/*
    scanning file and return pointer to array of numbers
*/
int scan_to_arr(FILE *f, int n, int *a)
{
    assert(f != NULL);
    int *j = a;
    for (int i = 0; i < n; ++i)
    {
//        fscanf(f, "%d", a + i);
        if (fscanf(f, "%d", j++) != 1)
            return 1;
    }
    return 0;
}

void print_to_file(FILE *f, int n, int *a)
{
    assert(f != NULL);
    for (int *i = a; i < a + n; i++)
    {
        fprintf(f, "%d ", *i);
    }
}
