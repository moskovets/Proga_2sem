#include "mylist.h"

/*
    функци€ создани€ новой структуры
    возвращает NULL при неуспешном выделении пам€ти
*/
list *create_node(void *val)
{
    list *a = malloc(sizeof(list));
    if (a)
    {
        a->value = val;
        a->next = NULL;
    }
    return a;
}
/*
    добавление единицы структуры в упор€дочнный по убыванию список
*/

list *add_to_begin_of_list(list *tmp, list *head)
{
    if (!head)
    {
        head = tmp;
        return head;
    }
    tmp->next = head;
    return tmp;
 }
/*
    освобождение пам€ти дл€ всего списка
*/
void free_all(list *head)
{
    list *next;
    for (; head; head = next)
    {
        next = head->next;
        free(head);
    }
}
/*
    удаление элементов списка из указанного интервала [l,r]
*/

list *del_interval(list *head, int l, int r)
{
/*    assert(r >= l);
    if (head)
    {
        if (head->value >= l && head->value <= r)
        {
            list *next = head->next;
            free(head);
            return del_interval(next, l, r);
        }
        head->next = del_interval(head->next, l, r);
    }*/
    return head;
}

// возвращает указатель на данные из элемента, который расположен в "голове" списка. ѕри этом из списка сам элемент удал€етс€.
void *pop_front(list **head)
{
    if(!(*head))
        return NULL;
    void *data = (*head)->value;
    list *tmp = (*head)->next;
    free(*head);
    *head = tmp;
    return data;
}

//вставл€ет элемент перед указанным элементом списка (в качетсве параметров указываютс€ адреса обоих элементов)
// return 1 if not found before
int insert(list** head, list *before, list *tmp)
{
    assert(before && *head);
    list *it = *head;
    if(before == *head)
    {
        tmp->next = before;
        *head = tmp;
        return 0;
    }
    while(it)
    {
        if(it->next == before)
        {
            it->next = tmp;
            tmp->next = before;
            return 0;
        }
    }
    return 1;
}

list *reverse_rekur(list *tmp, list **head)
{
    if(!tmp->next)
    {
        *head = tmp;
        return tmp;
    }
    list *t = reverse_rekur(tmp->next, head);
    t->next = tmp;
    return tmp;
}
void reverse(list **head)
{
    if(*head)
    {
        list *old_head = *head;
        reverse_rekur(*head, head);
        old_head->next = NULL;
    }
}
void front_back_split(list *head, list **mid)
{
    list *tmp = head;
    int n = 0;
    while(tmp)
    {
        tmp = tmp->next;
        n++;
    }
    int m = (n + 1) / 2;
    tmp = head;
    for(int i = 0; i < m - 1; i++)
    {
        tmp = tmp->next;
    }
    *mid = tmp->next;
    tmp->next = NULL;
}
list *sorted_merge(list *a, list *b, int (*comparator)(const void *, const void *))
{
    list *head = NULL;
    if(a && b)
    {
        if(comparator(a->value, b->value) >= 0)
        {
            head = a;
            a = a->next;
        }
        else
        {
            head = b;
            b = b->next;
        }
    }
    else
        head = a ? a : b;
    list *tmp = head;
    while(a || b)
    {
        if(a && (!b || comparator(a->value, b->value) >= 0))
        {
            tmp->next = a;
            a = a->next;
            tmp = tmp->next;
        }
        else
        {
            tmp->next = b;
            b = b->next;
            tmp = tmp->next;
        }
    }
    tmp->next = NULL;
    return head;
}
void merge_sort(list **head, int (*comparator)(const void *, const void *))
{
    if(head)
    {
        list *mid = NULL;
        front_back_split(*head, &mid);
        if(!mid)
            return;
        merge_sort(head, comparator);
        merge_sort(&mid, comparator);
        *head = sorted_merge(*head, mid, comparator);
    }
}
