#include "jzinferno.h"

int file_or_dir_exists(const char *file) {
	struct stat buffer;
	if (stat(file, &buffer) == 0) {
		return 1;
	}
	return 0;
}
