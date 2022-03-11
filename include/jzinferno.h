#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <strings.h>
#include <string.h>
#include <libgen.h>

#ifdef _GETENFORCE_
int getenforce_main(int, char *[]);
void getenforce_usage(void);
#endif

#ifdef _SELINUXENABLED_
int selinuxenabled_main(int, char *[]);
void selinuxenabled_usage(void);
#endif

#ifdef _SETENFORCE_
int setenforce_main(int, char *[]);
void setenforce_usage(void);
#endif

int run_util_function(int, char *[], char *);

extern char *function_list[];
extern int function_count;

#ifndef PATH_MAX
# define PATH_MAX 4096
#endif

#define ENFORCE_FILE "/sys/fs/selinux/enforce"

int file_or_dir_exist(const char *);
int get_terminal_size(const char *);
