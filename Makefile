all:
	mkdir -p bin
	$(CC) src/main.c -o bin/mshell -O3 -Wall -Wextra -pedantic
