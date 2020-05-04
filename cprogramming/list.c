#include <stdio.h>
typedef struct listitem{
	struct listitem *next;
	struct listitem *prev;
	int data;
} item;

int main()
{
	item *temp, head;

	head.next = &head;
	head.prev = &head;
	head.data = -1;

	for(int i = 0; i < 3 ;i++){
		temp = malloc(sizeof(item));
		temp->data = i;
		temp->next = head.next;
		head.next = temp;
		temp->prev = &head;
		temp->next->prev = temp;
	}
}
