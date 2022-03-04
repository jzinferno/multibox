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

int if_file_exists(char *);
int get_terminal_width(void);
int get_terminal_height(void);

void print_function(void);
void print_function_list(void);


#define PROGRAM_VERSION "0.0.1"CONFIG_EXTRAVERSION
