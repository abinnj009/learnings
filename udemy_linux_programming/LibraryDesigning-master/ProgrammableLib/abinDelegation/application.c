#include "dll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
typedef struct student_{
	char name[32];
	int age;
	int weight;
	unsigned int rollno;
}student_t;

static void print_student_details(student_t *student)
{
	printf("name: %s\n", student->name);
	printf("age:%d\n", student->age);
	printf("weight:%d\n", student->weight);
	printf("rollno:%u\n", student->rollno);
}

static void print_student_db(dll_t *student_db)
{
	if(!student_db || !student_db->head) return;

	dll_node_t *head = student_db->head;
	student_t *data = NULL;
	while(head){
		data = head->data;
		print_student_details(data);
		head = head->right;
	}
}

typedef struct employee_{
	char name[32];
	char designation[32];
	unsigned int salary;
	unsigned int emp_id;
} employee_t;

static void print_emp_details(employee_t *emp)
{
	printf("name:%s\n", emp->name);
	printf("designation:%s\n", emp->designation);
	printf("salary:%u\n", emp->salary);
	printf("employee ID:%u\n", emp->emp_id);
}

static void print_emp_db(dll_t *emp_db)
{
	if(!emp_db || !emp_db->head) return;

	dll_node_t *head = emp_db->head;
	employee_t *data = NULL;
	while(head) {
		data = head->data;
		print_emp_details(data);
		head = head->right;
	}
}


static int student_comparison_fn(void *stud1, void *stud2)
{
	student_t *student1 = (student_t *)stud1;
	student_t *student2 = (student_t *)stud2;

	if(strncmp(student1->name, student2->name, 32) < 0)
		return -1;
	else if(strncmp(student1->name, student2->name, 32) > 0)
		return 1;
	else if(student1->age < student2->age)
		return -1;
	else if(student1->age > student2->age)
		return 1;
	else if(student1->weight < student2->age)
		return -1;
	else if(student1->weight > student2->age)
		return 1;
	else if(student1->rollno < student2->rollno)
		return -1;
	else if(student1->rollno > student2->rollno)
		return 1;
	assert(0);
}


student_t * search_student_by_rollno(dll_t *student_db, unsigned int rollno)
{
	if(!student_db || !student_db->head) return NULL;

	dll_node_t *head = student_db->head;
	student_t *data = NULL;

	while(head) {
		data = head->data;
		if(data->rollno == rollno)
			return data;
		head = head->right;
	}
}


employee_t * search_employee_by_emp_id(dll_t *emp_db, unsigned int emp_id)
{
	if(!emp_db || !emp_db->head) return NULL;

	dll_node_t *head = emp_db->head;
	employee_t *data = NULL;
	while(head) {
		data = head->data;
		if(data->emp_id == emp_id)
			return data;
		head = head->right;
	}
}


static int search_student_db_by_key(void *data, void *key)
{
	student_t *student = (student_t *) data;
	unsigned int rollno = (unsigned int)key;

	if(student->rollno == rollno)
		return 0;
	return -1;
}

static int search_employee_db_by_key(void *data, void *key)
{
	employee_t *emp = (employee_t *)data;
	unsigned int emp_id = (unsigned int) key;
	if(emp->emp_id == emp_id)
		return 0;
	return -1;
}

int main(int argc , char **argv) 
{

	student_t *student1 = calloc(1, sizeof(student_t));
	strncpy(student1->name, "Abin", strlen("Abin"));
	student1->age = 29;
	student1->weight = 75;
	student1->rollno = 800000;

	student_t *student2 = calloc(1, sizeof(student_t));
	strncpy(student2->name, "Joseph", strlen("Joseph"));
	student2->age = 41;
	student2->weight = 70;
	student2->rollno = 800400;

	student_t *student3 = calloc(1, sizeof(student_t));
	strncpy(student3->name, "Jack", strlen("Jack"));
	student3->age = 29;
	student3->weight = 55;
	student3->rollno = 800400;

	student_t *student4 = calloc(1, sizeof(student_t));
	strncpy(student4->name, "Abhishek", strlen("Abhishek"));
	student4->age = 30;
	student4->weight = 55;
	student4->rollno = 800399;

	dll_t *student_db = get_new_dll();
	register_key_match_callback(student_db, search_student_db_by_key);
	register_comparison_callback(student_db, student_comparison_fn);


	dll_priority_insert_data(student_db, student1);
	dll_priority_insert_data(student_db, student2);
	dll_priority_insert_data(student_db, student3);
	dll_priority_insert_data(student_db, student4);

	dll_node_t *node_ptr = NULL;
	student_t *data = NULL;

	ITERATIVE_LIST_BEGIN(student_db, node_ptr){
		data = node_ptr->data;
		print_student_details(data);
	} ITERATIVE_LIST_END;
#if 0
	print_student_db(student_db);
	//student_t *student = search_student_by_rollno(student_db, 800400);
	student_t * student = (student_t *)dll_search_by_key(student_db, (void *)800400);
	
	if(!student)
		printf("Student record not found\n");
	else
		print_student_details(student);

#endif	
	
	
	employee_t *employee1 = calloc(1, sizeof(employee_t));
	strncpy(employee1->name, "Harsh", strlen("Harsh"));
	strncpy(employee1->designation, "Vice President", 
			strlen("Vice President"));
	employee1->salary = 11131;
	employee1->emp_id = 10000;

	employee_t *employee2 = calloc(1, sizeof(employee_t));
	strncpy(employee2->name, "Huma", strlen("Huma"));
	strncpy(employee2->designation, "CEO", strlen("CEO"));
	employee2->salary = 127000;
	employee2->emp_id = 10001;

	employee_t *employee3 = calloc(1, sizeof(employee_t));
	strncpy(employee3->name, "Neena", strlen("Neena"));
	strncpy(employee3->designation, "Manager", strlen("Manager"));
	employee3->salary = 139000;
	employee3->emp_id = 10002;


	dll_t *emp_db = get_new_dll();
	register_key_match_callback(emp_db, search_employee_db_by_key);

	add_data_to_dll(emp_db, employee1);
	add_data_to_dll(emp_db, employee2);
	add_data_to_dll(emp_db, employee3);
#if 0
	print_student_db(student_db);

	//employee_t *emp = search_employee_by_emp_id(emp_db, 10002);
	employee_t *emp = (employee_t *) dll_search_by_key(emp_db, (void *)10002);
	if(!emp) {
		printf("Employee record not found\n");
	}
	else
		print_emp_details(emp);
	return 0;
#endif
}


