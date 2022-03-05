#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <strings.h>
#include <string.h>
#include <libgen.h>

#include "config.h"

#ifdef CONFIG_GETENFORCE
int getenforce_main(int, char *[]);
#endif

#ifdef CONFIG_SELINUXENABLED
int selinuxenabled_main(int, char *[]);
#endif

#ifdef CONFIG_SETENFORCE
int setenforce_main(int, char *[]);
#endif

#define ENFORCE_FILE "/sys/fs/selinux/enforce"

int multibox(int, char *[], char *);

extern char *function_list[];
extern int function_count;
void print_all_function(void);
void print_function_list(void);

int file_exists(char *);
int dirr_exists(char *);

int get_terminal_size(char);
int get_terminal_width(void);
int get_terminal_height(void);

FILE* open_file_for_read(const char *path);
FILE* open_file_for_write(const char *path);

#define PROGRAM_VERSION "multibox 0.0.1"CONFIG_EXTRAVERSION
