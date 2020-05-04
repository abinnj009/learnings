#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main()
{
	int status;
	if(fork()){
		printf("Parent waiting for child exit..\n");
		wait(&status);
		if (WIFEXITED(status))
			printf("Child finished normally with exit\
					status: %d\n", WEXITSTATUS(status));
		if(WIFSIGNALED(status))
			printf("child terminated with signal:%d\n",
					WTERMSIG(status));
	}
	else {
		printf("Child running with pid:%d\n", getpid());
		*(int *)0 = 42; //segmentation violation(tried to 
					//access invalid address
		sleep(85);
		exit(3);
	}
}
