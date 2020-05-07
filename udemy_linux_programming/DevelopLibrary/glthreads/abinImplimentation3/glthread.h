#ifndef __GLTHREADS__
#define __GLTHREADS__

typedef struct glthread_node_{
	struct glthread_node_ *left;
	struct glthread_node_ *right;
} glthread_node_t;

typedef struct glthread_{
	glthread_node_t *head;
	unsigned int offset;
} glthread_t;

void glthread_add_node(glthread_t *lst, glthread_node_t *glnode);
void glthread_remove_node(glthread_t *lst, glthread_node_t *glnode);
void init_glthread(glthread_t *glthread, unsigned int offset);

#define ITERATE_GLTHREAD_BEGIN(lst,struct_type,ptr){\
	glthread_node_t *_next = NULL, *_glnode = NULL; \
	for(_glnode = lst->head;_glnode;_glnode = _next){\
		_next = _glnode->right;\
		ptr = (struct_type *)((char *)_glnode - lst->offset);
#define ITERATE_GLTHREAD_END }}

#define offsetof(struct_name, field_name) \
	((unsigned int)& ((struct_name *)0)->field_name)
#define glthread_node_init(glnode)\
	glnode->left = NULL;\
	glnode->right = NULL;
#endif
