#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <strings.h>
#include <string.h>
#include <libgen.h>

typedef int (*bb_applet)(int, char *[]);
extern char *applets_table[];
extern int applets_count;
extern bb_applet applets[];

#define ENFORCE_FILE "/sys/fs/selinux/enforce"

int file_or_dir_exist(const char *);
int get_terminal_size(const char *);

int getenforce_main(int, char *[]);
int selinuxenabled_main(int, char *[]);
int setenforce_main(int, char *[]);