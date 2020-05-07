#include "dll.h"
#include <stdlib.h>
#include <stdio.h>

void init_list(list_t *lst, unsigned int offset)
{

	lst->head = NULL;
	lst->offset = offset;
}

void remove_node(list_t *lst, node_t *node){
	if(!node->right){
		node->left->right = NULL;
		return;
	}
	if(!node->left && !node->right){
		lst->head = NULL;
		return;
	}
	if(!node->left && node->right){
		lst->head = node->right;
		return;
	}
	node->left->right = node->right;
	node->right->left = node->left;
	return;
}

void add_node(list_t *lst, node_t *node)
{
	node_t *head = lst->head;
	node->right = node->left = NULL;
	if(!head){
		lst->head = node;
		return;
	}
	while(head->right){
		head = head->right;
	}
	head->right = node;
	node->left = head;
	return;

}
