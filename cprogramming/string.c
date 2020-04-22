#include <stdio.h>

int main(int argc, char **argv)
{
	char str1[] = "hello world";
	printf("%s %c %u %u %u\n", str1, str1[0], &str1, &str1[0], str1);
	return 1;
}
