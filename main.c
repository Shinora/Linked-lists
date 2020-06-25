#include <stdio.h>
#include <stdlib.h>
#include "structs.c"



Array *init_linked_list();
void add_element_first(Array *array, int newNum);
void print_linked_list(Array *array);
void test_print_linked_list(Array *array);

int main(){

   
    Array *linked_list = init_linked_list();
    add_element_first(linked_list, 45);
    add_element_first(linked_list, 12);
    add_element_first(linked_list, 35642);
    add_element_first(linked_list, 465);
    add_element_first(linked_list, 7878);
    add_element_first(linked_list, 545);
    add_element_first(linked_list, 1);
    test_print_linked_list(linked_list);
    
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

void print_linked_list(Array *array){
    Element *elem = 0;
    Element *element;
    element = array->first;
    elem = element->next;
    printf("%d ", element->num);
    printf("-> ");
    Element *nextaddr = element->next;
    while(elem != NULL){    
        elem = nextaddr->next;
        printf("%d", nextaddr->num);
        printf("-> ");
           
    }
}

void test_print_linked_list(Array *array){
    Element *element;
    Element *nextelem;
    element = array->first;
    
    
    while(element->next != NULL){
        printf("-> ");    
        element = nextelem->next;
        printf("%d", nextelem->num);
        if(element->next == NULL){break;}
        printf("-> ");
        
        nextelem = element->next;
        printf("%d ", element->num);
    
    
    }

}

