#ifndef __CONFIG_H__
#define __CONFIG_H__

/* This is not a configuration file for the program,
 * instead this file and config.c include the functions,
 * of the config file */

struct mshell_config_vars{
	char *prompt;
	char *home_directory;
	char *username;
	char *hostname;
	char *config_path;
};

void mshell_config_print_prompt(void);

#include "config.c"

#endif /* __CONFIG_H__ */
