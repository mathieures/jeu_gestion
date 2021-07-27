CC=gcc
CFLAGS=-Wall -O2

all: app.exe

app.exe: app.c screen.o rules.o mygetch.o potager.o plante.o leaderboard.o
	$(CC) $^ $(CFLAGS) -o $@

screen.o: screen.c screen.h
	$(CC) $< $(CFLAGS) -c

rules.o: rules.c rules.h
	$(CC) $< $(CFLAGS) -c

mygetch.o: mygetch.c mygetch.h
	$(CC) $< $(CFLAGS) -c

potager.o: potager.c potager.h screen.h
	$(CC) $< $(CFLAGS) -c

plante.o: plante.c plante.h
	$(CC) $< $(CFLAGS) -c

leaderboard.o: leaderboard.c leaderboard.h
	$(CC) $< $(CFLAGS) -c

clean:
	rm -rf *.o
