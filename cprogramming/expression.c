#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
	char item[SIZE];
	int top;
}Stack;


void push(Stack *, char);
char pop(Stack *);
int isEmpty(Stack *);
char stacktop(Stack *);

int isOpeningMatch(char, char);
int checkExpr(char[]);

void push(Stack *sp, char v) {
	if(sp->top == SIZE-1){
		printf("Stack overflow, terminating program\n");
		exit(1);
	}
	sp->item[++sp->top] = v;
}

char pop(Stack *sp) {

	if(isEmpty(sp)){
		printf("Stack empty, terminating program\n");
		exit(1);
	}
	return sp->item[sp->top--];
}
int isEmpty(Stack *sp) {
	return sp->top == -1;
}
char stacktop(Stack *sp) {
	if (isEmpty(sp)){
		printf("Stack empty, terminating program \n");
		exit(1);
	}
	return sp->item[sp->top];

}

int isOpeningMatch(char left, char right) {
	int match = 0;
	switch(left){
		case '(': if(right == ')')
				  match = 1;
			 break;
		case '{': if(right == '}')
				  match = 1;
			  break;
		case '[': if(right == ']')
				  match = 1;
			  break;
		default: printf("Invalid symbol encountered. terminating program \n");
			 exit(1);
	}
	return match;
}

int checkExpr(char expr[]){
	Stack stack;
	stack.top = -1;

	int error = 0;

	int i = 0;
	while(expr[i] != '\0'){
	
	 char next_char = expr[i];
	 if(next_char == '(' || next_char == '{' || next_char == '['){
		 if(!isEmpty(&stack)){
		 	if(next_char == '{') {
				if(stacktop(&stack) == '(' || stacktop(&stack) == '['){
					printf("precedence error\n");
					error = 1;
				}
			}
			else if(next_char == '[') {
				if(stacktop(&stack) == '(') {
					printf("precedence error\n");
					error = 1;
				}
			}
		 }
	 	push(&stack, next_char);
	 }
	 else if(next_char == ')' || next_char == '}' || next_char == ']') {
	 	if(isEmpty(&stack)){
			error = 1;
			break;
		}
		else if(isOpeningMatch(stacktop(&stack), next_char)) {
			pop(&stack);
		}
		else{
			error = 1;
			break;
		}
	 }
	 ++i;
	}
	if (!error && !isEmpty(&stack)){
		error = 1;
	}
	return error;
}


int main() {
	char expr[SIZE];
	printf("Enter expression: ");
	scanf("%s", expr);

	if (checkExpr(expr)) {
		printf("Doesnot contain well formed brackets\n");
	}
	else {
		printf("Contains well formed brackets\n");
	}
	return 0;

}
