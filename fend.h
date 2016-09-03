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
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>

#ifdef LOGPRINT
#define log(message) printf("LOG:>>\t\t%s\n",message)
#else
#define log(message) {do{}while(0);}
#endif

char Str[] = "Hello World";

int parse(char * config) {
        int configFile;
        char *string = (char *)malloc(sizeof(char) * 128);
        if( access( config, F_OK ) != -1 ) {
                configFile = open(config, O_RDONLY);
                fgets(&string, 5, configFile);
                printf("config file says %s%d", string,len);
                close(configFile);
        } else {
                return -1;
        }
        return 0;
}
