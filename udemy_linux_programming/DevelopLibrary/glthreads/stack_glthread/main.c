#include "glthread.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

typedef struct emp_{
	char name[30];
	unsigned int salary;
	char designation[30];
	unsigned int emp_id;
	glthread_node_t glnode;
} emp_t;

void print_emp_details(emp_t *emp)
{
	printf("Employee name = %s\n", emp->name);
	printf("Salary = %u\n", emp->salary);
	printf("Designation = %s\n", emp->designation);
	printf("Emp ID = %u\n", emp->emp_id);
}

int main(int argc, char **argv)
{
	 emp_t *emp1  = calloc(1, sizeof(emp_t));
    strncpy(emp1->name, "Neha", strlen("Neha"));
    emp1->salary = 50000;
    strncpy(emp1->designation, "HR", strlen("HR"));
    emp1->emp_id = 21;
	glthread_node_init((&emp1->glnode));
	emp_t *emp2  = calloc(1, sizeof(emp_t));
    strncpy(emp2->name, "Abhishek", strlen("Abhishek"));
    emp1->salary = 150000;
    strncpy(emp2->designation, "SE3", strlen("SE3"));
    emp2->emp_id = 32;
    glthread_node_init((&emp2->glnode));

    emp_t *emp3  = calloc(1, sizeof(emp_t));
    strncpy(emp3->name, "Arun", strlen("Arun"));
    emp3->salary = 60000;
    strncpy(emp3->designation, "SE4", strlen("SE4"));
    emp3->emp_id = 27;
    glthread_node_init((&emp3->glnode));


	glthread_t *emp_list = calloc(1, sizeof(glthread_t));
	init_glthread(emp_list, offsetof(emp_t, glnode));

	 glthread_add(emp_list, &emp1->glnode);
    	glthread_add(emp_list, &emp2->glnode);
	glthread_add(emp_list, &emp3->glnode);


	emp_t *ptr = NULL;
	ITERATE_GL_THREADS_BEGIN(emp_list, emp_t, ptr) {
		print_emp_details(ptr);
	} ITERATE_GL_THREADS_ENDS;

	printf("\nAfter removal\n");
	glthread_remove(emp_list);
    ITERATE_GL_THREADS_BEGIN(emp_list, emp_t, ptr){
		print_emp_details(ptr);
    } ITERATE_GL_THREADS_ENDS;

    return 0;


}


