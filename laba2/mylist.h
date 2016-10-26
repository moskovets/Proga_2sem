#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct node
{
    int value;
    struct node *next;
} list;

//typedef (list *)(list*, int, int) del_func;

list *create_node(int n);
list *add_to_list(list *tmp, list *head);
void free_all(list *head);
list *del_interval(list *head, int l, int r);
list *del_interval_while(list *head, int l, int r);
list* pop_part(list *head, int l, int r);
list *del_interval_while_optimus(list *head, int l, int r);
