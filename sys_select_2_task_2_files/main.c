#include <stdio.h>
#include "help_fun.h"
#include <sys/select.h>


int main()
{
	// create descriptors struct
	fds descriptors;
	fds descr_ptr = &descriptors;
	if(descr_ptr == NULL) { perror("Error create ptr to struct fds\n"); exit(EXIT_FAILURE); }

	// files name
	char f1[] = "file_1.txt";
	char f2[] = "file_2.txt";

	// create time struct and ptr
	struct timeval tv;
	tv.tv_sec = -1;
	tv.tv_usec = -1;

	// create fd_set struct
	fd_set readfds;
	fd_set *readfds_ptr = &readfds;
	
	// create files
	create_files_get_fd(f1, f2, descr_ptr);

	// add descriptors 
	FD_ZERO(&readfds);
	FD_SET(descriptors.file_1, &readfds);
	FD_SET(descriptors.file_2, &readfds);

	// search max descriptor value
	int max_fd = descriptors.file_1 > descriptors.file_2 ? descriptors.file_1 : descriptors.file_2;
	max_fd += 1;

	int activity = select(max_fd, &readfds, NULL, NULL, NULL);


	close(descriptors.file_1);
	close(descriptors.file_2);
	
	return 0;
}
