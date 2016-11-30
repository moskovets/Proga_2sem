#include "mycstring.h"
#include "func.h"
#include <string.h>
#include <stdio.h>


void test_my_strchr()
{
    char *str;
    printf("test_my_strchr\n");

    printf("test1 ");
    str = "hello";
    printf("%s\n", strchr(str, 'h') == my_strchr(str, 'h') ? "OK" : "FAIL");

    printf("test2 ");
    printf("%s\n", strchr(str, 'o') == my_strchr(str, 'o') ? "OK" : "FAIL");

    printf("test3 ");
    printf("%s\n", strchr(str, '\0') == my_strchr(str, '\0') ? "OK" : "FAIL");

    printf("test4 ");
    printf("%s\n", strchr(str, 'q') == my_strchr(str, 'q') ? "OK" : "FAIL");

    printf("test5 ");
    str = "";
    printf("%s\n", strchr(str, '\0') == my_strchr(str, '\0') ? "OK" : "FAIL");

    printf("test6 ");
    printf("%s\n", strchr(str, 'q') == my_strchr(str, 'q') ? "OK" : "FAIL");

    printf("test7 ");
    str = "aaaaabaaaa";
    printf("%s\n", strchr(str, 'a') == my_strchr(str, 'a') ? "OK" : "FAIL");

    printf("test8 ");
    str = NULL;

    printf("%s\n", my_strchr(str, 'a') == NULL ? "OK" : "FAIL");// а стандартная так не может :)

    printf("test9 ");
    str = "aaaaaa\0b";
    printf("%s\n", strchr(str, 'b') == my_strchr(str, 'b') ? "OK" : "FAIL");

    printf("test10 ");
    str = "aaaaaa\0b";
    printf("%s\n", strchr(str, '\0') == my_strchr(str, '\0') ? "OK" : "FAIL");

    printf("\n\n");
}

void tmp_test_for_test_my_strdup(const char *str)
{
    char *str1, *str2;
    str1 = strdup(str);
    str2 = my_strdup(str);
    if (!str1)
    {
        printf("%s\n", !str2 ? "OK" : "FAIL");
        if (str2)
            free(str2);
        return;
    }
    printf("%s\n", !strcmp(str1, str2) ? "OK" : "FAIL");
    free(str1);
    free(str2);
}

void test_my_strdup()
{
    char *str;
    printf("test_my_strchr\n");

    printf("test1 ");
    str = "hello";
    tmp_test_for_test_my_strdup(str);

    printf("test2 ");
    str = "";
    tmp_test_for_test_my_strdup(str);

    printf("test3 ");
    str = NULL;
    tmp_test_for_test_my_strdup(str);

    printf("test4 ");
    str = "asdf\0asdd";
    tmp_test_for_test_my_strdup(str);

    printf("\n\n");

}

void test_replace_str()
{
    printf("\ntest_replace \n ");

    char *str, *substr, *repstr, *res, *r;
    int i;

    printf("test1 ");
    str =    "sdasdasd";
    substr = "asd";
    repstr = "dsa";
    i = 2;
    res = "sddsaasd";
    r = replace_str(str, i, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);

    printf("test2 ");
    str =    "aaaaaa";
    substr = "aaaa";
    repstr = "a";
    i = 2;
    res = "aaa";
    r = replace_str(str, i, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);

    printf("test3 ");
    str =    "aaaaaa";
    substr = "aaaa";
    repstr = "";
    i = 2;
    res = "aa";
    r = replace_str(str, i, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);

    printf("test4 ");
    str =    "aaaaaa";
    substr = "aaaaaa";
    repstr = "bds";
    i = 0;
    res = "bds";
    r = replace_str(str, i, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);
}

