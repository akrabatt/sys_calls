#ifndef HELP_FUN_H
#define HELP_FUN_H

// this structur contain 2 file's descriptors
typedef struct 
{
	int file_1;
	int file_2;
} fds;

/**
* this function create 2 files and return their file 
* descriptors
*/
void create_files_get_fd(char *file_1, char *file_2, fds *descr);



#endif // HELP_FUN_H
