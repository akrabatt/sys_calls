#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int fd = 0;
	off_t file_size = 0;
	off_t new_file_size = 0;
	
	const char *file_name = "./f1.txt";
	off_t new_size = 150;
	
#ifdef FTRUNCATE

	// opening file
	if((fd = open("./f1.txt", O_RDWR)) == -1) { perror("Error open f1.txt\n"); exit(EXIT_FAILURE); }
	printf("File opened...\n");	

	// get file size
	if((file_size = lseek(fd, 0, SEEK_END)) == -1) { perror("Error in getting file's size\n"); close(fd); exit(EXIT_FAILURE); }	
	printf("Files size: %ld\n", (long)file_size);
	
	// for test devide file's size, it's new files size for test function
	new_file_size = file_size / 2;

	if(ftruncate(fd, new_file_size) == -1) { perror("Error truncating file\n"); close(fd); exit(EXIT_FAILURE); }
	printf("File ftruncated successfully\n");

	// close file
	close(fd);
#else

	if(truncate(file_name, new_size) == -1)
	{
		perror("Error truncating file\n");
		return EXIT_FAILURE;
	}
	printf("File '%s' truncated to %ld bytes\n", filename, new_size);

#endif

	return 0;
}
