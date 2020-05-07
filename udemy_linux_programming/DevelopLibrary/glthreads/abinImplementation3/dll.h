#ifndef __DLL__
#define __DLL__
typedef struct node_{
	struct node_ *right;
	struct node_ *left;
}node_t;

typedef struct list_{
	node_t *head;
	unsigned int offset;
}list_t;

void add_node(list_t *lst, node_t *node);
void remove_node(list_t *lst, node_t *node);
void init_list(list_t *lst, unsigned int offest);

#define ITERATE_LIST_BEGIN(lstptr,struct_type,ptr){\
	node_t *_next=NULL, *_node = NULL;\
	for(_node = lstptr->head; _node; _node = _next){\
	      _next = _node->right;\
		ptr = (struct_type *)((char *)_node-lstptr->offset);
#define ITERATE_LIST_END }}

#define add_node_sorted(lst,new_node,type){\
	node_t *q, *head = lst->head;	\
	new_node.right = NULL;\
	new_node.left = NULL;\
	if(!head){			\
		lst->head = &new_node;	\
	}\
	else{	\
			type *node_ptr = (type *)	\
			((char *)(&new_node) - lst->offset);     \
			type *head_ptr = (type *)	\
			((char *)head - lst->offset);	\
			while(head && (head_ptr->emp_id < node_ptr->emp_id) && head->right){	\
				q = head;		\
				head = head->right;	\
			}\
		if(head == lst->head){\
			if(!head->right){\
				lst->head->right = &new_node;\
				new_node.left = lst->head;\
			}\
			else{\
				new_node.right = lst->head;\
				lst->head->left = &new_node;\
				lst->head = &new_node;\
			}\
		}				\
		else {\
			q->right = &new_node;\
				new_node.left = q;\
				new_node.right = head;\
				head->left = &new_node;\
		}\
	}
#define end_add_node_sorted }


#define node_init(node)\
	node->left = node->right = NULL;

#define offsetof(struct_type, member)\
	((unsigned int)&((struct_type *)0)->member)
#endif
