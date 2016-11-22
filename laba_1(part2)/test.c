#include "func.h"
#include "write.h"
#include <stdlib.h>
#include <string.h>
unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

int equal_arrs(const int a[], const int b[], int na, int nb)
{
    if (na != nb)
        return 0;
    for (int i = 0; i < na; i++)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

void test_scan_to_arr()
{
    printf("test_scan_to_arr\n");

    FILE * file;
    int res, n;
    int a[40];

    printf("test1 ");
    int arr1[] = { 1, 2, 3, 4, 5 };
    n = 5;
    file = fopen("test1.txt", "r");
    res = scan_to_arr(file, n, a);
    fclose(file);
    printf("%s\n", (res == 0 && equal_arrs(a, arr1, n, n)) ? "OK" : "FAIL");

    printf("test2 ");
    int arr2[] = { -1, -2, -3, 4, 5, 6 };
    n = 6;
    file = fopen("test4.txt", "r");
    res = scan_to_arr(file, n, a);
    fclose(file);
    printf("%s\n", (res == 0 && equal_arrs(a, arr2, n, n)) ? "OK" : "FAIL");

    printf("test3 ");
    n = 6;
    file = fopen("test1.txt", "r");
    res = scan_to_arr(file, n, a);
    fclose(file);
    printf("%s\n", res == 1 ? "OK" : "FAIL");

    printf("test4 ");
    n = 6;
    file = fopen("test10.txt", "r");
    res = scan_to_arr(file, n, a);
    fclose(file);
    printf("%s\n", res == 1 ? "OK" : "FAIL");

    printf("test5 ");
    int arr4[] = { 1, 2, 3, 4 };
    n = 4;
    file = fopen("test1.txt", "r");
    res = scan_to_arr(file, n, a);
    fclose(file);
    printf("%s\n", (res == 0 && equal_arrs(a, arr4, n, n)) ? "OK" : "FAIL");
}

void test_scan_file_for_amount()
{
    printf("test_scan_file_for_amount function\n");

    FILE * file;
    int n;
    int res_n;

    printf("test1 ");
    res_n = 5;
    file = fopen("test1.txt", "r");
    n = scan_file_for_amount(file);
    fclose(file);
    printf("%s\n", res_n == n ? "OK" : "FAIL");

    printf("test2 ");
    res_n = 6;
    file = fopen("test4.txt", "r");
    n = scan_file_for_amount(file);
    fclose(file);
    printf("%s\n", res_n == n ? "OK" : "FAIL");

    printf("test3 ");
    res_n = 1;
    file = fopen("test5.txt", "r");
    n = scan_file_for_amount(file);
    fclose(file);
    printf("%s\n", res_n == n ? "OK" : "FAIL");

    printf("test4 ");
    res_n = 0;
    file = fopen("test7.txt", "r");
    n = scan_file_for_amount(file);
    fclose(file);
    printf("%s\n", res_n == n ? "OK" : "FAIL");
}


void test_find_place()
{
    int res;
    int n;
    int a;
    printf("test of bin poisk\n");

    printf("test1 ");
    int arr1[] = { 1, 2, 3, 4, 5 };
    res = 2;
    a = 3;
    n = 5;
    printf("%s\n", res == find_place(arr1, 0, n, sizeof(int), &a, &funccmp_int) ? "OK" : "FAIL");

    printf("test2 ");
    int arr2[] = { 1, 2, 3, 4, 5 };
    res = 0;
    a = -3;
    n = 5;
    printf("%s\n", res == find_place(arr2, 0, n, sizeof(int), &a, &funccmp_int) ? "OK" : "FAIL");

    printf("test3 ");
    int arr3[] = { 1, 2, 3, 4, 5 };
    res = 4;
    a = 10;
    n = 5;
    printf("%s\n", res == find_place(arr3, 0, n, sizeof(int), &a, &funccmp_int) ? "OK" : "FAIL");

    printf("test4 ");
    int arr4[] = { 1, 1, 3, 4, 5 };
    res = 1;
    a = 2;
    n = 5;
    printf("%s\n", res == find_place(arr4, 0, n, sizeof(int), &a, &funccmp_int) ? "OK" : "FAIL");

    printf("test5 ");
    int arr5[] = { 1 };
    res = 0;
    a = 2;
    n = 1;
    printf("%s\n", res == find_place(arr5, 0, n, sizeof(int), &a, &funccmp_int) ? "OK" : "FAIL");

    printf("test6 ");
    int arr6[] = { 1 };
    res = 0;
    a = 0;
    n = 1;
    printf("%s\n", res == find_place(arr6, 0, n, sizeof(int), &a, &funccmp_int) ? "OK" : "FAIL");

    printf("test7 ");
    int arr7[] = { 0, 1, 2, 3, 4 };
    res = 4;
    a = 6;
    n = 5;
    printf("%s\n", res == find_place(arr7, 0, n, sizeof(int), &a, &funccmp_int) ? "OK" : "FAIL");

    printf("\n\n");
}

void write_arr(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}
int for_test_my_qsort(int *arr, int n)
{
    int *a = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));
    write_arr(a, arr, n);
    write_arr(b, arr, n);
    my_qsort(a, n, sizeof(int), &funccmp_int);
    qsort(b, n, sizeof(int), &funccmp_int);
    int ret = equal_arrs(a, b, n, n);
    free(a);
    free(b);
    return ret;
}

