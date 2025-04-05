#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// init vars
	int fd = 0;	
	off_t file_size = 0;
	
	// open file 
	if((fd = open("./f1.txt", O_RDONLY)) == -1) { perror("Error in opening file f1.txt\n"); exit(EXIT_FAILURE); }

	// get file size
	if((file_size = lseek(fd, 0, SEEK_END)) == -1) { perror("Error in getting filesize information\n"); close(fd); exit(EXIT_FAILURE); }	
	printf("file's size: %d\n", file_size);
	
	// close file
	close(fd);
}
