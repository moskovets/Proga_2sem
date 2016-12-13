#include "func.h"
#include <math.h>
#define EPS 0.001
int equal_matrix(const double** a, const double **b, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(fabs(a[i][j] - b[i][j]) > EPS) {
                printf("%lf %lf\n", a[i][j], b[i][j]);
                return 0;
            }
        }
    }
    return 1;
}
int for_test_functions(FILE *in1, FILE *in2, FILE *answer, int flag_function)
{
    assert(in1 && in2);
    int n, m, n1, m1, n2, m2;
    double **arr1 = from_file_to_arr(in1, &n1, &m1);
    double **arr2 = from_file_to_arr(in2, &n2, &m2);
    double **ans = from_file_to_arr(answer, &n, &m);
    double **res;
    if(flag_function == 1)
    {
        res = add((const double**) arr1, (const double**) arr2, n1, m1);
    }
    else
    {
        res = mult((const double**) arr1, (const double**) arr2, n1, m1, m2);
    }
    free_matrix_rows(arr1, n1);
    free_matrix_rows(arr2, n2);
    //printf("ok\n");
    int result = equal_matrix((const double**)ans, (const double**)res, n, m);
    free_matrix_rows(res, n);
    free_matrix_rows(ans, n);
    return result;
}
int for_test_inverse(FILE *in, FILE *answer)
{
    assert(in);
    int n, m, n1, m1;
    double **arr = from_file_to_arr(in, &n1, &m1);
    double **ans = from_file_to_arr(answer, &n, &m);
    double **res;
    res = inverse_matrix((const double**) arr, n1);
    free_matrix_rows(arr, n1);
    //printf("ok\n");
    int result = equal_matrix((const double**)ans, (const double**)res, n, m);
    free_matrix_rows(res, n);
    free_matrix_rows(ans, n);
    return result;
}

void test_add()
{
    FILE *in1, *in2, *res;
    printf("\nadd\n");

    printf("test1\n");
    in1 = fopen("1arr1.txt", "r");
    in2 = fopen("1arr2.txt", "r");
    res = fopen("1out.txt", "r");
    printf("%s\n", for_test_functions(in1, in2, res, 1) ? "OK" : "FAIL");
    fclose(in1);
    fclose(in2);
    fclose(res);

    printf("test2\n");
    in1 = fopen("2arr1.txt", "r");
    in2 = fopen("2arr2.txt", "r");
    res = fopen("2out.txt", "r");
    printf("%s\n", for_test_functions(in1, in2, res, 1) ? "OK" : "FAIL");
    fclose(in1);
    fclose(in2);
    fclose(res);

    printf("test3\n");
    in1 = fopen("3arr1.txt", "r");
    in2 = fopen("3arr2.txt", "r");
    res = fopen("3out.txt", "r");
    printf("%s\n", for_test_functions(in1, in2, res, 1) ? "OK" : "FAIL");
    fclose(in1);
    fclose(in2);
    fclose(res);

    printf("test4\n");
    in1 = fopen("4arr1.txt", "r");
    in2 = fopen("4arr2.txt", "r");
    res = fopen("4out.txt", "r");
    printf("%s\n", for_test_functions(in1, in2, res, 1) ? "OK" : "FAIL");
    fclose(in1);
    fclose(in2);
    fclose(res);

}

void test_mult()
{
    FILE *in1, *in2, *res;
    printf("\nmult\n");

    printf("test1\n");
    in1 = fopen("5arr1.txt", "r");
    in2 = fopen("5arr2.txt", "r");
    res = fopen("5out.txt", "r");
    printf("%s\n", for_test_functions(in1, in2, res, 2) ? "OK" : "FAIL");
    fclose(in1);
    fclose(in2);
    fclose(res);

    printf("test2\n");
    in1 = fopen("6arr1.txt", "r");
    in2 = fopen("6arr2.txt", "r");
    res = fopen("6out.txt", "r");
    printf("%s\n", for_test_functions(in1, in2, res, 2) ? "OK" : "FAIL");
    fclose(in1);
    fclose(in2);
    fclose(res);

    printf("test3\n");
    in1 = fopen("7arr1.txt", "r");
    in2 = fopen("7arr2.txt", "r");
    res = fopen("7out.txt", "r");
    printf("%s\n", for_test_functions(in1, in2, res, 2) ? "OK" : "FAIL");
    fclose(in1);
    fclose(in2);
    fclose(res);
}

void test_inverse()
{
    FILE *in, *res;
    printf("\ninverse\n");

    printf("test1\n");
    in = fopen("1arr.txt", "r");
    res = fopen("1out_inverse.txt", "r");
    printf("%s\n", for_test_inverse(in, res) ? "OK" : "FAIL");
    fclose(in);
    fclose(res);

    printf("test2\n");
    in = fopen("2arr.txt", "r");
    res = fopen("2out_inverse.txt", "r");
    printf("%s\n", for_test_inverse(in, res) ? "OK" : "FAIL");
    fclose(in);
    fclose(res);

    printf("test3\n");
    in = fopen("3arr.txt", "r");
    res = fopen("3out_inverse.txt", "r");
    printf("%s\n", for_test_inverse(in, res) ? "OK" : "FAIL");
    fclose(in);
    fclose(res);
}
int main()
{
    test_add();
    test_mult();
    test_inverse();
    return 0;
}
