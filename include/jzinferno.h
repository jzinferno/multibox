#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <strings.h>
#include <string.h>
#include <libgen.h>

#ifdef _GETENFORCE_
int getenforce_main(int, char *[]);
#endif

#ifdef _SELINUXENABLED_
int selinuxenabled_main(int, char *[]);
#endif

#ifdef _SETENFORCE_
int setenforce_main(int, char *[]);
#endif

int run_util_function(int, char *[], char *);

extern char *function_list[];
extern int function_count;

void print_all_function(void);
void print_function_list(void);
void install_funcs(char *arg);
void print_version(void);

#define ENFORCE_FILE "/sys/fs/selinux/enforce"

int file_or_dir_exists(const char *);
int get_terminal_size(const char *);
