#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <dirent.h>

uint8_t mshell_command_dir (char *argv[]) {
	struct dirent *entry;
	DIR *dp = NULL;

	if (argv[1] == NULL)
		return 1;

	while (*argv) {
		if (*++argv == NULL)
			break;

		dp = opendir(*argv);

		if (dp == NULL) {
			fprintf(stderr, "ERROR: Cannot open directory %s\n", *argv);
			return 1;
		}

		fprintf(stdout, "WD:\t%s\n", *argv);

		while ((entry = readdir(dp))) {
			switch (entry->d_type) {
				case DT_DIR: fprintf(stdout, "DIR:\t"); break;
				case DT_LNK: fprintf(stdout, "LINK:\t"); break;
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

	return 0;
}
