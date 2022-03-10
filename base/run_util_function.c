#include "jzinferno.h"

#define _RUN_FUNC if (argv[1] && !strcmp(argv[1], "--version")) { puts(_VERSION_); return 0; } return

int run_util_function(int argc, char **argv, char *func_name) {
	if (!func_name) {
		puts(_PROG_NAME_": error");
		return 1;
	}

	#ifdef _GETENFORCE_
	else if (!strcmp(func_name, "getenforce")) {
		_RUN_FUNC getenforce_main(argc, argv);
	}
	#endif
	#ifdef _SELINUXENABLED_
	else if (!strcmp(func_name, "selinuxenabled")) {
		_RUN_FUNC selinuxenabled_main(argc, argv);
	}
	#endif
	#ifdef _SETENFORCE_
	else if (!strcmp(func_name, "setenforce")) {
		_RUN_FUNC setenforce_main(argc, argv);
	}
	#endif

	else {
		printf("%s: not a function\n", func_name);
	}
	return 1;
}
