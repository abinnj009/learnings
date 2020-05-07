#include<stdio.h>
#include<stdlib.h>

typedef struct node_{
	int data;
	struct node_ *next;
} node_t;

node_t *p, *head = NULL;
node_t *t;
void insert(int x)
{
	t = (node_t *) malloc(sizeof(node_t));	
	t->data = x;
	t->next = NULL;
	
	if(head == NULL){
          	head = t;
          	return;
	}
	p = head;
	if(p->data > x){
			t->next = p;
			head = t;
			return;
		}
	
	while(p){
		if((p->next) && (p->next->data < x)){
			p = p->next;
			continue;
		}
		t->next = p->next;
		p->next = t;
		return;
	}
	
}
void show()
{
	t = head;
	while(t){
		printf("%d->\t", t->data);
		t = t-> next;
	}
}
int main()
{
	insert(5);
		insert(9);
			insert(11);
				insert(19);
					insert(10);
	show();
	
}
