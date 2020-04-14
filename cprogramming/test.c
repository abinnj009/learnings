#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
        pid_t child = fork();

        if(child == -1) return EXIT_FAILURE;
        if(child) {
		int status;
		waitpid(child, &status, 0);
		return EXIT_SUCCESS;
        }else {
	
		execl("/bin/ls", "ls", "-alh", (char *) NULL);
		perror("exec failed!");
	}
}

