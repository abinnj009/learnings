#include <stdio.h>

#define LENGTH 3

char *words[LENGTH];
int data[LENGTH];
int main(int argc, char **argv)
{
	words[0] = "Zero";
	words[1] = "One";
	words[2] = "Two";

	void *gp;
	int i;
	for(i = 0;i < LENGTH; i++){
		data[i] = i;
	}

	gp = words;
	printf("Address of data %p\n", gp);
	printf("Item pointed by gp %s\n",*( char **)gp);
	gp = (char **)gp + 1;
	printf("Item pointed by gp %s\n", *(char **)gp);
	return 1;


}
