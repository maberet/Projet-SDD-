CC=gcc
CFLAGS=-Wextra -Wall
LDFLAGS=
EXEC=agenda

all:$(EXEC)

agenda: main.o motif.o semaine.o action.o
	$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Lancer le programme avec ./agenda action.txt"

action.o : action.c action.h 
	$(CC) -o $@ -g $< $(CFLAGS)
	
semaine.o : semaine.c semaine.h 
	$(CC) -o $@ -g $< $(CFLAGS)

motif.o : motif.c motif.h 
	$(CC) -o $@ -g $< $(CFLAGS)

main.o : main.c motif.h 
	$(CC) -o $@ -g $< $(CFLAGS)

clean:
	rm -rf *.o

rmExec: clean
	rm -rf $(EXEC)