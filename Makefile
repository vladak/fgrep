all: fgrep

fgrep: fgrep.c
	$(CC) fgrep.c

clean:
	rm -f fgrep
