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
// ���������� ��������� �� ������ �� ��������, ������� ���������� � "������" ������. ��� ���� �� ������ ��� ������� ���������.
void *pop_front(list **head);
//��������� ������� ����� ��������� ��������� ������ (� �������� ���������� ����������� ������ ����� ���������)
int insert(list** head, list *before, list *tmp);

void reverse(list **head);
// �������� ������ � ����� ��� �� ��� ��������. ���� � ������ �������� ����� ���������, "����������" ������� ������ ������� � ������ ��������.
void front_back_split(list *head, list **mid);
// �������� ��� ������������� ������ � ���������� �� � ����.
list *sorted_merge(list *a, list *b, int (*comparator)(const void *, const void *));
void merge_sort(list **head, int (*comparator)(const void *, const void *));
#endif // MYLIST_H_INCLUDED
