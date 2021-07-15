CC=gcc
CFLAGS=-Wall

all: app

app: app.c screen.o mygetch.o potager.o plante.o
	$(CC) $^ $(CFLAGS) -o $@

screen.o: screen.c screen.h
	$(CC) $< $(CFLAGS) -c

mygetch.o: mygetch.c mygetch.h
	$(CC) $< $(CFLAGS) -c

potager.o: potager.c potager.h screen.h
	$(CC) $< $(CFLAGS) -c

plante.o: plante.c plante.h
	$(CC) $< $(CFLAGS) -c

clean:
	rm -rf *.o app