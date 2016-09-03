#Makefile for OS_Sandbox
#Anand Jayaram

CC=gcc
CFLAGS=-Wall -Wextra -pedantic

all:
	$(CC) $(CFLAGS) fend.c fend.h -o fend

clean:
	rm -rf *.o *.exe *.exe.stackdump

save:
	git add fend.c fend.h Makefile
	git commit -m "$m"
	
#sync changes to repository
sync:
	git push
