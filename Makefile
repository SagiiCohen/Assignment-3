# -*- Makefile -*-
all: sortLibrary.so findLibrary.so mainA mainB

mainB: main_find.o findLibrary.so
	gcc -Wall -o txtfind main_find.o ./findLibrary.so
findLibd: findLibrary.so

main_find.o: main_find.c txtfind.h
	gcc -Wall -c main_find.c
txtfind.o: txtfind.c txtfind.h
	gcc -Wall -fPIC -c txtfind.c
findLibrary.so: txtfind.o
	gcc -shared -o findLibrary.so txtfind.o

mainA: main_sort.o sortLibrary.so
	gcc -Wall -o isort main_sort.o ./sortLibrary.so
sortLibd: sortLibrary.so

main_sort.o: main_sort.c isort.h
	gcc -Wall -c main_sort.c
isort.o: isort.c isort.h
	gcc -Wall -fPIC -c isort.c
sortLibrary.so: isort.o
	gcc -shared -o sortLibrary.so isort.o
.PHONY: clean all sortLibd finLibd

clean: 
	rm -f *.o *.so isort txtfind
