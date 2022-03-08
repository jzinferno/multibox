#include "jzinferno.h"

int get_terminal_size(const char *hw) {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (hw[0] == 'h' && hw[1] == '\0') {
		return w.ws_row;
	}
	if (hw[0] == 'w' && hw[1] == '\0') {
		return w.ws_col;
	}
	return 0;
}
