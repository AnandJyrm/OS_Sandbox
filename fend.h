#include <sys/ptrace.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <err.h>
#include <sys/user.h>
#include <asm/ptrace.h>
#include <sys/wait.h>
#include <asm/unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>


#ifdef LOGPRINT
#define log(message) printf("LOG:>>\t\t%s\n",message)
#else
#define log(message) {do{}while(0);}
#endif

struct accessGlob{
	int glob;
	char * filename;
};

int parse(char * config) {
	FILE * configFP;
	char string[100];
	if( access( config, R_OK ) != -1 ) {
		configFP = fopen(config, "r");
		fread(string, 5, 20, configFP);
		printf("Config file says %s\n", string);
		fclose(configFP	);
	} else {
		return -1;
	}
	return 0;
}
