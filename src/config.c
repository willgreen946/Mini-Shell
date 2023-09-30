#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>

#include "config.h"

struct mshell_config_vars *config_vars;

/* Prints the prompt out to the screen */
void mshell_config_print_prompt (void) {
	char prompt[256], wd[256];

	getcwd(wd, 255);
	strcat(prompt, wd);
	strcat(prompt, ">");

	fprintf(stdout, "%s", prompt);
}
