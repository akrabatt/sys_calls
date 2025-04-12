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
