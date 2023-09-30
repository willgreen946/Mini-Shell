#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dirent.h>
#include <unistd.h>

/* Clears the console */
uint8_t mshell_command_cls (char *argv[]);

/* Similar to 'ls' but it formats differently */
uint8_t mshell_command_dir (char *argv[]);

/* Pretty much the same as 'cp' */
uint8_t mshell_command_copy (char *argv[]);

/* Exits out of the program */
uint8_t mshell_command_exit (char *argv[]);

/* Implementation of the cd command */
uint8_t mshell_command_cd (char *argv[]);

#include "commands.c"

#endif /* __COMMANDS_H__ */
