#include <stdio.h>

void (*print)();
void sayhello();

int main()
{
	print=sayhello;
	print();
	return 0;
}
void sayhello()
{
	printf("Hello abin\n");
}
