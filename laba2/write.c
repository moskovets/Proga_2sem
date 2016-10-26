#include "write.h"
/*
    функция создает список из чисел, записанных в файле
    возвращает NULL, если файл пуст, или не удалось выделить память
*/
list *from_file_to_list(FILE *f)
{
    assert(f);

    list *head = NULL;
    int x;

    while (fscanf(f, "%d", &x) == 1)
    {
        list *tmp = create_node(x);
        if (tmp == NULL)
        {
            free_all(head);
            break;
        }
        head = add_to_list(tmp, head);
    }
    return head;
}
/*
    функция записи списка в файл
*/
void write_from_list_to_file(FILE *f, const list *head)
{
    assert(f);
    /*if(!head)
    {
        fprintf(f, "list is empty");
        return;
    }*/

    const list *tmp = head;
    while (tmp)
    {
        fprintf(f, "%d ", tmp->value);
        tmp = tmp->next;
    }
    return;
}
