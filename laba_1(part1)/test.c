#include "func.h"
#include "write.h"

int equal_arrs(const int a[], const int b[], int na, int nb)
{
    if(na != nb)
        return 0;
    for(int i = 0; i < na; i++)
    {
        if(a[i] != b[i])
            return 0;
    }
    return 1;
}

void test_scan_to_arr()
{
    printf("test_scan_to_arr\n");

    FILE *file;
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

    FILE *file;
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


void test_result()
{
    int res, n;
    printf("test of result function\n");

    printf("test1 ");
    int arr1[] = { 1, 2, 3, 4, 5 };
    res = 0;
    n = 5;
    printf("%s\n", res == result(arr1, arr1 + n) ? "OK" : "FAIL");

    printf("test2 ");
    int arr2[] = { -1, -2, -3, -4 };
    res = 0;
    n = 4;
    printf("%s\n", res == result(arr2, arr2 + n) ? "OK" : "FAIL");

    printf("test3 ");
    int arr3[] = { 1, -2, 3, -4, 5 };
    res = -22;
    n = 5;
    printf("%s\n", res == result(arr3, arr3 + n) ? "OK" : "FAIL");

    printf("test4 ");
    int arr4[] = { -1, -2, -3, 4, 5, 6 };
    res = -28;
    n = 6;
    printf("%s\n", res == result(arr4, arr4 + n) ? "OK" : "FAIL");

    printf("test5 ");
    int arr5[] = { 1 };
    res = 0;
    n = 1;
    printf("%s\n", res == result(arr5, arr5 + n) ? "OK" : "FAIL");

    printf("\n\n");
}

int main()
{
    test_result();
    test_scan_file_for_amount();
    test_scan_to_arr();

    return 0;
}
