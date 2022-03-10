#include "jzinferno.h"

char *function_list[] = {
	#ifdef _GETENFORCE_
	"getenforce",
	#endif
	#ifdef _SELINUXENABLED_
	"selinuxenabled",
	#endif
	#ifdef _SETENFORCE_
	"setenforce",
	#endif
};

int function_count = sizeof(function_list) / sizeof(function_list[0]);
