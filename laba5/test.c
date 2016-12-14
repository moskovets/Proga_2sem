#include "func.h"
#include "string.h"
void test_snprintf()
{
    int res_n, res_my;
    char a[50], res[50];

    printf("test1\n");
    res_n = snprintf(res, 4, "%I64o",(long long int) -123);
    res_my = my_snprintf(a, 4, "%llo",(long long int) -123);
    printf("%s\n%s\n", a, res);
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test2\n");
    res_n = snprintf(res, 4, "%I64o",(long long int) -8);
    res_my = my_snprintf(a, 4, "%llo",(long long int) -8);
    printf("%s\n%s\n", a, res);
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test3\n");
    res_n = snprintf(res, 30, "%I64o",(long long int) -123);
    res_my = my_snprintf(a, 30, "%llo",(long long int) -123);

    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test4\n");
    res_n = snprintf(res, 30, "%I64o",(long long int) -8);
    res_my = my_snprintf(a, 30, "%llo",(long long int) -8);
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test5\n");
    res_n = snprintf(res, 20, "%c", 'a');
    res_my = my_snprintf(a, 20, "%c", 'a');
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test6\n");
    res_n = snprintf(res, 20, " %c ", 'a');
    res_my = my_snprintf(a, 20, " %c ", 'a');
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test7\n");
    res_n = snprintf(res, 20, " %s %s ", "hello", "test");
    res_my = my_snprintf(a, 20, " %s %s ", "hello", "test");
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test8\n");
    res_n = snprintf(res, 20, " %s %c ", "hello", '!');
    res_my = my_snprintf(a, 20, " %s %c ", "hello", '!');
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test9\n");
    res_n = snprintf(res, 20, "%I64o", (long long int) 123);
    res_my = my_snprintf(a, 20, "%llo", (long long int) 123);
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test10\n");
    res_n = snprintf(res, 20, "%I64o %s", (long long int) 8, "hello");
    res_my = my_snprintf(a, 20, "%llo %s", (long long int) 8, "hello");
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test10\n");
    res_n = snprintf(res, 20, "%I64o %s", (long long int) 0, "");
    res_my = my_snprintf(a, 20, "%llo %s", (long long int) 0, "");
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test11\n");
    res_n = snprintf(res, 4, " %s %c ", "hello", '!');
    res_my = my_snprintf(a, 4, " %s %c ", "hello", '!');
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");

    printf("test11\n");
    res_n = snprintf(res, 7, " %s %c ", "hello", '!');
    res_my = my_snprintf(a, 7, " %s %c ", "hello", '!');
    printf("%s\n", !strcmp(a, res) && res_n == res_my ? "OK" : "FAIL");
}
int main()
{
    test_snprintf();
    //char a[51];
    /*snprintf(a, 50, "%I64o",(long long int) -123);
    printf("%s\n", a);
    snprintf(a, 50, "%I64o",(long long int) 123);
    printf("%s\n", a);
    snprintf(a, 50, "%I64o",(long long int) 8);
    printf("%s\n", a);
    snprintf(a, 50, "%I64o",(long long int) -1);
    printf("%s\n\n", a);


    my_snprintf(a, 50, "%llo",(long long int) -123);
    printf("%s\n", a);
    my_snprintf(a, 50, "%llo",(long long int) 123);
    printf("%s\n", a);
    my_snprintf(a, 50, "%llo",(long long int) 8);
    printf("%s\n", a);
    my_snprintf(a, 50, "%llo",(long long int) -1);
    printf("%s\n\n", a);
*/
   // printf("%d \n\n", snprintf(a, 2, "%s %d %c", "один", 2, '3'));

    return 0;

}
