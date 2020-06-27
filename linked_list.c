#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int main(){

   
    Array *linked_list = init_linked_list();
    add_element_end(linked_list, new_element(51));
    print_linked_list(linked_list);
    
    add_element_first(linked_list, new_element(12));
    add_element_first(linked_list, new_element(125));
    add_element_first(linked_list, new_element(420));

    add_element_end(linked_list, new_element(636));

    print_linked_list(linked_list);

    size_list(linked_list);

    delete_first_element(linked_list);

    delete_chained_list(linked_list);

    //delete_last_element(linked_list);  NOT WORKING YET
    print_linked_list(linked_list);

    size_list(linked_list);
    
    return 0;
}

Array* init_linked_list(){

    Array *array = malloc(sizeof(*array));
    printf("%p  \n", array);

    if(array == NULL){
        exit(1);

    }

    array->first = NULL;

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

    if (array == NULL || new == NULL) {
        exit(1);
    }
    if (array->first == NULL) {
        array->first = new;
        new->next = NULL;
        return;
    }

    Element *current = array->first;
    while(current->next!= NULL){
        current = current->next;
    }
    current->next = new;
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

    if(current == NULL){
        return;
    }
    while(current->next != NULL){
        current = current->next;
    }
    Element *toDelete = current;
    current->next = NULL;
    free(toDelete);

}


void delete_elements_with_value(Array *array, int value){
    // delete a specified value
    // for exemple if value = 4, it will delete every element which value = 4
}

void add_element_at_index(Array *array, int pos, Element *element){

}


int size_list(Array *array){

    int size = 0;
    if(array == NULL){
        exit(1);
    }

    Element *current = array->first;
    while(current != NULL){
        current = current->next;
        size++;
    }

    printf("%d \n", size);

    return(size);





}