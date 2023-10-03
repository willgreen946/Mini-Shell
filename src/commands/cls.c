#include <stdio.h>
#include <stdint.h>

/* Clears the terminal screen */
uint8_t mshell_command_cls (char *argv[]) {
	/* argv to be ignored */
	fprintf(stdout, "\e[1;1H\e[2J");
	return 0;
}
