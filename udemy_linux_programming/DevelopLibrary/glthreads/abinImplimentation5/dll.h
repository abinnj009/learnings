#ifndef __DLL__
#define __DLL__

typedef struct node_{
	struct node_ *left;
	struct node_ *right;
}node_t;

typedef struct list_{
	node_t *head;
	unsigned int offset;
}list_t;

void add_node(list_t *lst, node_t *node);
void remove_node(list_t *lst, node_t *node);
void init_list(list_t *lst, unsigned int offset);

#define ITERATE_LIST_BEGIN(lstptr, struct_type, ptr){\
	node_t *_node = NULL, *_next = NULL;\
	for(_node = lstptr->head;_node;_node = _next){\
		_next = _node->right;\
		ptr = (struct_type *)((char *) _node - lstptr->offset);
#define ITERATE_LIST_END }}

#define node_init(node)\
	node->left = NULL;\
	node->right = NULL;
#define offsetof(struct_type, member)\
	((unsigned int)&((struct_type *)0)->member)

#endif