void test_my_qsort()
{
    printf("test_my_qsort\n");
    int n;

    printf("test1 ");
    int arr1[] = { 1, 2, 3, 4, 5 };
    n = 5;
    printf("%s\n", for_test_my_qsort(arr1, n) ? "OK" : "FAIL");

    printf("test2 ");
    int arr2[] = { 5, 4, 3, 2, 1 };
    n = 5;
    printf("%s\n", for_test_my_qsort(arr2, n) ? "OK" : "FAIL");

    printf("test3 ");
    int arr3[] = { 1, 1 };
    n = 2;
    printf("%s\n", for_test_my_qsort(arr3, n) ? "OK" : "FAIL");

    printf("test4 ");
    int arr4[] = { 1, 2, 4, 1, 2 };
    n = 5;
    printf("%s\n", for_test_my_qsort(arr4, n) ? "OK" : "FAIL");

    printf("test5 ");
    int arr5[] = { 1, 4, 3, 1, 5, 9, 0, 2 };
    n = 8;
    printf("%s\n", for_test_my_qsort(arr5, n) ? "OK" : "FAIL");

    printf("test6 ");
    int arr6[] = { 2, 1 };
    n = 2;
    printf("%s\n", for_test_my_qsort(arr6, n) ? "OK" : "FAIL");

    printf("test7 ");
    int arr7[] = { 1, 2 };
    n = 2;
    printf("%s\n", for_test_my_qsort(arr7, n) ? "OK" : "FAIL");

    printf("test8 ");
    int arr8[] = { 1 };
    n = 1;
    printf("%s\n", for_test_my_qsort(arr8, n) ? "OK" : "FAIL");

}
int for_test_my_qsort_add(void *arr, int n, size_t size, int (*comparator)(const void *, const void *))
{
    void *a = malloc(n * size);
    void *b = malloc(n * size);
    memcpy(a, arr, n * size);
    memcpy(b, arr, n * size);
    my_qsort(a, n, size, comparator);
    qsort(b, n, size, comparator);
    int ret = memcmp(a, b, n * size); //ret = 0 if a == b

    free(a);
    free(b);
    return !ret;
}
typedef struct mystruct { //+float, + double
    int a;
    int b;
} my_struct;
int funccmp_mystruct(const void *val1, const void *val2)
{
    my_struct *a = (my_struct *) val1;
    my_struct *b = (my_struct *) val2;
    return b->a + b->b - a->a - a->b;
}
/*int funccmp_double(const void *val1, const void *val2)
{
    double *a = (double *) val1;
    double *b = (double *) val2;
    return *a > *b;
*/

