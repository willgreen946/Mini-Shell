cc src/main.c -c -O3 -Wall -o main.o
mkdir -p obj
mv main.o obj/main.o

cc obj/main.o -o mshell
mkdir -p bin
mv mshell bin/mshell

cc src/main.c -S -O3 -Wall -o main.s
mkdir -p asm
mv main.s asm/main.s
