SRCDIR = src/

CC = g++

ALL:
	$(CC) $(SRCDIR)*.cpp -o RUN

clean:
	rm -f *.o
