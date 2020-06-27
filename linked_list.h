
typedef struct Element Element;
struct Element{
    int num;
    void* next;

};

typedef struct Array Array;
struct Array{

    void* first;
};

Array *init_linked_list();
Element *new_element(int newNum);
void add_element_first(Array *array, Element *new);
void print_linked_list(Array *array);
void add_element_end(Array *array, Element *new);
void delete_chained_list(Array *array);
void delete_first_element(Array *array);
void delete_last_element(Array *array);
void add_element_at_index(Array *array, int pos, Element *element);
void delete_elements_with_value(Array *array, int value);
int size_list(Array *array);