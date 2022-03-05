#include "multibox.h"

int file_exists(char *file) {
	struct stat buffer;
	if (stat(file, &buffer) == 0) {
		return 1;
	}
	return 0;
}

int dirr_exists(char *file) {
	return file_exists(file);
}