#include<stdio.h>
#include<stdlib.h>


struct ListNode
{
    int value;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

typedef struct
{
    ListNode *head;
    
} List;

List * fill_list(List *, int *, int);
int get_list_item(List *, int);
void add_list_item(List *, int);
int remove_list_item(List *, int);
void extend_list(List *, List*);

List * fill_list(List * new_list, int array[], int elements_count){
    if (new_list->head != NULL)
    {
        printf("List is already created\n");
        exit(1);
    }
    
    new_list->head = NULL;

    ListNode * last_node;
    int * current_element = array;


    for (int i = 0; i < elements_count; i++)
    {
        ListNode *new_node = (struct ListNode*) malloc(sizeof(ListNode));
        new_node->value = *current_element;
        new_node->next = NULL;

        if(i == 0){
            new_list->head = new_node;
        } else
        {
            last_node->next = new_node;
        }
        
        last_node = new_node;
        current_element++;
    }
    
    return new_list;

}

int get_list_item(List * list, int index){
    ListNode * current_item = list->head;

    if (current_item == NULL)
        {
            printf("\nList index out of range\n");
            exit(1);
        }

    
    for (int i = 0; i < index; i++)
    {
        if (current_item->next == NULL)
        {
            printf("\nList index out of range\n");
            exit(1);
        }
        

        current_item = current_item->next;
    }

    return current_item->value;
}

void add_list_item(List * list, int value){
    ListNode * current_item = list->head;

    ListNode * new_node = (ListNode *) malloc(sizeof(ListNode));
    if (new_node == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed!\n");
        return;
    }

    new_node->value = value;
    new_node->next = NULL;

    if (current_item == NULL) {
        list->head = new_node;
        return;
    }

    while (current_item->next != NULL) {
        current_item = current_item->next;
    }

    current_item->next = new_node;
}

int remove_list_item(List * list, int index){
    ListNode * previous_item = NULL;
    ListNode * current_item = list->head;
    ListNode * next_item = current_item->next;

    if (current_item == NULL)
    {
        printf("List index out of range");
        exit(1);
    }
    
    int current_item_index = 0;
    while (current_item != NULL && current_item_index < index)
    {
        previous_item = current_item;
        current_item = current_item->next;
        next_item = current_item->next;
        current_item_index++;
    }

    if (current_item == NULL || current_item_index != index)
    {
        printf("List index out of range");
        exit(1);
    }


    if (previous_item != NULL)
    {
        previous_item->next = next_item;
    } else {
        list->head = next_item;
    }
    
    int current_item_value = current_item->value;
    free(current_item);

    return current_item_value;
}


void extend_list(List * list_to_extend, List* extending_list){
    ListNode * current_item = list_to_extend->head;
    ListNode * extending_list_current_item = extending_list->head;

    while (current_item->next != NULL)
    {
        current_item = current_item->next;
    }

    while (extending_list_current_item != NULL)
    {
        ListNode * new_item = (ListNode *) malloc(sizeof(ListNode));
        new_item->next = NULL;
        new_item->value = extending_list_current_item->value;
        current_item->next = new_item;

        extending_list_current_item = extending_list_current_item->next;
        current_item = current_item->next;
    }
    
}