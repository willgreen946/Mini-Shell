#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

/* exits out of the program */
uint8_t mshell_command_exit (char *argv[]);

/* implementation of the cd command */
uint8_t mshell_command_cd (char *argv[]);

#include "commands.c"
#endif /* COMMANDS_H */