my_struct* form_array_from_struct(const int *arr, int n)
{
    my_struct *a = malloc(n * sizeof(my_struct));
    for(int i = 0; i < n; i++)
    {
        a[i].a = arr[i];
        a[i].b = arr[i];
    }
    return a;
}
int funccmp_float(const void *val1, const void *val2)
{
    float *a = (float *) val1;
    float *b = (float *) val2;
    return *a - *b;
}

void test_my_qsort_add()
{
    printf("test_my_qsort_add\n");
    int n;
    printf("test01 ");
    float arr01[] = { 1, 2, 3, 4, 5 };
    n = 5;
    printf("%s\n", for_test_my_qsort_add(arr01, n, sizeof(float), &funccmp_float) ? "OK" : "FAIL");

    printf("test02 ");
    float arr02[] = { 5, 4, 3, 2, 1 };
    n = 5;
    printf("%s\n", for_test_my_qsort_add(arr02, n, sizeof(float), &funccmp_float) ? "OK" : "FAIL");

    printf("test03 ");
    float arr03[] = { 1, 7, 3, 5, 6 };
    n = 5;
    printf("%s\n", for_test_my_qsort_add(arr03, n, sizeof(float), &funccmp_float) ? "OK" : "FAIL");


    printf("test1 ");
    int arr1[] = { 1, 2, 3, 4, 5 };
    n = 5;
    printf("%s\n", for_test_my_qsort_add(arr1, n, sizeof(int), &funccmp_int_less) ? "OK" : "FAIL");

    printf("test2 ");
    int arr2[] = { 5, 4, 3, 2, 1 };
    n = 5;
    printf("%s\n", for_test_my_qsort_add(arr2, n, sizeof(int), &funccmp_int_less) ? "OK" : "FAIL");

    printf("test3 ");
    int arr3[] = { 1, 7, 3, 5, 6 };
    n = 5;
    printf("%s\n", for_test_my_qsort_add(arr3, n, sizeof(int), &funccmp_int_less) ? "OK" : "FAIL");

    printf("test4 ");
    n = 0;
    printf("%s\n", for_test_my_qsort_add(NULL, n, sizeof(int), &funccmp_int_less) ? "OK" : "FAIL");

    my_struct *a;

    printf("test5 ");
    int arr5[] = { 1, 7, 3, 5, 6 };
    n = 5;
    a = form_array_from_struct(arr5, n);
    printf("%s\n", for_test_my_qsort_add(a, n, sizeof(my_struct), &funccmp_mystruct) ? "OK" : "FAIL");
    free(a);

    printf("test6 ");
    int arr6[] = { 1, 2, 3, 4, 5 };
    n = 5;
    a = form_array_from_struct(arr6, n);
    printf("%s\n", for_test_my_qsort_add(a, n, sizeof(my_struct), &funccmp_mystruct) ? "OK" : "FAIL");
    free(a);

    printf("test7 ");
    int arr7[] = { 5, 3, 2, 0 };
    n = 4;
    a = form_array_from_struct(arr7, n);
    printf("%s\n", for_test_my_qsort_add(a, n, sizeof(my_struct), &funccmp_mystruct) ? "OK" : "FAIL");
    free(a);
}

int for_test_filter(int *arr, int *res, int n, int nres)
{
    int *a = malloc(n * sizeof(int));
    write_arr(a, arr, n);
    int *b = filter(a, &n);
    int ret = n == 0 ? nres == n : equal_arrs(b, res, n, nres);
    free(a);
    free(b);
    return ret;
}

