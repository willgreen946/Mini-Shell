#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <sys/stat.h>

/* Creates a directory */
uint8_t mshell_mkdir (const char *dn, mode_t mode);

#include "mshell_mkdir.c"

#endif /* __SYSTEM_H__ */
