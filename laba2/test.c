#include "write.h"

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

int equal_list(const int a[], list* head, int na)
{
    list *tmp = head;
    for(int i = 0; i < na; i++)
    {
        if(!tmp || a[i] != tmp->value)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}
list *create_list(const int a[], int na)
{
    list *head = create_node(a[0]);
    list *tmp = head;
    for(int i = 1; i < na; ++i)
    {
        tmp->next = create_node(a[i]);
        tmp = tmp->next;
    }
    return head;
}
/*
void t1est_add_to_list()
{
    printf("test_add_to_list\n");

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
    int a2[] = { 1 };
    int arr2[] = { 1, 2 };
    n = 2;
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
*/

void test_add_to_list()
{
    int n;
    list* head = NULL;
    printf("test_add_to_list\n");

    printf("test1 ");
    int arr1[] = { 1 };
    n = 1;
    head = add_to_list(create_node(1), head);
    printf("%s\n", equal_list(arr1, head, n) ? "OK" : "FAIL");
    free_all(head);

    printf("test2 ");
    int a2[] = { 1 };
    int arr2[] = { 2, 1 };
    n = 2;
    head = create_list(a2, n - 1);
    head = add_to_list(create_node(2), head);
    printf("%s\n", equal_list(arr2, head, n) ? "OK" : "FAIL");
    free_all(head);

    printf("test3 ");
    int a3[] = { 2, 1 };
    int arr3[] = { 2, 1, 0 };
    n = 3;
    head = create_list(a3, n - 1);
    head = add_to_list(create_node(0), head);
    printf("%s\n", equal_list(arr3, head, n) ? "OK" : "FAIL");
    free_all(head);

    printf("test4 ");
    int a4[] = { 3, 1 };
    int arr4[] = { 3, 2, 1 };
    n = 3;
    head = create_list(a4, n - 1);
    head = add_to_list(create_node(2), head);
    printf("%s\n", equal_list(arr4, head, n) ? "OK" : "FAIL");
    free_all(head);

    printf("test5 ");
    int a5[] = { 3, 2, 1 };
    int arr5[] = { 3, 2, 2, 1 };
    n = 4;
    head = create_list(a5, n - 1);
    head = add_to_list(create_node(2), head);
    printf("%s\n", equal_list(arr5, head, n) ? "OK" : "FAIL");
    free_all(head);

    printf("test6 ");
    int a6[] = { -2, -2, -2 };
    int arr6[] = { -2, -2, -2, -2 };
    n = 4;
    head = create_list(a6, n - 1);
    add_to_list(create_node(-2), head);
    printf("%s\n", equal_list(arr6, head, n) ? "OK" : "FAIL");
    free_all(head);

    printf("\n\n");
}
void test_del_interval(list * (*del_func) (list*, int, int))
{
    int na, ndel, l, r;
    list* head = NULL;

    printf("test1 ");
    int a1[] = { 1 };
    na = 1;
    ndel = 0;
    l = 1;
    r = 1;
    head = create_list(a1, na);
    head = del_interval(head, l, r);
    printf("%s\n", head == NULL ? "OK" : "FAIL");
    free_all(head);

    printf("test2 ");
    int a2[] = { 7, 6, 5, 4, 3, 2, 1 };
    int arr2[] = { 7, 2, 1 };
    na = 7;
    ndel = 3;
    l = 3;
    r = 6;
    head = create_list(a2, na);
    head = del_interval(head, l, r);
    printf("%s\n", equal_list(arr2, head, ndel) ? "OK" : "FAIL");
    free_all(head);

    printf("test3 ");
    int a3[] = { 7, 2, 1 };
    int arr3[] = { 7, 2, 1 };
    na = 3;
    ndel = 3;
    l = 3;
    r = 6;
    head = create_list(a3, na);
    head = del_interval(head, l, r);
    printf("%s\n", equal_list(arr3, head, ndel) ? "OK" : "FAIL");
    free_all(head);

    printf("test4 ");
    int a4[] = { 7, 7, 6, 2, 2, 1 };
    int arr4[] = { 2, 2, 1 };
    na = 6;
    ndel = 3;
    l = 4;
    r = 20;
    head = create_list(a4, na);
    head = del_interval(head, l, r);
    printf("%s\n", equal_list(arr4, head, ndel) ? "OK" : "FAIL");
    free_all(head);

    printf("test5 ");
    int a5[] = { 7, 7, 6, 2, 2, 1 };
    int arr5[] = { 7, 7 };
    na = 6;
    ndel = 2;
    l = -20;
    r = 2;
    head = create_list(a5, na);
    head = del_interval(head, l, r);
    printf("%s\n", equal_list(arr5, head, ndel) ? "OK" : "FAIL");
    free_all(head);

    printf("\n\n");
}

unsigned long long test_time(list * (*del_func) (list*, int, int), int iter, int l, int r)
{
    unsigned long long tb, te;

    list* head = NULL;
    for(int i = iter; i >= 0; --i) {
        head = add_to_list(create_node(i), head);
    }
    tb = tick();
    head = del_func(head, l, r);
    te = tick();
    free_all(head);
    return te - tb;
}

int main()
{
    test_add_to_list();
    printf("test_del_interval\n");
    test_del_interval(del_interval);
    printf("test_del_interval_while\n");
    test_del_interval(del_interval_while);
    printf("test_del_interval_Sokolov\n");
    test_del_interval(pop_part);
    printf("test_del_interval_while_optimus\n");
    test_del_interval(del_interval_while_optimus);
    int t;
    t = test_time(del_interval, 1000, 20, 700);
    printf("Recurs         %d\n", t);
    t = test_time(del_interval_while, 1000, 20, 700);
    printf("While          %d\n", t);
    t = test_time(pop_part, 1000, 20, 700);
    printf("Sokolov_while  %d\n", t);
    t = test_time(del_interval_while_optimus, 1000, 20, 700);
    printf("optimus_while  %d\n", t);
    return 0;
}
