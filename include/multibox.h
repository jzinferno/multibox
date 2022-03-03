#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <strings.h>
#include <string.h>
#include <stdbool.h>
#include <libgen.h>

#include "config.h"

#define ENFORCE_FILE "/sys/fs/selinux/enforce"

int multibox(int argc, char **argv, char *func_name);

extern char *function_list[];
extern int function_count;

bool selinux_enabled_status(void);
