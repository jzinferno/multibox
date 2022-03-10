#include "jzinferno.h"

int file_or_dir_exist(const char *file) {
	struct stat buffer;
	if (stat(file, &buffer) == 0) {
		return 1;
	}
	return 0;
}
