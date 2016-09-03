#Makefile for OS_Sandbox
#Anand Jayaram

CC=gcc
CFLAGS=-Wall -Wextra -pedantic

all:    
	$(CC) $(CFLAGS) fend.c fend.h -o fend

debug:
	$(CC) $(CFLAGS) -DLOGPRINT fend.c fend.h -o dfend

clean:  
	rm -rf *.o *.exe *.exe.stackdump fend dfend

save:   
	git add fend.c fend.h Makefile
	git commit -m "$m"
	
sync:	
	git push
