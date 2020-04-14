typedef struct dll_node_{
	void *data;
	struct dll_node_ *right;
	struct dll_node_ *left;
} dll_node_t;

typedef struct dll_{
	dll_node_t *head;
	int (*key_match)(void *, void *);
	int (*comparison)(void *, void *);
}dll_t;

void register_key_match_callback(dll_t *dll, int (*key_match)(void*, void*));
void register_comparison_callback(dll_t *dll, int(*comparison)(void*, void*));

dll_t * get_new_dll();

void * dll_search_by_key(dll_t *dll, void *key);
int add_data_to_dll(dll_t *dll, void *app_data);
int dll_priority_insert_data(dll_t *dll, void *data);
#define ITERATIVE_LIST_BEGIN(list_ptr, node_ptr) \
{\
	dll_node_t *_node_ptr = NULL;\
	node_ptr = list_ptr->head;\
	for(; node_ptr!=NULL;node_ptr = _node_ptr) {\
		if(!node_ptr)\
			break;\
		_node_ptr = node_ptr->right;
#define ITERATIVE_LIST_END }}

