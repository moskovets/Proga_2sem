#include "write.h"
/* return 0; if ok
*/
int from_file_to_database(FILE *f, Data **arr, const int n)
{
    assert(f);
    for(int i = 0; i < n; i++)
    {
        if(scan_struct_from_file(f, arr[i]))
            return 1;
    }
    return 0;
}

/*
    функция создает список из чисел, записанных в файле
    возвращает NULL, если не удалось выделить память
*/
list *from_database_to_list(const Data *arr, const int n)
{

    list *head = NULL;
    for(int i = n - 1; i >= 0; i--)
    {
        list *tmp = create_node((void *) &arr[i]);
        if (tmp == NULL)
        {
            free_all(head);
            break;
        }
        head = add_to_begin_of_list(tmp, head);
    }
    return head;
}

/*
    функция записи списка в файл
*/
void write_from_list_to_file(FILE *f, const list *head)
{
    assert(f);
    if(!head)
    {
        fprintf(f, "list is empty");
        return;
    }
    const list *tmp = head;
    while (tmp)
    {
        print_struct_to_file(f, tmp->value);
        tmp = tmp->next;
    }
    return;
}
