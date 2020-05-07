#include "dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

typedef struct emp_{
	char name[30];
	unsigned int salary;
	unsigned int emp_id;
	node_t glnode;
}emp_t;

void print_emp_details(emp_t *emp)
{
	printf("Employee name = %s\n", emp->name);
	printf("Salary = %u\n", emp->salary);
	printf("Emp ID = %u\n", emp->emp_id);
}

int main(int argc, char **argv)
{
	emp_t *emp1 = calloc(1, sizeof(emp_t));
	strncpy(emp1->name, "Neha", strlen("Neha"));
	(*emp1).salary = 5000;
	emp1->emp_id = 21;
	node_init((&emp1->glnode));

	emp_t *emp2 = calloc(1, sizeof(emp_t));
        strncpy(emp2->name, "Abhishek", strlen("Abhishek"));
        emp2->salary = 150000;
        emp2->emp_id = 32;
        node_init((&emp2->glnode));

	emp_t *emp3 = calloc(1, sizeof(emp_t));
        strncpy(emp3->name, "Arun", strlen("Neha"));
        emp3->salary = 60000;
        emp3->emp_id = 27;
        node_init((&emp3->glnode));

	list_t *emp_list = calloc(1, sizeof(list_t));
	
	
	
	
	printf("Emp struct size::%d\n", sizeof(emp_t));
	printf("GLnode Size:%d\n", sizeof( emp3->glnode));
	printf("Offset:%d\n", offsetof(emp_t, glnode));
	
	
	init_list(emp_list, offsetof(emp_t, glnode));

	add_node(emp_list, &emp1->glnode);
	add_node(emp_list, &emp2->glnode);
	add_node(emp_list, &emp3->glnode);

	emp_t *ptr = NULL;
	ITERATE_LIST_BEGIN(emp_list, emp_t, ptr){
		print_emp_details(ptr);
	} ITERATE_END;
	remove_node(emp_list, &emp2->glnode);
	printf("\nPrintin again..\n");
	ITERATE_LIST_BEGIN(emp_list, emp_t, ptr){
                print_emp_details(ptr);
        } ITERATE_END;



}
