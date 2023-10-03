#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

/* Changes working directory to a specified directory */
uint8_t mshell_command_cd (char *argv[]) {
	const char *home;

	if (!argv[1]) {
		home = getenv("HOME");

		if (home == NULL)
			return 1;

		chdir(home);
	}

	else if (chdir(argv[1]) == -1) {
		fprintf(stderr, "ERROR: No such path %s\n", argv[1]);
		return 1;
	}

	return 0;
}
