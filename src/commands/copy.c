#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

uint8_t mshell_command_copy (char *argv[]) {
	size_t argc;

	/* Get the arg count */
	for (argc = 0; *++argv; argc++)
		;

	if ((argc % 2) != 0) {
		fprintf(stderr, "ERROR: Insufficient arg count for a call t copy");
		return 1;
	}

	return 0;
}
