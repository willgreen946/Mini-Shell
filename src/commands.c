#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "commands.h"

uint8_t mshell_command_exit (char *argv[]) {
	exit(0);
	return 0;
}

uint8_t mshell_command_cd (char *argv[]) {
	if (!argv[1]) {
		const char *home = getenv("HOME");

		if (home == NULL)
			return 255;

		chdir(home);
	} else chdir(argv[1]);

	return 0;
}
