#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef int (*comparator)(void *,void *);

int greater(void *x, void *y)
{
        return x < y;
}

comparator gt = greater;

int main(int argc, char **argv)
{
        int a=10, b = 15;
        printf("%d", gt(&a, &b));
        return 1;
}

