#include "dll.h"
#include <stdlib.h>
#include <stdio.h>


static void _glthread_add_next(glthread_node_t *new_node,
		glthread_node_t *curr_node)
{
	new_node->right = curr_node;
	curr_node->left = new_node;
	return;
}
void glthread_add_node(glthread_t *lst, glthread_node_t *glnode)
{
	glnode->left = glnode->right = NULL;
	if(!lst->head){
		lst->head = glnode;
		return;
	}	
	glthread_node_t *head = lst->head;
	_glthread_add_next(glnode, head);
	lst->head = glnode;
}

static void _remove_glthread(glthread_node_t * glnode)
{
	if(!glnode->left){
		if(glnode->right){
			glnode->right->left = NULL;
			glnode->right = NULL;
			return;
		}
		return;
	}
	if(!glnode->right){
		glnode->left->right = NULL;
		glnode->left = NULL;
		return;
	}

	glnode->left->right = glnode->right;
	glnode->right->left = glnode->left;
	glnode->left=glnode->right = NULL;
}

void glthread_remove_node(glthread_t *lst, glthread_node_t *glnode)
{
	glthread_node_t *head = lst->head;
	if(head == glnode)
		head = head->right;
	_remove_glthread(glnode);
}
void glthread_init(glthread_t *glthread, unsigned int offset)
{
	glthread->head = NULL;
	glthread->offset = offset;
}
