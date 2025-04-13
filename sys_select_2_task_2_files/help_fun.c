#include <iostream.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "help_fun.h"


void create_files_get_fd(char *file_1, char *file_2, fds *descr)
{
	if((descr->file_1(file_1, O_RDWR | O_CREAT, 
					  S_IRUSR | S_IWUSR | S_IXUSR
					  S_IRGRP | S_IWGRP | 
					  S_IROTH | S_IWOTH)) == -1)
	{ 
		perror("Error opening file_1!\n"); exit(EXIT_FAILURE);
	}

	if((descr->file_2(file_1, O_RDWR | O_CREAT, 
					  S_IRUSR | S_IWUSR | S_IXUSR
					  S_IRGRP | S_IWGRP | 
					  S_IROTH | S_IWOTH)) == -1) 
	{ 
		perror("Error opening file_2!\n"); close(descr->file1); exit(EXIT_FAILURE);
	}
}

void check_files(fds *descr_ptr, fd_set *readfds_ptr, char file1, char file2)
{
	ssize_t bytes_read = 0;
	char buffer[100];

	if(FD_ISSET(descr_ptr->file_1, read_fds))
	{
		//read bytes
		bytes_read = read(descr_ptr->file_1, buffer, sizeof(buffer) - 1);
		if(bytes_read > 0) 
		{
			buffer[bytes_read] = '\0';
			printf("Data read from %s: %s\n", file_1, buffer);

			// write notify to file_2
			const char *message = "Data was written ti file1.txt\n";
			if(write(descr_ptr->file_2, message, strlen(message)) == -1)
			{
				perror("Error writing to file2"); exit(EXIT_FAILURE);
			}
		}
		
	}
}
