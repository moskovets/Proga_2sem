#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct node
{
    void *value;
    struct node *next;
} list;

//typedef (list *)(list*, int, int) del_func;

list *create_node(void *val);
list *add_to_begin_of_list(list *tmp, list *head);
void free_all(list *head);
// возвращает указатель на данные из элемента, который расположен в "голове" списка. ѕри этом из списка сам элемент удал€етс€.
void *pop_front(list **head);
//вставл€ет элемент перед указанным элементом списка (в качетсве параметров указываютс€ адреса обоих элементов)
int insert(list** head, list *before, list *tmp);

void reverse(list **head);
// получает список и делит его на две половины. ≈сли в списке нечетное число элементов, "серединный" элемент должен попасть в первую половину.
void front_back_split(list *head, list **mid);
// получает два упор€доченных списка и объедин€ет их в один.
list *sorted_merge(list *a, list *b, int (*comparator)(const void *, const void *));
void merge_sort(list **head, int (*comparator)(const void *, const void *));
#endif // MYLIST_H_INCLUDED
