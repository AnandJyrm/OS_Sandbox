/* OS_Sandbox
 * Anand Jayaram
 * fend.c
 */

#include "fend.h"

int main(int argc, char * argv[]) {
	int argsNo;

	/* Handle inputs
	 ******************************************************************************************************************
	 */
	if(argc < 2) {
		printf("Invalid no of arguments.\n"
			"Format : fend [-c config] <command [args]>\n");
		return -1;
	}
	if(strcmp(argv[1], "-c") == 0) {
		argsNo = 4;
		log("Calling parser with fend argument");
		if(parse(argv[2]) == -1) {
			printf("Given Config File can't be read.\n");
			return -1;
		}
	} else {
		argsNo = 2;
		if(access("./.fendrc", F_OK) != -1 ) {
			if(parse("./.fendrc") == -1) {
				printf("./.fendrc can't be read.\n");
				return -1;
			}
		} else if(access("~/.fendrc", F_OK) != -1) {
			if(parse("~/.fendrc") == -1) {
				printf("~/.fendrc can't be read.\n");
				return -1;
			}
		} else {
			printf("Cannot find .fendrc anywhere.\nMust provide a config file.\nTerminating...");
			return -1;
		}
	}
	/*********************************************************************************************************************
	 */
	
	printf("Command to execute is %s.\n", command);
	execl(command);
	
	return 1;
}
