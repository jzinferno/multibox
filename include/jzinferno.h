#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <strings.h>
#include <string.h>
#include <libgen.h>

#include "main.h"

#define ENFORCE_FILE "/sys/fs/selinux/enforce"

int file_or_dir_exists(char *);

int get_terminal_height(void);
int get_terminal_width(void);

FILE* open_file_for_read(const char *path);
FILE* open_file_for_write(const char *path);
