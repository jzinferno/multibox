#include "jzinferno.h"

#ifdef _GETENFORCE_
void getenforce_usage(void) {
	puts(
		"Usage: getenforce"
	);
}
#endif

#ifdef _SELINUXENABLED_
void selinuxenabled_usage(void) {
	puts(
		"Usage: selinuxenabled"
	);
}
#endif

#ifdef _SETENFORCE_
void setenforce_usage(void) {
	puts(
		"Usage: setenforce [0|1]"
	);
}
#endif
