#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd = 0;

	if((fd = open("./f2.txt", O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG)) == -1) { perror("Error open file!\n"); exit(EXIT_FAILURE); }
	printf("file opened successul!\nfd=%d\n",fd);

	if(close(fd) == -1) { perror("Error clese file!\n"); exit(EXIT_FAILURE); }
	printf("file closed successul!\nfd=%d\n",fd);

	return EXIT_SUCCESS;
}
