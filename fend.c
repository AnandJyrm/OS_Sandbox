/* OS_Sandbox
 * Anand Jayaram
 * fend.c
 */

#include "fend.h"

int main(int argc, char * argv[]) {
	char * command;
	char * argsList;
	if(argc < 2) {
		printf("Invalid no of arguments.\n"
			"Format : fend [-c config] <command [args]>\n");
		return -1;
	}
	if(strcmp(argv[1], "-c") == 0) {
		int c = parse(argv[2]);
		if(c == -1) {
			printf("Config File doesn't exist or can't be read.\n");
			log("parser returned -1");
			return -1;
		}
		command = argv[3];
		
	}
	        
	printf("\n%s\n",Str);
	log("hello");
	return 1;
}
