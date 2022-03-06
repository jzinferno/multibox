#include "multibox.h"

int get_terminal_size(char a) {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (a == 'h') {
		return w.ws_row;
	}
	if (a == 'w') {
		return w.ws_col;
	}
	return 0;
}

int get_terminal_height(void) {
	return get_terminal_size('h');
}

int get_terminal_width(void) {
	return get_terminal_size('w');
}
