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
	char fileName[];
};

typedef struct accessGlob Glob;
/*
 * Function to parse the config file and create an array of accessGlob
 */
int parse(char * config, Glob * accessList) {
	FILE * configFP;
	//char string[100];
	if( access( config, R_OK ) != -1 ) {
		configFP = fopen(config, "r");

		/*
		 * Convert the contents of configFP into array of struct accessGlob
		 * using fscanf
		 */
		// int i = 0;
		//while(1){
			log("here");
			if(fscanf(configFP, "%d %s", &(accessList->glob), &(accessList->fileName)) > 0) //{
				printf("\n%d %s\n",accessList->glob, accessList->fileName);
		//		i++;
		//	} else 
		//		break;
		//}
		fclose(configFP);
	} else {
		return -1;
	}
	return 0;
}
