#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
int main()
{
	char line[100];
	while(printf(">"), gets((line)!= NULL)) {
		if(fork() == 0){
			execlp(line, line, (char *)0);
			printf("not found: %s!\n", line);
			exit(1);
		}
		else wait(0); //prompt the user again
	}
	return 0;
}
