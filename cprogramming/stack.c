#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *item;
	int top;
	int size;
}Stack;

void  push (Stack *xp, int value);
int pop(Stack *xp);
void init(Stack *xp,int  size);

void init(Stack *xp, int size){
	xp->top  = -1;
	xp->item = malloc(size*sizeof(int));
	if(xp->item == NULL){
		printf("memory allocation failed");
		exit(1);
	}
	xp->size = size;

}
void push(Stack *xp, int value) {
	if(xp->top == xp->size-1) {
		int * temp;
		temp = malloc(xp->size * 2);
		if(temp == NULL) {
		printf("stack overflow");
		return;
		}
		for(int i = 0;i<xp->size;i++){
		 temp[i] = xp->item[i];
		}
		free(xp->item);
		xp->item = temp;
	}
	xp->top++;
	xp->item[xp->top] = value;

}
int pop(Stack *xp) {
	if(xp->top == -1) {
		printf("Stack empty");
		return -1;
	}
	int value = xp->item[xp->top];
	  xp->top --;
	  return value;



}

void deallocate(Stack *xp);
void deallocate(Stack *xp) {
	if(xp->item != NULL) {
		free(xp->item);
	}
xp->size =0;
xp->top = -1;
}
int main() {
Stack s1,s2;
init(&s1,1);
init(&s2,3);
push(&s1, 100);
push(&s2, 200);
push(&s1, 300);
printf("%d:%d:%d", pop(&s1), pop(&s2), pop(&s1));
deallocate(&s1);
deallocate(&s2);

return 0;
}
