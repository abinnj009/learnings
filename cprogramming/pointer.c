#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef int (*comparator)(void*,void*);
int greater_than(void *a,void *b){
	return a > b;
}
comparator gt = greater_than;

int main()
{
	int y=50, x=100;
	printf("%d",gt(&x,&y));
	return 0;
}

