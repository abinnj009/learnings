#include "dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

typedef struct emp_ {
	char name[30];
	unsigned int salary;
	char designation[30];
	unsigned int emp_id;
	node_t glnode;
}emp_t;

void print_emp_details(emp_t *emp){

    printf("Employee name = %s\n", emp->name);
    printf("salary = %u\n", emp->salary);
    printf("designation = %s\n", emp->designation);
    printf("emp_id = %u\n", emp->emp_id);
}


int main(int argc, char **argv)
{
	emp_t *emp1 = calloc(1, sizeof(emp_t));
	strncpy(emp1->name, "neha", strlen("neha"));
        emp1->salary = 5000;
        strncpy(emp1->designation, "HR", strlen("HR"));
        emp1->emp_id = 21;
	node_init((&emp1->glnode));

	emp_t *emp2 = calloc(1, sizeof(emp_t));
        strncpy(emp2->name, "Abhishek", strlen("Abhishek"));
        emp2->salary = 150000;
        strncpy(emp2->designation, "SE3", strlen("SE3"));
        emp2->emp_id = 32;
        node_init((&emp2->glnode));

        emp_t *emp3 = calloc(1, sizeof(emp_t));
        strncpy(emp3->name, "Arun",strlen("Arun"));
        emp3->salary = 60000;
        strncpy(emp3->designation, "SE4", strlen("SE4"));
        emp3->emp_id =27;
        node_init((&emp3->glnode));
	
	list_t *emp_list = calloc(1, sizeof(list_t));
	init_list(emp_list, offsetof(emp_t, glnode));

	add_node(emp_list, &emp1->glnode);
        add_node(emp_list, &emp2->glnode);
        add_node(emp_list, &emp3->glnode);

	emp_t *ptr = NULL;
	ITERATE_LIST_BEGIN(emp_list, emp_t, ptr){
		print_emp_details(ptr);
	} ITERATE_LIST_END;

	 remove_node(emp_list, &emp2->glnode);
        printf("\nPrinting again...\n");

        ITERATE_LIST_BEGIN(emp_list, emp_t, ptr){
                print_emp_details(ptr);
        } ITERATE_LIST_END;

	return 1;
}