void test_filter()
{
    printf("test_filter\n");
    int n, res;

    printf("test1 ");
    int arr1[] = { 1, 2, 3, 4, 5 };
    int res1[] = { 2, 3, 4 };
    n = sizeof(arr1) / sizeof(int);
    res = sizeof(res1) / sizeof(int);
    printf("%s\n", for_test_filter(arr1, res1, n, res) ? "OK" : "FAIL");

    printf("test2 ");
    int arr2[] = { 3, 5, 2, 7, 0, 2, 3 };
    n = sizeof(arr2) / sizeof(int);
    res = 0;
    printf("%s\n", for_test_filter(arr1, NULL, n, res) ? "OK" : "FAIL");

    printf("test3 ");
    int arr3[] = { 5, 4, 3, 2, 1 };
    int res3[] = { 4, 3, 2 };
    n = sizeof(arr3) / sizeof(int);
    res = sizeof(res3) / sizeof(int);
    printf("%s\n", for_test_filter(arr3, res3, n, res) ? "OK" : "FAIL");

    printf("test4 ");
    int arr4[] = { 1 };
    n = sizeof(arr4) / sizeof(int);
    res = 0;
    printf("%s\n", for_test_filter(arr4, NULL, n, res) ? "OK" : "FAIL");

    printf("test5 ");
    int arr5[] = { 2, 7, 5, 3, 1, 4, 0, 5, 0, 3 };
    int res5[] = { 5, 3, 1, 4 };
    n = sizeof(arr5) / sizeof(int);
    res = sizeof(res5) / sizeof(int);
    printf("%s\n", for_test_filter(arr5, res5, n, res) ? "OK" : "FAIL");

    printf("test6 ");
    int arr6[] = { 2, 0, 5, 3, 1, 4, 7, 5, 7, 3 };
    int res6[] = { 5, 3, 1, 4, 7, 5 };
    n = sizeof(arr6) / sizeof(int);
    res = sizeof(res6) / sizeof(int);
    printf("%s\n", for_test_filter(arr6, res6, n, res) ? "OK" : "FAIL");
}

void test_time(FILE *f, int n, int flag)
{
    unsigned long long tb, te;
    unsigned long long time_qsort, time_my_qsort;
    unsigned long long t;
    int *a = malloc(sizeof(int) * n);
    int *b = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        switch (flag)
        {
            case 0:
                tmp = rand();
                break;
            case 1:
                tmp = i;
                break;
            case 2:
                tmp = n - i;
                break;
        }
        a[i] = tmp;
        b[i] = tmp;
    }
    int i;
    t = 0;
    for(i = 0; i < 21; i++)
    {
        tb = tick();
        my_qsort(a, n, sizeof(int), &funccmp_int);
        te = tick();
        t += te - tb;
    }
    time_my_qsort = t / (long)i;

    t = 0;
    for(i = 0; i < 21; i++)
    {
        tb = tick();
        qsort(b, n, sizeof(int), &funccmp_int);
        te = tick();
        t += te - tb;
    }
    time_qsort = t / (long)i;

    fprintf(f, "%10d   %10d\n", (int)time_qsort, (int)time_my_qsort);
}

void test_compare_time()
{
    FILE * out;
    out = fopen("out.txt", "w");
    if (!out)
        return;

    for (int i = 10; i <= 500; i += 20)
    {
        fprintf(out, "%12d ", i);
        test_time(out, i, 0);
    }
    fprintf(out, "\n\n\n");

    for (int i = 10; i <= 500; i += 20)
    {
        fprintf(out, "%12d ", i);
        test_time(out, i, 1);
    }
    fprintf(out, "\n\n\n");

    for (int i = 10; i <= 500; i += 20)
    {
        fprintf(out, "%12d ", i);
        test_time(out, i, 2);
    }
    fprintf(out, "\n\n\n");
    fclose(out);
}
int main()
{
    //test_scan_file_for_amount();
    //test_scan_to_arr();
    test_find_place();
    test_my_qsort();
    test_filter();
    test_my_qsort_add();
    //printf("          n      qsort    my_qsort \n");
    //test_compare_time();
    return 0;
}
