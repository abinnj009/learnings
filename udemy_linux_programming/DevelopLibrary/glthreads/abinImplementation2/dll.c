#include "dll.h"
#include <stdlib.h>
#include <stdio.h>

void init_list(list_t *lst, unsigned int offset)
{
	lst->head = NULL;
	lst->offset = offset;
}
static void _add_node(node_t *new_node, node_t *head)
{
	new_node->right = head;
	head->left = new_node;
	return;
}
 void add_node(list_t *lst, node_t *node)
{
	node->left = node->right = NULL;
	if(!lst->head){
		lst->head = node;
		return;
	}
	node_t *head = lst->head;
	_add_node(node, head);
	lst->head = node;
}

static void _remove_node(node_t *node)
{
	if(!node->left) {
		if(node->right){
			node->right->left = NULL;
			node->right = NULL;
			return;
		}
		return;
	}

	node->left->right = node->right;
	node->right->left = node->left;
	node->left = node->right = NULL;
}

void remove_node(list_t *lst, node_t *node)
{
	node_t *head = lst->head;
	if(head == node){
		lst->head = head->right;
	}

	_remove_node(node);
}
