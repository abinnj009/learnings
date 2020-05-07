CFLAGS= -g -Wall -Wextra

LIBNAME = libdll.a
TARGET: ${LIBNAME} exe
${LIBNAME}: dll.o
	ar rs ${LIBNAME} dll.o
exe: main.o ${LIBNAME}
	gcc   -gdwarf-2 -g3 main.c -o exe -L . -ldll
main.o: main.c
	gcc  -gdwarf-2 -g3 -c  -I . main.c -o main.o
dll.o: dll.c
	gcc  -gdwarf-2 -g3 -c  -I  . dll.c -o dll.o

clean:
	rm *.o
	rm exe
	rm ${LIBNAME}
