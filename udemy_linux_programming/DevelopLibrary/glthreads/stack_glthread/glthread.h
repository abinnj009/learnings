#ifndef __GLTHREADS__
#define __GLTHREADS__
typedef struct glthread_node_ {
	struct glthread_node_ *right;
	struct glthread_node_ *left;
} glthread_node_t;

typedef struct glthread_ {
	glthread_node_t *head;
	unsigned int offset;
}glthread_t;

void glthread_add(glthread_t *list, glthread_node_t *node);
void glthread_remove(glthread_t *list);
void init_glthread(glthread_t *glthread, unsigned int offset);

#define offsetof(struct_name, field_name) \
	((unsigned int)&((struct_name *)0)->field_name)
#endif

#define glthread_node_init(glnode) \
	glnode->left = NULL;\
	glnode->right = NULL;
#define ITERATE_GL_THREADS_BEGIN(lstptr, struct_type, ptr)\
{\
	glthread_node_t *_glnode = NULL, *_next = NULL;\
	for(_glnode = lstptr->head; _glnode; _glnode = _next) {\
		_next = _glnode->right;\
		ptr = (struct_type *)((char *)_glnode - lstptr->offset);
#define ITERATE_GL_THREADS_ENDS }}
