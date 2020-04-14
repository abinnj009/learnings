#include "dll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct person_{
	char name[20];
	int age;
	int weight;
}person_t;

static void print_person_details(person_t *person)
{
	printf("Name:%s\n", person->name);
	printf("Age:%d\n", person->age);
	printf("Weight:%d\n",person->weight);
}

static void print_person_db(dll_t *person_db) 
{
	if(!person_db || !person_db->head) 
		return;
	dll_node_t *head = person_db->head;
	person_t *data = NULL;

	while(head){
		data = head->data;
		print_person_details(data);
		head=head->right;
	}
}

int main(int argc, char **argv)
{
	dll_t *person_db = get_new_dll();
	person_t *person1 = calloc(1,sizeof(person_t));

	strncpy(person1->name,"Abin",strlen("Abin"));
	person1->age = 29;
	person1->weight = 78;

	person_t *person2 = calloc(1,sizeof(person_t));

	strncpy(person2->name, "Albin", strlen("Albin"));
	person2->age = 28;
	person2->weight = 62;

	person_t *person3 = calloc(1,sizeof(person_t));
	
	strncpy(person3->name, "Melbin", strlen("Melbin"));
	person3->age = 30;
	person3->weight = 58;

	add_data_to_dll(person_db, person1);
	add_data_to_dll(person_db, person2);
	add_data_to_dll(person_db, person3);

	print_person_db(person_db);

}

