#ifdef _GETENFORCE_
int getenforce_main(int, char *[]);
#endif

#ifdef _SELINUXENABLED_
int selinuxenabled_main(int, char *[]);
#endif

#ifdef _SETENFORCE_
int setenforce_main(int, char *[]);
#endif

int run_util_function(int, char *[], char *);

extern char *function_list[];
extern int function_count;

void print_all_function(void);
void print_function_list(void);
int print_version(void);
