#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd = 0;		// for file descriptor
	int bytes_read = 0;		// contain how many bytes have been read
	struct stat st;		// file info
	
	// open file
	if((fd = open("./f1.txt", O_RDONLY)) == -1) { perror("Error open file!\n"); exit(EXIT_FAILURE); }
	printf("File opened successful!\n");

	// read file info(params)
	if(fstat(fd, &st) == -1) { perror("Error read file info!\n"); close(fd); exit(EXIT_FAILURE); }
	off_t filesize = st.st_size;	// get file size for buffer
	printf("File size = %ld bytes\n", filesize);
	char *buffer = malloc(filesize + 1);	// allocate memory for text in file
	if(buffer == NULL) { printf("Error allocate memory!\n"); close(fd); exit(EXIT_FAILURE); }

	// read text from file	
	if((bytes_read = read(fd, buffer, filesize)) == -1) { perror("Error open file!\n"); close(fd); free(buffer); exit(EXIT_FAILURE); }
	buffer[bytes_read] = '\0';

	printf("Read %ld bytes: \n%s\n", (long)bytes_read, buffer);
	
	// close file
	if(close(fd) == -1) { perror("Error close file1\n"); exit(EXIT_FAILURE); }
	free(buffer);
	printf("File closed successful!\n");
	return 0;
}