void test_replace_all_str()
{
    printf("\ntest_replace_all \n ");

    char *str, *substr, *repstr, *res, *r;

    printf("test1 ");
    str = "sdasdasd";
    substr = "asd";
    repstr = "dsa";
    res = "sddsadsa";
    r = replace_all(str, substr, repstr);
//    printf("%s   %s\n", r, !strcmp(res, r) ? "OK" : "FAIL");
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);

    printf("test2 ");
    str =    "aaaaaaa";
    substr = "aaaa";
    repstr = "a";
    res =    "aaaa";
    r = replace_all(str, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
//    printf("%s   %s\n", r, !strcmp(res, r) ? "OK" : "FAIL");
    free(r);

    printf("test3 ");
    str =    "aaaaaa";
    substr = "aaaa";
    repstr = "";
    res =    "aa";
    r = replace_all(str, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);

    printf("test4 ");
    str =    "aaaaaa";
    substr = "aaaaaa";
    repstr = "bds";
    res =    "bds";
    r = replace_all(str, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);

    printf("test5 ");
    str = "aaaaaa";
    substr = "aa";
    repstr = "bbb";
    res = "bbbbbbbbb";
    r = replace_all(str, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);


    printf("test6 ");
    str = "abcabcabc";
    substr = "bc";
    repstr = "";
    res = "aaa";
    r = replace_all(str, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);

    printf("test7 ");
    str = "aaaaaa";
    substr = "aa";
    repstr = "aaaa";
    res = "aaaaaaaaaaaa";
    r = replace_all(str, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);

    printf("test8 ");
    str = "aaaaaa";
    substr = "bb";
    repstr = "cc";
    res = "aaaaaa";
    r = replace_all(str, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);


    printf("test9 ");
    str = "";
    substr = "bb";
    repstr = "cc";
    res = "";
    r = replace_all(str, substr, repstr);
    printf("%s\n", !strcmp(res, r) ? "OK" : "FAIL");
    free(r);

}

int for_test_search_str(const char *str, const char *substr)
{
    char *elem = strstr(str, substr);
    int i = -1;
    if(elem)
        i = elem - str;
    int j = search_str(str, substr);
    return i == j;
}
void test_search_str()
{
    printf("\ntest_search_str \n ");

    char *str, *substr;

    printf("test1 ");
    str = "asdasd";
    substr = "asd";
    printf("%s\n", for_test_search_str(str, substr) ? "OK" : "FAIL");

    printf("test2 ");
    str = "";
    substr = "asd";
    printf("%s\n", for_test_search_str(str, substr) ? "OK" : "FAIL");

    printf("test3 ");
    str = "qwerty";
    substr = "asd";
    printf("%s\n", for_test_search_str(str, substr) ? "OK" : "FAIL");

    printf("test4 ");
    str = "q";
    substr = "asd";
    printf("%s\n", for_test_search_str(str, substr) ? "OK" : "FAIL");

    printf("test5 ");
    str = "aaaaaa";
    substr = "aaa";
    printf("%s\n", for_test_search_str(str, substr) ? "OK" : "FAIL");

    printf("test6 ");
    str = "aaaaaa";
    substr = "";
    printf("%s\n", for_test_search_str(str, substr) ? "OK" : "FAIL");

}
//memcpy, memmove, realloc, replace_all, index -2;
int main()
{
    //test_my_strchr();
    //test_my_strdup();
    test_search_str();
    test_replace_str();
    test_replace_all_str();
/*        double **matr;
        void *p;
        int n = 5, m = 4;
        p = malloc(sizeof(double*)*n + sizeof(double)*n*m);
        matr = p;
        if(matr)
        {
            for(int i = 0; i < n; i++)
            {
                matr[i] = (*matr) + sizeof(double*) * n + i * sizeof(double) * m;
            }
        }
        double * a = matr[0];
        a[2] = 0;

        for(int i = 1; i <n; i++)
        {
            for(int j = 1; j < m; j++)
            {;
 //               matr[i][j] = 1;
            }
        }
        free(matr);*/
    return 0;
}
