#include "jzinferno.h"

char *applets_table[] = {
	"getenforce",
	"selinuxenabled",
	"setenforce"
};

bb_applet applets[] = {
	getenforce_main,
	selinuxenabled_main,
	setenforce_main
};

int applets_count = sizeof(applets_table) / sizeof(char*);