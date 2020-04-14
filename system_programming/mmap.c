#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct record_{
	int id;
	char name[80];
}record_t;

int main()
{
	int fd;
	size_t size;
	record_t *records;
	fd = open("foo", O_RDWR);
	size = lseek(fd,0, SEEK_END);

	records = (record_t *)mmap(NULL, size, PROT_READ | PROT_WRITE,
			MAP_PRIVATE, fd, 0);
	records[1].id = 99;

	msync(records, size, MS_SYNC);
}
