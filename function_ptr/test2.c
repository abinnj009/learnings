#include <stdio.h>

#define NUM_A 1
#define NUM_B 2

typedef int (*two_num_operation)(int, int);

static int sum(int a, int b){
	return a + b;
}

static int sum_via_pointer(int a, int b, two_num_operation *fnp)
{
	return fnp(a,b);
}
static two_num_operation get_sum_fun()
{
	return &sum;
}

void test_pointer_as_variable()
{
	two_num_operation sum_p = &sum;

	printf("Pointer as variable: \t %d + %d = %d\n", NUM_A, NUM_B, (*sum_p)
			(NUM_A, NUM_B));
}

void test_pointer_as_param()
{
	printf("pointer as param:\t%d +%d=%d\n", NUM_A, NUM_B, sum_via_pointer(NUM_A, NUM_B));
}

// test - use function pointer as return value,
void test_pointer_as_return_value() {
    printf("pointer as return value:\t %d + %d = %d\n", NUM_A, NUM_B, (*get_sum_fun())(NUM_A, NUM_B));
}

int main() {
    test_pointer_as_variable();
    test_pointer_as_param();
    test_pointer_as_return_value();

    return 0;
}


