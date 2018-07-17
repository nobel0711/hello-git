myapp: 1.o 2.o 3.o
	gcc -o myapp 1.o 2.o 3.o

1.o: 1.c 2.h 3.h
	gcc -c 1.c -o 1.o

2.o: 2.c 2.h
	gcc -c 2.c -o 2.o

3.o: 3.c 3.h
	gcc -c 3.c -o 3.o

clean:
	rm -rf *.o myapp



