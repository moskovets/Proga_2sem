#include "write.h"

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

int equal_list(const int a[], list* head, int na, Data *arr)
{
    list *tmp = head;
    for(int i = 0; i < na; i++)
    {
        if(!tmp || (&arr[a[i]]) != tmp->value)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}
list *goto_list(list *head, int n)
{
    list *tmp = head;
    int i;
    for(i = 0; tmp && i < n; i++)
    {
        tmp = tmp->next;
    }
    assert(i == n);
    return tmp;
}
list *create_list(const int a[], int na, Data *arr)
{
    list *head = create_node((void *)&arr[a[0]]);
    list *tmp = head;
    for(int i = 1; i < na; ++i)
    {
        tmp->next = create_node((void *)&arr[a[i]]);
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

void test_pop_front(Data *arr)
{
    list* head = NULL;
    void *ret = NULL;
    printf("test_pop_front\n");

    printf("test1 ");
    ret = pop_front(&head);
    printf("%s\n", !head && !ret ? "OK" : "FAIL");

    printf("test2 ");
    int a2[] = { 2, 1 };
    int arr2[] = { 1 };
    head = create_list(a2, sizeof(a2) / sizeof(a2[0]), arr);
    pop_front(&head);
    //print_struct(head->value);
    //if(head->next)
    //    print_struct(head->next->value);
    printf("%s\n", equal_list(arr2, head, sizeof(arr2) / sizeof(arr2[0]), arr) ? "OK" : "FAIL");
    free_all(head);

    printf("test3 ");
    int a3[] = { 1 };
    head = create_list(a3, sizeof(a3) / sizeof(a3[0]), arr);
    pop_front(&head);
    printf("%s\n", !head ? "OK" : "FAIL");
    free_all(head);

    printf("test4 ");
    int a4[] = { 0, 2, 1 };
    int arr4[] = { 2, 1 };
    head = create_list(a4, sizeof(a4) / sizeof(a4[0]), arr);
    pop_front(&head);
    printf("%s\n", equal_list(arr4, head, sizeof(arr4) / sizeof(arr4[0]), arr) ? "OK" : "FAIL");
    free_all(head);

    printf("\n\n");
}

void test_insert(Data *arr)
{
    list* head = NULL;
    int ret = 0;
    printf("test_insert\n");
    list *tmp, *before;

    printf("test1 ");
    int a1[] = { 2 };
    int arr1[] = { 1, 2 };
    head = create_list(a1, sizeof(a1) / sizeof(a1[0]), arr);
    tmp = create_node((void *) &arr[1]);
    before = goto_list(head, 0);
    //printf("ok\n");
    insert(&head, before, tmp);
    //print_struct(head->value);
    //if(head->next)
    //    print_struct(head->next->value);
    printf("%s\n", equal_list(arr1, head, sizeof(arr1) / sizeof(arr1[0]), arr) && !ret ? "OK" : "FAIL");
    free_all(head);

    printf("test2 ");
    int a2[] = { 2, 3 };
    int arr2[] = { 2, 1, 3 };
    head = create_list(a2, sizeof(a2) / sizeof(a2[0]), arr);
    tmp = create_node((void *) &arr[1]);
    before = goto_list(head, 1);
    insert(&head, before, tmp);
    printf("%s\n", equal_list(arr2, head, sizeof(arr2) / sizeof(arr2[0]), arr) && !ret ? "OK" : "FAIL");
    free_all(head);

    printf("test3 ");
    int a3[] = { 2, 3 };
    int arr3[] = { 1, 2, 3 };
    head = create_list(a3, sizeof(a3) / sizeof(a3[0]), arr);
    tmp = create_node((void *) &arr[1]);
    before = goto_list(head, 0);
    insert(&head, before, tmp);
    printf("%s\n", equal_list(arr3, head, sizeof(arr3) / sizeof(arr3[0]), arr) && !ret ? "OK" : "FAIL");
    free_all(head);

    printf("\n\n");
}

void test_reverse(Data *arr)
{
    list* head = NULL;
    printf("test_reverse\n");

    printf("test1 ");
    int a1[] = { 2 };
    int arr1[] = { 2 };
    head = create_list(a1, sizeof(a1) / sizeof(a1[0]), arr);
    reverse(&head);
    //print_struct(head->value);
    //if(head->next)
    //    print_struct(head->next->value);
    printf("%s\n", equal_list(arr1, head, sizeof(arr1) / sizeof(arr1[0]), arr) ? "OK" : "FAIL");
    free_all(head);

    printf("test2 ");
    int a2[] = { 2, 3 };
    int arr2[] = { 3, 2 };
    head = create_list(a2, sizeof(a2) / sizeof(a2[0]), arr);
    reverse(&head);
    printf("%s\n", equal_list(arr2, head, sizeof(arr2) / sizeof(arr2[0]), arr) ? "OK" : "FAIL");
    free_all(head);

    printf("test3 ");
    int a3[] = { 1, 2, 3 };
    int arr3[] = { 3, 2, 1 };
    head = create_list(a3, sizeof(a3) / sizeof(a3[0]), arr);
    reverse(&head);
    printf("%s\n", equal_list(arr3, head, sizeof(arr3) / sizeof(arr3[0]), arr) ? "OK" : "FAIL");
    free_all(head);

    printf("\n\n");
}

void test_merge_sort(Data *arr)
{
    list* head = NULL;
    printf("test_merge_sort\n");

    printf("test1 ");
    int a1[] = { 2 };
    int arr1[] = { 2 };
    head = create_list(a1, sizeof(a1) / sizeof(a1[0]), arr);
    merge_sort(&head, &funccmp_Data);
    //print_struct(head->value);
    //if(head->next)
    //    print_struct(head->next->value);
    printf("%s\n", equal_list(arr1, head, sizeof(arr1) / sizeof(arr1[0]), arr) ? "OK" : "FAIL");
    free_all(head);

    printf("test2 ");
    int a2[] = { 2, 3 };
    int arr2[] = { 2, 3 };
    head = create_list(a2, sizeof(a2) / sizeof(a2[0]), arr);
    merge_sort(&head, &funccmp_Data);
    //print_struct(head->value);
    //if(head->next)
    //    print_struct(head->next->value);
    printf("%s\n", equal_list(arr2, head, sizeof(arr2) / sizeof(arr2[0]), arr) ? "OK" : "FAIL");
    free_all(head);

    printf("test3 ");
    int a3[] = { 3, 2 };
    int arr3[] = { 2, 3 };
    head = create_list(a3, sizeof(a3) / sizeof(a3[0]), arr);
    merge_sort(&head, &funccmp_Data);
    printf("%s\n", equal_list(arr3, head, sizeof(arr3) / sizeof(arr3[0]), arr) ? "OK" : "FAIL");
    free_all(head);

    printf("test4 ");
    int a4[] = { 1, 2, 3, 4, 5 };
    int arr4[] = { 1, 2, 3, 4, 5 };
    head = create_list(a4, sizeof(a4) / sizeof(a4[0]), arr);
    merge_sort(&head, &funccmp_Data);
    printf("%s\n", equal_list(arr4, head, sizeof(arr4) / sizeof(arr4[0]), arr) ? "OK" : "FAIL");
    free_all(head);

    printf("test5 ");
    int a5[] = { 5, 4, 3, 2, 1 };
    int arr5[] = { 1, 2, 3, 4, 5 };
    head = create_list(a5, sizeof(a5) / sizeof(a5[0]), arr);
    merge_sort(&head, &funccmp_Data);
    printf("%s\n", equal_list(arr5, head, sizeof(arr5) / sizeof(arr5[0]), arr) ? "OK" : "FAIL");
    free_all(head);

    printf("test6 ");
    int a6[] = { 5, 4, 2, 2, 5 };
    int arr6[] = { 2, 2, 4, 5, 5 };
    head = create_list(a6, sizeof(a6) / sizeof(a6[0]), arr);
    merge_sort(&head, &funccmp_Data);
    printf("%s\n", equal_list(arr6, head, sizeof(arr6) / sizeof(arr6[0]), arr) ? "OK" : "FAIL");
    free_all(head);

    printf("\n\n");
}
/*void test_del_interval(list * (*del_func) (list*, int, int))
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
    unsigned long long t = 0;
    for(int j = 0; j < 5; j++)
    {
        unsigned long long tb, te;

        list* head = NULL;
        for(int i = iter; i >= 0; --i)
        {
            head = add_to_list(create_node(i), head);
        }
        tb = tick();
        head = del_func(head, l, r);
        te = tick();
        free_all(head);
        t += te - tb;
    }
    return t / 5;
}
*/
int main()
{
    Data arr[100];
    for(int i = 0; i < 30; i++)
    {
        arr[i].country_name[0] = 'a' + i;
        arr[i].country_name[1] = '\0';
        arr[i].town_name[0] = 'A' + i;
        arr[i].town_name[1] = '\0';
        arr[i].population = i;
    }
    test_pop_front(arr);
    test_insert(arr);
    test_reverse(arr);
    test_merge_sort(arr);

/*    test_add_to_list();
    printf("test_del_interval\n");
    test_del_interval(del_interval);
    printf("test_del_interval_while\n");
    test_del_interval(del_interval_while);
    printf("test_del_interval_Sokolov\n");
    test_del_interval(pop_part);
    printf("test_del_interval_while_optimus\n");
    test_del_interval(del_interval_while_optimus);
    printf("test_del_interval_Sokolov\n");
    test_del_interval(pop_part2);
    int t;
    t = test_time(del_interval, 1000, 20, 700);
    printf("Recurs         %d\n", t);
    t = test_time(del_interval_while, 1000, 20, 700);
    printf("While          %d\n", t);
    t = test_time(pop_part, 1000, 20, 700);
    printf("Sokolov_while  %d\n", t);
    t = test_time(del_interval_while_optimus, 1000, 20, 700);
    printf("optimus_while  %d\n", t);
    t = test_time(pop_part2, 1000, 20, 700);
    printf("pop_part2  %d\n", t);

    FILE * out;
    out = fopen("res.txt", "w");
    for (int i = 100; i < 2000; i += 100)
    {
        int t1 = test_time(del_interval, i, 20, i - 20);
        int t2 = test_time(del_interval_while, i, 20, i - 20);
        int t3 = test_time(pop_part, i, 20, i - 20);
        int t4 = test_time(del_interval_while_optimus, i, 20, i - 20);
        int t5 = test_time(pop_part2, i, 20, i - 20);
        fprintf(out, "%10d %10d %10d %10d %10d %10d\n", i, t1, t2, t3, t4, t5);
    }
*/
    return 0;
}
