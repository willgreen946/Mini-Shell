#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <dirent.h>

/* Changes the working directory to one specified */
uint8_t mshell_command_cd (char *argv[]);

/* Clears the terminal window */
uint8_t mshell_command_cls (char *argv[]);

/* Quits the program */
uint8_t mshell_command_exit (char *argv[]);

/* Runs the last command */
uint8_t mshell_command_last (char *argv[]);

#include "cd.c"
#include "cls.c"
#include "exit.c"
#include "last.c"

#endif /* __COMMANDS_H__ */
