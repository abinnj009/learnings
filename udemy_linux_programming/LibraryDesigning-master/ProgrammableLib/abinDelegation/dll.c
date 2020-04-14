#include "dll.h"
#include <memory.h>
#include <stdlib.h>

dll_t * get_new_dll()
{
	dll_t *dll = calloc(1,sizeof(dll_t));
	dll->head = NULL;
	return dll;
}

void register_key_match_callback(dll_t *dll, 
		int (*key_match)(void *, void *))
{
	dll->key_match = key_match;
}
void register_comparison_callback(dll_t *dll,
		int (*comparison)(void *, void *))
{
	dll->comparison = comparison;
}
void * dll_search_by_key(dll_t *dll, void *key)
{
	if(!dll || !dll->head) return NULL;

	dll_node_t *head = dll->head;

	while(head) {
		if(dll->key_match(head->data, key) == 0){
			return (void *)head->data;
		}
		head = head->right;
	}
}

int dll_priority_insert_data (dll_t *dll, void *data)
{
	if(!dll)
		return -1;
	if(!dll->head){
		add_data_to_dll(dll, data);
		return 0;
	}

	dll_node_t *data_node = calloc(1, sizeof(dll_node_t));
	data_node->data = data;
	data_node->right = NULL;
	data_node->left = NULL;

	if(dll->head && !dll->head->right){
		if(dll->comparison(dll->head->data, data) == -1){
			dll->head->right = data_node;
			data_node->left = dll->head;
		}
		else {
			dll->head->left = data_node;
			data_node->right = dll->head;
			dll->head = data_node;
		}
		return 0;
	}

	if(dll->comparison(data, dll->head->data) == -1) {
		data_node->right = dll->head;
		dll->head->left = data_node;
		dll->head = data_node;
		return 0;
	}

	dll_node_t *prev = NULL, *curr = NULL;
	curr = dll->head;

	while(curr){
		if(dll->comparison(data, curr->data) != -1){
			prev = curr;
			curr = curr->right;
			continue;
		}
		prev->right = data_node;
		data_node->left = prev;
		data_node->right = curr;
		curr->left = data_node;
		return 0;
	}

	prev->right = data_node;
	data_node->left = prev;
	return 0;
}


int add_data_to_dll(dll_t *dll, void *app_data) 
{
	if(!dll || !app_data) return -1;

	dll_node_t *new_node = calloc(1,sizeof(dll_node_t));
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->data = app_data;

	if(!dll->head){
		dll->head = new_node;
		return 0;
	}

	dll_node_t *first_node = dll->head;
	new_node->right = first_node;
	first_node->left = new_node;
	dll->head = new_node;
	return 0;
}
