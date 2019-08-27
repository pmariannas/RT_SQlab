CFLAG = -ansi -pedantic -g

aprog : hash_main.o hash.o
	gcc -o aprog hash_main.o hash.o

hash_main.o : hash_main.c hash.h
	gcc -c $(CFLAFS) hash_main.c

hash.o : hash.c hash.h
	gcc -c $(CFLAFS) hash.c

