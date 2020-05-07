LIBNAME=libglthread.a
TARGET:${LIBNAME} exe
${LIBNAME}:glthread.o
	ar rs ${LIBNAME} glthread.o
main.o:main.c
	gcc -g -c -I . main.c -o main.o
glthread.o:glthread.c
	gcc -g -c -I . glthread.c -o glthread.o
exe:main.o ${LIBNAME}
	gcc -g main.o -o exe -L . -lglthread
clean:
	rm *.o
	rm exe
	rm ${LIBNAME}
