#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAXLEN 100

char *string_function(char *string)
{
	char *s;
	s = malloc(MAXLEN);
	strcat(s, "hello");
	strcat(s, string);
	strcat(s, "\n");
	return s;
}

int main(int argc, char **argv)
{
	printf("%s", string_function("Fred"));
	printf("%s",string_function("Gussie Fink-Nottle"));
	return 0;
}
