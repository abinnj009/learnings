LIBNAME = libdll.a
TARGET: ${LIBNAME} exe
${LIBNAME}: dll.o
	ar rs ${LIBNAME} dll.o
exe: main.o ${LIBNAME}
	gcc -g main.o -o exe -L . -ldll
main.o: main.c
	gcc -g -c -I . main.c -o main.o
dll.o: dll.c
	gcc -g -c -I . dll.c -o dll.o

clean:
	rm *.o
	rm exe
	rm ${LIBNAME}

