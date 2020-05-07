LIBNAME = libdll.a
TARGET: ${LIBNAME} exe
${LIBNAME}: dll.o
	ar rs ${LIBNAME} dll.o
exe: main.o ${LIBNAME}
	gcc -g main.o -o exe -L . -ldll
dll.o: dll.c
	gcc -g -c -I . dll.c -o dll.o
main.o: main.c
	gcc -g -c -I . main.c -o main.o
clean:
	rm *.o
	rm exe
	rm ${LIBNAME}
