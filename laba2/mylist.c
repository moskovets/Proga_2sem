#include "mylist.h"

/*
    функция создания новой структуры
    возвращает NULL при неуспешном выделении памяти
*/
list *create_node(int n)
{
    list *a = malloc(sizeof(list));
    if (a)
    {
        a->value = n;
        a->next = NULL;
    }
    return a;
}
/*
    добавление единицы структуры в упорядочнный по убыванию список
*/

list *add_to_list(list *tmp, list *head)
{
    if (!head)
    {
        head = tmp;
        return head;
    }
    if (tmp->value > head->value)
    {
        tmp->next = head;
        return tmp;
    }
    else
    {
        head->next = add_to_list(tmp, head->next);
    }
    return head;
}
/*
    освобождение памяти для всего списка
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
    assert(r >= l);
    if (head)
    {
        if (head->value >= l && head->value <= r)
        {
            list *next = head->next;
            free(head);
            return del_interval(next, l, r);
        }
        head->next = del_interval(head->next, l, r);
    }
    return head;
}

list *del_interval_while(list *head, int l, int r)
{
    assert(r >= l);
    list *start = head;
    list *tmp = head;
    while (tmp && tmp->value > r)
    {
        start = tmp;
        tmp = tmp->next;
    }
    while (tmp && tmp->value >= l){
        list *fr = tmp;
        tmp = tmp->next;
        free(fr);
        if (fr == start)
            start = NULL;
        if (fr == head)
            head = NULL;
    }
    if (start)
        start->next = tmp;
    else
        start = tmp;
    if(!head)
        head = start;
    return head;
}
list *del_interval_while_optimus(list *head, int l, int r)
{
    assert(r >= l);
    list *start = head;
    list *tmp = head;
    while (tmp && tmp->value > r)
    {
        start = tmp;
        tmp = tmp->next;
    }
    list*fr;
    if (tmp && tmp->value >= l){
        fr = tmp;
        tmp = tmp->next;
        free(fr);
        if (fr == start)
            start = NULL;
        if (fr == head)
            head = NULL;
    }
    while (tmp && tmp->value >= l){
        fr = tmp;
        tmp = tmp->next;
        free(fr);
    }
    if (start)
        start->next = tmp;
    else
        start = tmp;
    if(!head)
        head = start;
    return head;
}

list* pop_part(list *head, int l, int r)
{
	// Удаляем элементы списка снчала, пока не дойдем до первого,
	// Не входящего в интервал
    assert(r >= l);
	list *out = create_node(0);
	list *outfirst = out;
	while (head->value <= r && head->value >= l && head->next != NULL)
	{
		out->next = head;
		out = head;
		head = head->next;
	}
	list *cur = head->next;
	list *prev = head;
	// "Строим" по ссылкам список заново, пропуская ненужные элементы
	for ( ; cur; cur = cur->next)
	{
		if (!(cur->value <= r && cur->value >= l))
		{
			prev->next = cur;
			prev = cur;
			out->next = NULL;
		}
		else
		{
			out->next = cur;
			out = out->next;
		}
	}
	free_all(outfirst);
	return head;
}
