#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/* Gets the amount of elements of an array (argc) */
size_t mshell_command_copy_get_argc (char *argv[]) {
	size_t argc;
	for (argc = 0; *++argv; argc++);
	return argc;
}

uint8_t mshell_command_copy (char *argv[]) {
	size_t lc = 0; /* The amount of time we need to loop */
	size_t argc = mshell_command_copy_get_argc(argv);

	if ((lc = (argc % 2)) != 0) {
		fprintf(stderr, "ERROR: Insufficient arg count for a call to copy!\n");
		return 1;
	}

	while (*argv) {

	}
	return 0;
}
