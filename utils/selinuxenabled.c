#include "jzinferno.h"

int selinuxenabled_main(int argc, char **argv) {
	if (file_or_dir_exist(ENFORCE_FILE) == 1) {
		return 0;
	}
	return 1;
}
