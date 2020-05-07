#include "dll.h"
#include <stdlib.h>
#include <stdio.h>

void init_list(list_t *lst, unsigned int offset)
{
	lst->head = NULL;
	lst->tail = NULL;
	lst->offset = offset;
}

static void _add_node(node_t *new_node, node_t *tail)
{
	tail->next = new_node;;
	return;
}
void add_node(list_t *lst, node_t *node)
{
	node->next = NULL;
	if(!lst->head){
		lst->head = lst->tail = node;
		return;
	}
	node_t *tail = lst->tail;
	_add_node(node, tail);
	lst->tail = node;
}
void remove_node(list_t *lst, node_t *node)
{
}
