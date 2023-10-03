#include <stdlib.h>
#include <stdint.h>

/* Exits the program */
uint8_t mshell_command_exit (char *argv[]) {
	if (argv[1] != NULL)
		exit(atoi(argv[1]));

	exit(0);
}
