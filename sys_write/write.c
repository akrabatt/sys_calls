#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main()
{
	// files descriptors
	int src_fd = 0;
	int dst_fd = 0;

	ssize_t bytes_read = 0; // contain how many bytes have been read
	ssize_t total_write = 0; // contain how many bytes have been write
	ssize_t bytes_written = 0;
	struct stat st; 	// file info struct
	off_t size_buff = 0;		// size dst file
	
	// open files src and dst
	if((src_fd = open("./src.txt", O_RDONLY)) == -1) { perror("Error opening src file\n"); exit(EXIT_FAILURE); }
	if((dst_fd = open("./dst.txt", O_WRONLY)) == -1) { perror("Error opening dst file\n"); close(src_fd); exit(EXIT_FAILURE); }
	printf("Files opened successfully!");

	// get information about size src file
	if(fstat(src_fd, &st) == -1) { perror("Error get info about src file\n"); close(src_fd); close(dst_fd); exit(EXIT_FAILURE); }
	size_buff = st.st_size;
	printf("File's size = %ld bytes\n", (long)size_buff);

	// create buff
	char *buff = malloc(size_buff + 1);
	if(buff == NULL) { perror("Error memmory allocation"); close(src_fd); close(dst_fd); exit(EXIT_FAILURE); }
	
	//read src file
	if((bytes_read = read(src_fd, buff, size_buff)) == -1) { perror("Error read src file\n"); close(src_fd); close(dst_fd); free(buff); exit(EXIT_FAILURE); }

	// write recived text to dst file
	while(total_write < size_buff)
	{	
		bytes_written = write(dst_fd, buff + total_write, bytes_read - total_write);
		if(bytes_written == -1) 
		{
			if(errno == EINTR) { continue; }
			perror("Error write dst file");
			free(buff);
			close(src_fd);
			close(dst_fd);
			exit(EXIT_FAILURE);
		}
		total_write += bytes_written;	
	}

	// free data
	close(dst_fd);
	close(src_fd);
	free(buff);
	printf("File copied successfully!\n");
	
	return 0;
}
