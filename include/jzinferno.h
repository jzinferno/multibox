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
int print_version(void);

#define ENFORCE_FILE "/sys/fs/selinux/enforce"

int file_or_dir_exists(char *);

int get_terminal_height(void);
int get_terminal_width(void);

FILE* open_file_for_read(const char *path);
FILE* open_file_for_write(const char *path);
