CC = gcc
EXEC = maze
CFLAGS =  -Wall -Werror -pedantic -g -std=c89
OBJ = fileIO.o main.o LinkedList.o terminal.o playerSettings.o snakeSettings.o

ifdef DEBUG
CFLAGS += -D DEBUG -g # -g for valgrind
DEBUG : clean $(EXEC)
endif

ifdef Secret
CFLAGS += -D Secret
Editor : clean $(EXEC)
endif

ifdef Editor
CFLAGS += -D Editor
Editor : clean $(EXEC)
endif

ifdef DARK
CFLAGS += -D DARK
Editor : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC) 

main.o : main.c terminal.h LinkedList.h playerSettings.h fileIO.h snakeSettings.h
	$(CC) $(CFLAGS) main.c -c 

playerSettings.o : playerSettings.c playerSettings.h LinkedList.h
	$(CC) $(CFLAGS) playerSettings.c -c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

fileIO.o : fileIO.c fileIO.h
	$(CC) $(CFLAGS) fileIO.c -c	

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) LinkedList.c -c

snakeSettings.o : snakeSettings.c snakeSettings.h fileIO.h LinkedList.h playerSettings.h
	$(CC) $(CFLAGS) snakeSettings.c -c

clean:
	rm -f $(EXEC) $(OBJ)

