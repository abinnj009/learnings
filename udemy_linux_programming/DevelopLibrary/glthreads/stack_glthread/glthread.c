#include "glthread.h"
#include <stdlib.h>
#include <stdio.h>

static void _glthread_add_to_stack(glthread_t *lst, 
		glthread_node_t *node)
{
	node->right = lst->head;
	lst->head->left = node;
	lst->head = node;
}
void glthread_add(glthread_t *lst, glthread_node_t *node)
{
	node->left = NULL;
	node->right = NULL;
	if(!lst->head){
		lst->head = node;
		return;
	}
	_glthread_add_to_stack(lst, node);
}

static void _glthread_remove(glthread_t *lst)
{
	lst->head = lst->head->right;
	lst->head->left = NULL;
}
void glthread_remove(glthread_t *lst)
{
	if(!lst->head) return;
	_glthread_remove(lst);
}

void init_glthread(glthread_t *glthread, unsigned int offset)
{
	glthread->head = NULL;
	glthread->offset = offset;
}
