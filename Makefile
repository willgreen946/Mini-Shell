all:
	mkdir -p asm
	mkdir -p bin
	$(CC) src/main.c -o bin/mshell -O3 -Wall -Wextra -pedantic

asm:
	$(CC) src/main.c -S -o asm/main.asm -O3 -Wall -Wextra -pedantic
