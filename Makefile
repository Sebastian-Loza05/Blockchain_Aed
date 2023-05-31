CC = g++
CFLAGS = -std=c++11

all: hello

hello: main.o sha256/SHA256.o
	$(CC) $(CFLAGS) -o hello main.o sha256/SHA256.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

sha256/SHA256.o: sha256/SHA256.cpp
	$(CC) $(CFLAGS) -c sha256/SHA256.cpp -o sha256/SHA256.o

clean:
	rm -rf *.o hello