#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	printf("Start programm...");
	printf("Before fork: PID=%d, PPID=%d\n", getpid(), getppid());
	pid_t pid = fork();

	if(pid < 0) { perror("fork\n"); exit(EXIT_FAILURE); }

	if(pid == 0)
	{
		printf("[child]: PID=%d, PPID=%d\n", getpid(), getppid());
	} else {
		printf("[parent]: PID=%d, child=%d\n", getpid(), pid);
	}	

	return EXIT_SUCCESS;
}
