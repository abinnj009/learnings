#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int id;
	if((id = fork())){
		printf("Parent process with child id:%d\n", id);
	}
	else
		printf("Child process here\n");
	return 1;
}
