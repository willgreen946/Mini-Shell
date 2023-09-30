#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "commands.h"

uint8_t mshell_command_exit (char *argv[]) {
	if (argv[1] != NULL)
		exit(atoi(argv[1]));

	exit(0);
	return 0;
}

/* The same as ls command but formatted differently */
uint8_t mshell_command_dir (char *argv[]) {
	struct dirent *entry;
	DIR *dp;

	if (!argv[1])
		argv[1] = strndup(".", 1);

	while (*++argv) {
		dp = opendir(*argv);

		if (!dp) {
			fprintf(stderr, "ERROR: Cannot open directory %s!\n", *argv);
			return 0;
		}

		while ((entry = readdir(dp))) {
			switch (entry->d_type) {
				case DT_DIR: fprintf(stdout, "DIR:\t"); break;
				case DT_LNK: fprintf(stdout, "LINK:\t" ); break;

				case DT_UNKNOWN:
				/* Fall through */
				default: fprintf(stdout, "FILE:\t"); break;
			}

			fprintf(stdout, "%s\n", entry->d_name);
		}

		closedir(dp);
	}

	if (dp) closedir(dp);

	return 0;
}

uint8_t mshell_command_copy (char *argv[]) {
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
