#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#include "config.h"
#include "commands.h"

struct MSHELL_COMMAND_MAP {
	uint8_t (*function)(char *argv[]);
	const char *command;
};

/* This is a map of the built in shell commands */
struct MSHELL_COMMAND_MAP mshell_command_map[] = {
	{ mshell_command_cd, "cd" },
	{ mshell_command_exit, "exit" },
	{ mshell_command_dir, "dir" },
	{ mshell_command_copy, "copy" },
	{ mshell_command_cls, "cls" },
};

void mshell_signal_handler (int sig) {
	switch (sig) {
		case SIGKILL:
			break;
		case SIGSTOP:
			break;
	}
}

/* Goes through mshell_command_map until it shows NULL,
 * or finds an matching string to the command,
 * if it finds a match it will call the corresponding function */
uint8_t mshell_run_built_in (char *argv[]) {
	for (size_t k = 0; mshell_command_map[k].command; k++)
		if (!strcmp(mshell_command_map[k].command, argv[0])) {
			mshell_command_map[k].function(argv);
			return 0;
		}
	return 255;
}

/* Uses execvp to execute a command */
uint8_t mshell_exec (char *argv[]) {
	int status;
	uint8_t ret;
	pid_t pid, wpid;

	pid = wpid = ret = status = 0;

	pid = fork();

	if (pid == 0) {
		ret = execvp(argv[0], argv);
		fprintf(stderr, "%s: Unkown Command!\n", argv[0]);
	}

	else if (pid > 0) {
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}

	return ret;
}

/* If command is not built in send argv[] off to execvp */
uint8_t mshell_run_command (char *argv[]) {
	uint8_t ret;

	if (argv[0] == NULL)
		return 0; /* Do nothing if nothing is passed */

	if (!mshell_run_built_in(argv))
		return 0;
	else ret = mshell_exec(argv);

	return ret;
}

/* Splits up string by whitespace and assigns words to argv array */
void mshell_input_parse (char *argv[], char *string, size_t array_size) {
	char **Pargv;

	/* Splitting up string by whitespace */
	for (Pargv = argv; (*Pargv = strsep(&string, " \t")) != NULL;)
		if (**Pargv != (char) 0)
			if (++Pargv >= &argv[array_size])
				break;
}

/* The main loop of the program */
void mshell_input_loop (void) {
	char buf[256], *argv[256], *Pbuf;

	for (;;) {
		mshell_config_print_prompt();

		if (signal(SIGINT, mshell_signal_handler) == SIG_ERR){}

		/* Grabbing user input and removing \n if any */
		if (fgets(buf, 255, stdin) != NULL)
			if ((Pbuf = strchr(buf, '\n')) != NULL)
				*Pbuf = (char) 0;

		/* Parse it to fill the argv array */
		mshell_input_parse(argv, buf, 256);

		mshell_run_command(argv);
	}
}

int main (void) {
	mshell_input_loop();
	return 0;
}
