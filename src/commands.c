#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include "sys/system.h"
#include "commands.h"

char *prev_cmd;

// TODO 
uint8_t mshell_command_last (char *argv[]) {
	/* Ignores arguments */
	if (!prev_cmd)
		return 1;
	return 0;
}

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
			fprintf(stderr, "ERROR: Cannot open directory %s\n", *argv);
			return 0;
		}

		while ((entry = readdir(dp))) {
			switch (entry->d_type) {
				case DT_DIR: fprintf(stdout, "DIR:\t"); break;
				case DT_LNK: fprintf(stdout, "LINK:\t" ); break;
				case DT_FIFO: fprintf(stdout, "PIPE:\t"); break;
				case DT_CHR: fprintf(stdout, "CHAR:\t"); break;
				case DT_BLK: fprintf(stdout, "BLOCK:\t"); break;
				case DT_SOCK: fprintf(stdout, "SOCKET:\t"); break;
				case DT_WHT: fprintf(stdout, "WHT:\t"); break;

				case DT_UNKNOWN:
				/* Fall through */
				case DT_REG:
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

/* Clears the console */
uint8_t mshell_command_cls (char *argv[]) {
	/* argv is ignored here */
	fprintf(stdout, "\e[1;1H\e[2J");
	return 0;
}

/* Copys a file or directory somewhere */
uint8_t mshell_command_copy (char *argv[]) {
	size_t argc;

	for (argc = 0; *++argv; argc++)
		;

	// TODO
	/* If argc cannot be divided by 2, cant copy to NULL */
	if ((argc % 2) != 0) {
		fprintf(stderr, "ERROR: Insufficent argc for call to copy!\n");
		return 1;
	}
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
