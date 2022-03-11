#include "jzinferno.h"

int run_util_function(int argc, char **argv, char *func_name) {
	if (!func_name) {
		puts(_PROG_NAME_": error");
	}

	#ifdef _GETENFORCE_
	else if (!strcmp(func_name, "getenforce")) {
		if (argv[1]) {
			if (!strcmp(argv[1], "--help")) {
				getenforce_usage();
				return 0;
			}
			if (!strcmp(argv[1], "--version")) {
				puts(_VERSION_);
				return 0;
			}
		}
		return getenforce_main(argc, argv);
	}
	#endif
	#ifdef _SELINUXENABLED_
	else if (!strcmp(func_name, "selinuxenabled")) {
		if (argv[1]) {
			if (!strcmp(argv[1], "--help")) {
				selinuxenabled_usage();
				return 0;
			}
			if (!strcmp(argv[1], "--version")) {
				puts(_VERSION_);
				return 0;
			}
		}
		return selinuxenabled_main(argc, argv);
	}
	#endif
	#ifdef _SETENFORCE_
	else if (!strcmp(func_name, "setenforce")) {
		if (argv[1]) {
			if (!strcmp(argv[1], "--help")) {
				setenforce_usage();
				return 0;
			}
			if (!strcmp(argv[1], "--version")) {
				puts(_VERSION_);
				return 0;
			}
		}
		return setenforce_main(argc, argv);
	}
	#endif

	else {
		printf("%s: not a function\n", func_name);
	}
	return 1;
}
