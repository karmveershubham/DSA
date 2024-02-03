#include<stdio.h>
#include<stdlib.h>
 
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
 
struct node* head = NULL;
 
/* functions prototyping */
void insert_at_beginning(int);
void insert_at_end(int);
void insert_at_position(int, int);
void delete_from_beginning();
void delete_from_position(int);
void delete_from_end();
void traverse();

/* helper functions */
struct node* create_node(int);
int size_of_list();
int getData();
int getPosition();
 
int main(){
    char user_active = 'Y';
    int user_choice;
    int data, position;
 
    while (user_active == 'Y' || user_active == 'y'){
 
        printf("\n\n        Doubly Linked List       \n");
        printf("\n1. Insert a node at the beginning");
        printf("\n2. Insert a node at the end");
        printf("\n3. Insert a node at the given position");
        printf("\n\n4. Delete a node from the beginning");
        printf("\n5. Delete a node from the end");
        printf("\n6. Delete a node from the given position");
        printf("\n\n7. Print list from the beginning");
        printf("\n8. Exit");
 
        printf("\nEnter your choice: ");
        scanf("%d", &user_choice);
 
        switch(user_choice){
            case 1:
                printf("\nInserting a node at beginning");
                data = getData();
                insert_at_beginning(data);
                break;
 
            case 2:
                printf("\nInserting a node at end");
                data = getData();
                insert_at_end(data);
                break;
 
            case 3: 
                printf("\nInserting a node at the given position");
                data = getData();
                position = getPosition();
                insert_at_position(data, position);
                break;
 
            case 4: 
                printf("\nDeleting a node from beginning\n");
                delete_from_beginning();
                break;
 
            case 5: 
                printf("\nDeleting a node from end\n");
                delete_from_end();
                break;
 
            case 6: 
                printf("\nDelete a node from given position\n");
                position = getPosition();
                delete_from_position(position);
                break;
 
            case 7: 
                printf("\nPrinting the list from beginning\n\n");
                traverse();
                break;
 
            case 8:
                printf("\nProgram was terminated\n\n");
                return 0;
 
            default:
                printf("\n\tInvalid Choice\n");
        }
 
        printf("\n...............................\n");
        printf("\nDo you want to continue? (Y/N) : ");
        fflush(stdin);
        scanf(" %c", &user_active);
    }
 
    return 0;    
}
 

struct node* create_node(int data){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    if (new_node == NULL){
        return NULL;
    }
    else{
        new_node->prev = NULL;
        new_node->data = data;
        new_node->next = NULL;
    }
}
 
void insert_at_beginning(int data){
    struct node* new_node = create_node(data);
    if(head == NULL){
        head = new_node;
    }
    else{
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
    printf("\n* Node with data %d was inserted \n", data);
}
 
void insert_at_end(int data){
    struct node* new_node = create_node(data);
 
    if (head == NULL){
        head = new_node;
    }
    else{
        struct node* temp = head;
        //traverse to the last node
        while (temp->next != NULL){
            temp = temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    printf("\n* Node with data %d was inserted \n", data);
}
 
void insert_at_position(int data, int pos){
    struct node* new_node = create_node(data);
    int size = size_of_list();
 
    if (head != NULL && (pos < 1 || pos > size)){
        printf("\nInvalid position!\n");
        return;
    }
    else if (head == NULL && pos == 1){
        head = new_node;
    }
    else if (head != NULL && pos == 1){
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else{
 
        struct node* temp = head;
        int count = 1;
 
        //traverse to the before given position
        while (++count < pos){
            temp = temp->next;
        }
 
        temp->next->prev = new_node;
        new_node->next = temp->next;
 
        temp->next = new_node;
        new_node->prev = temp;
    }
    printf("\n* Node with data %d was inserted \n", data);
}
 
void delete_from_beginning(){
    if (head == NULL){
        printf("\nList is Empty!\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    int data = temp->data;

    //free the memory from the heap
    free(temp);
 
    printf("\n* Node with data %d was deleted \n", data);
}
 
/* deletes a node from the end of the list */
void delete_from_end(){
 
    if (head == NULL){
        printf("\nList is Empty!\n");
        return;
    }
    struct node* temp = head;
    int data = 0;
 
    while (temp->next != NULL){
        temp = temp->next;
    }
 
    if (temp->prev == NULL){
        head = NULL;
    }
    else{
        temp->prev->next = temp->next;
    }
    data = temp->data;
 
    free(temp);
    printf("\n* Node with data %d was deleted \n", data);
}
 
/* deletes a node from the given position */
void delete_from_position(int pos){
 
    if (head == NULL){
        printf("\nList is Empty!\n");
        return;
    }
    int size = size_of_list();
    struct node* temp = head;
    int data = 0;
 
    if (pos < 1 || pos > size){
        printf("\nInvalid position!\n");
        return;
    }
    else if (pos == 1){
        head = head->next;
        data = head->data;
        free(temp);
        printf("\n* Node with data %d was deleted \n", data);
    }
    else{
        int count = 0;

        while (++count < pos){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (pos != size){
            temp->next->prev = temp->prev;
        }
        data = temp->data;
        free(temp);
        printf("\n* Node with data %d was deleted \n", data);
    }
}
 
void traverse(){
    struct node* temp = head;
 
    while (temp != NULL){
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
 
int getData(){
    int data;
    printf("\n\nEnter Data: ");
    scanf("%d", &data);
 
    return data;
}
 
int getPosition(){
    int position;
    printf("\nEnter Position: ");
    scanf("%d", &position);
 
    return position;
}
 

int size_of_list(){
    struct node* temp = head;
    int count = 0;
 
    while (temp != NULL){
        count += 1;
        temp = temp->next;    
    }
 
    return count;
}