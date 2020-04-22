#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

/* usage: argdemo -a -b -n 400 -t purple */

void main(int argc, char *argv[])
{

	int c;
	int aflag = 0;
	int bflag = 0;
	int numoption = 0;
	char txtoption[200] = "default";

	opterr = 0;

	while(( c = getopt(argc, argv, "abn:t:")) != EOF){
		switch(c){
			case 'a':
				aflag = 1;
				break;
			case 'b':
				bflag = 1;
				break;
			case 'n':
				numoption = atoi(optarg);
				break;
			case 't':
				strcpy(txtoption, optarg);
				break;
			case '?':
				fprintf(stderr, "invalid option: -%c\n", optopt);
				
		
		}
	}

	if (aflag) printf("Option a is set\n");
	if (bflag) printf("Option b is set\n");
	printf("Numeric option value is %d\n", numoption);
	printf("Text option value  is %s\n", txtoption);

	argv += optind;
	argc -= optind;
	while (argc --){
		printf("arg\n", *argv++);
	}
}
