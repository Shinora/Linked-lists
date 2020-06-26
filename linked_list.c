#include <stdio.h>
#include <stdlib.h>
#include "structs.c"



Array *init_linked_list();
Element *new_element(int newNum);
void add_element_first(Array *array, Element *new);
void print_linked_list(Array *array);
void add_element_end(Array *array, Element *new);
void delete_chained_list(Array *array);
void delete_first_element(Array *array);
void delete_last_element(Array *array);


int main(){

   
    Array *linked_list = init_linked_list();
    Element *somelement = new_element(12);
    
    add_element_first(linked_list, somelement);
    Element *otherelem = new_element(8758);
    add_element_first(linked_list, otherelem);
    Element *anotherone = new_element(420);
    add_element_first(linked_list, anotherone);
    //add_element_end(linked_list, anotherone);    NOT WORKING YET
    
    print_linked_list(linked_list);
    delete_first_element(linked_list);
    delete_chained_list(linked_list);
    //delete_last_element(linked_list);  NOT WORKING YET
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

Element* new_element(int newNum){

    Element *new = malloc(sizeof(*new));
    if(new == NULL){
        exit(1);
    }
    new->num = newNum;
    return(new);


}


void add_element_first(Array *array, Element *new){

    
    if(array == NULL || new == NULL){
        exit(1);
    }

    new->next = array->first;
    array->first = new;


}


 void add_element_end(Array *array, Element *new){

    if(array == NULL || new == NULL){
        exit(1);
    }
    
    Element *current = array->first;
    
    while(current!= NULL){
        
        current = current->next;
    }
    
    current = new;
    new->next = NULL;

}

void print_linked_list(Array *array){
    

    if(array == NULL){
        exit(1);
    }
    
    Element *current = array->first;
    
    while(current!= NULL){

        printf("%d -> ", current->num);
        current = current->next;
    }
    printf("NULL\n");

}


void delete_chained_list(Array *array){
    Element *next;

    if(array == NULL){
        exit(1);
    }
    
    while(array->first != NULL){
        delete_first_element(array);


    }

}

void delete_first_element(Array *array){

    if(array == NULL){
        exit(1);
    }

    if(array->first != NULL){
        Element *toDelete = array->first;
        array->first = toDelete->next;
        free(toDelete);
    }

}

void delete_last_element(Array *array){     // WORKING ON IT

    if(array == NULL){
        exit(1);
    }

    Element *current = array->first;
    while(current->next != NULL){
        current = current->next;
    }
    Element *toDelete = current;
    current->next = NULL;
    free(toDelete);

}

void delete_element(Array *array, int element){

}

void delete_elements_with_value(Array *array, int value){
    // delete a specified value
    // for exemple if value = 4, it will delete every element which value = 4
}

void append_element(Array *array, int pos, int toAppend){

}


int size_list(Array *array){

}