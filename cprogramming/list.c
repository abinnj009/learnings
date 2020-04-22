#include <stdio.h>
#include <stdlib.h>

typedef struct listitem{
	int data;
	struct listitem *next;
}item;

int main()
{
	item *head, *temp;

	head = NULL;
	for(int i = 0; i < 3;i++){
		temp = malloc(sizeof(item));
		temp->data = i;
		temp->next = head;
		head = temp;
	}
	temp = head;
	while(temp != NULL){
		printf("list item: current=%p,next=%p,data=%d\n", 
				temp, temp->next,temp->data);
		temp= temp->next;
	}
	return 0;
}
