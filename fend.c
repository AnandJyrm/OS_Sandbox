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

	Glob accessList;
	
	if(argc < 2) {
		printf("Invalid no of arguments.\n"
			"Format : fend [-c config] <command [args]>\n");
		return -1;
	}
	if(strcmp(argv[1], "-c") == 0) {
		argsNo = 3;
		log("Calling parser with fend argument");
		if(parse(argv[2], &accessList) == -1) {
			printf("Given Config File can't be read.\n");
			return -1;
		}
	} else {
		argsNo = 1;
		if(access("./.fendrc", F_OK) != -1 ) {
			log("Calling parser with ./.fendrc");
			if(parse("./.fendrc", &accessList) == -1) {
				printf("./.fendrc can't be read.\n");
				return -1;
			}
		} else if(access("~/.fendrc", F_OK) != -1) {
			log("Calling parser with ~/.fendrc");
			if(parse("~/.fendrc", &accessList) == -1) {
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
	
	/*
	 *Fork and Ptrace shit goes here
	 */
	printf("%s\n",accessList.fileName);
	
	execv(argv[argsNo],(argv+argsNo));

	return 1;
}
