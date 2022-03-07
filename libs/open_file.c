#include "jzinferno.h"

FILE* open_file_for_read(const char *path) {
	return fopen(path, "r");
}

FILE* open_file_for_write(const char *path) {
	return fopen(path, "w");
}