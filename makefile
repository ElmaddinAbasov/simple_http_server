CC=gcc
CCFLAGS=-Wall -Wextra
http_server.o:http_server.c
	$(CC) $(CCFLAGS) -g -c $< -o $@
main:main.c http_server.o
	$(CC) $(CCFLAGS) -g $^ -o $@

