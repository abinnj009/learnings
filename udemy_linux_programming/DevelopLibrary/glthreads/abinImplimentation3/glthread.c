#include "glthread.h"
#include <stdlib.h>
#include <stdio.h>

void init_glthread(glthread_t *glthread, unsigned int offset)
{
	glthread->head = NULL;
	glthread->offset = offset;
}

static void _glthread_add_next(glthread_node_t *new_node,
		glthread_node_t *curr_node)
{
	new_node->right = curr_node;
	curr_node->left = new_node;
	return;
}
void glthread_add_node(glthread_t *lst, glthread_node_t *glnode){
	glnode->left = glnode->right = NULL;
	if(!lst->head){
		lst->head = glnode;
		return;
	}
	glthread_node_t *head = lst->head;
	_glthread_add_next(glnode, head);
	lst->head = glnode;

}
void glthread_remove_node(glthread_t *lst, glthread_node_t *glnode)
{


}
