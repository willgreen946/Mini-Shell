#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <sys/stat.h>

#include "system.h"

uint8_t mshell_mkdir (const char *dn, mode_t mode) {
	if (!dn)
		return 1;

	if (mkdir(dn, mode)) {
		perror("mkdir() failed: ");
		return 1;
	}

	return 0;
}
