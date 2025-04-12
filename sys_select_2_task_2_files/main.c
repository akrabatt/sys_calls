#include <stdio.h>
#include "help_fun.h"


int main()
{
	fds descriptors;
	fds descr_ptr = &descriptors;
	if(descr_ptr == NULL) { perror("Error create ptr to struct fds\n"); exit(EXIT_FAILURE); }

	char f1[] = "file_1.txt";
	char f2[] = "file_2.txt";

	create_files_get_fd(f1, f2, descr_ptr);
	
	return 0;
}
