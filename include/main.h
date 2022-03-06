#ifdef _GETENFORCE
int getenforce_main(int, char *[]);
#endif

#ifdef _SELINUXENABLED
int selinuxenabled_main(int, char *[]);
#endif

#ifdef _SETENFORCE
int setenforce_main(int, char *[]);
#endif

int multibox(int, char *[], char *);

extern char *function_list[];
extern int function_count;

void print_all_function(void);
void print_function_list(void);
void print_version(void);
