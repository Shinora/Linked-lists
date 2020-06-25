#include <stdio.h>
#include <stdlib.h>
#include "structs.c"



Array *init_linked_list();
void add_element_first(Array *array, int newNum);
void print_linked_list(Array *array);
void add_element_end(Array *array, int NewNum);
void delete_chained_list(Array *array);


int main(){

   
    Array *linked_list = init_linked_list();
    add_element_first(linked_list, 45);
    add_element_first(linked_list, 12);
    add_element_first(linked_list, 35642);
    add_element_first(linked_list, 465);
    add_element_first(linked_list, 7878);
    add_element_first(linked_list, 545);
    add_element_first(linked_list, 1);
    add_element_end(linked_list, 420);
    print_linked_list(linked_list);
    
    return 0;
}

Array* init_linked_list(){

    Array *array = malloc(sizeof(*array));
    Element *element = malloc(sizeof(*element));
    printf("%p  %p \n", array, element);

    if(array == NULL || element == NULL){
        exit(1);

    }

    element->num = 0;
    element->next = NULL;
    array->first = element;

    return array;

}

void add_element_first(Array *array, int newNum){

    Element *new = malloc(sizeof(*new));

    if(array == NULL || new == NULL){
        exit(1);
    }

    new->num = newNum;
    new->next = array->first;
    array->first = new;


}

void add_element_end(Array *array, int newNum){
    Element *new = malloc(sizeof(*new));

    if(array == NULL || new == NULL){
        exit(1);
    }
    
    Element *current = array->first;
    
    while(current!= NULL){
        
        current = current->next;
    }
    
    if(current->next == NULL){
        current->next = new;  // Error comes from here 
    }
    new->num = newNum;
    new->next = NULL;

}



void print_linked_list(Array *array){
    

    if(array == NULL){
        exit(1);
    }
    
    Element *current = array->first;
    
    while(current!= NULL){

        printf("%d ->", current->num);
        current = current->next;
    }
    printf("NULL\n");

}


void delete_chained_list(Array *array){

}

void delete_first_element(Array *array){

}

void delete_last_element(Array *array){

}

void delete_element(Array *array, int element){

}

void delete_value(Array *array, int value){
    // delete a specified value
    // for exemple if value = 4, it will delete every element which value = 4
}

void append_element(Array *array, int pos, int toAppend){

}
