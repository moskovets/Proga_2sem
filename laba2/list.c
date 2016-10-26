#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

node_t * create_node(node_value_t val)
{
	node_t *node = malloc(sizeof(node_t));

	if (node)
	{
		node -> value = val;
		node -> next = NULL;
	}
	return node;
}

node_t *insert_new_head(node_t *head, node_t *node)
{
	assert(node);
	node->next = head;
	return node; 	
}

node_t *insert_after(node_t *head, node_t *after, node_t *node)
{
	assert(node);
	if (after == NULL)
		head = insert_new_head(head, node);
	else 
	{
		node->next = after->next; 
		after->next = node;		
	}
	return head; 
}

void free_all(node_t *head)
{
    node_t *next;
    for ( ; head; head = next)
    {
        next = head->next;
        free(head);
    }
}
