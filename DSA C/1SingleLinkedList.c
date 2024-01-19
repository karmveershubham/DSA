#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *link;
};

struct node* head = NULL;  //head pointer created

struct node* create_node(int);
void insert_first(int);
void insert_last(int);
void insert_at_position(int,int);
void delete_first();
void delete_last();
void delete_at_position(int);
void print();

struct node* create_node(int value)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    new_node->data = value;
    new_node->link = NULL;
    return new_node;
}
int size_of_list(){
    struct node* temp = head;
    int count = 0;
 
    while(temp != NULL){
        count += 1;
        temp = temp->link;
    }
    return count;
}

void insert_first(int value){
    struct node* new_node = create_node(value);
    new_node->link=head;
    head=new_node;
    printf("\nNode with data %d was Inserted\n", value);
}

void insert_last(int value){
    struct node* new_node = create_node(value);
    if(head == NULL){
        head=new_node;
    }else{
        struct node* last=head; 
        while(last->link!=NULL){
            last=last->link;
        }
        last->link=new_node;
    }
     
    printf("\nNode with data %d was Inserted\n", value);
}

void insert_at_position(int  value,int pos){
    int size=size_of_list();
    
    if(head==NULL && pos==1){
        insert_first(value);
    }else if(pos==size){
        insert_last(value);
    }else if(pos <= 0 || pos > size){
        printf("Invalid Position of Insertion.\n");
    }
    else{
        struct node* new_node = NULL;
        new_node = create_node(value);

        struct node* temp = head;
        int count = 1;
        while(count < pos-1)
        {
            temp = temp -> link;
            count += 1;
        }
        new_node->link = temp->link;
        temp->link = new_node;
    }
    
    
}

void delete_first(){
    if(head == NULL){
        printf("List is Empty.");
        return;
    }
 
    struct node* temp = head;
    int data = head->data;
 
    //move head pointer to the next node to the head
    head = head->link;
    free(temp);
 
    printf("\nNode with data %d was Deleted\n", data);
}
void delete_last(){
    if(head == NULL){
        printf("List is Empty.");
        return;
    }
 
    struct node* temp = head;
    struct node* prev = NULL;
    int data;
 
    while(temp->link != NULL){
        prev = temp;
        temp = temp->link;
    }
 
    data = temp->data;
 
    //if there is only one node
    if(temp == head){
        free(temp);
        head = NULL;
    }
    else{
        free(temp);
        prev->link = NULL;
    }
    printf("\nNode with data %d was Deleted\n", data);

}
void delete_at_position(int pos){
    int size=size_of_list();

    if(pos <= 0 || pos > size){
        printf("\nInvalid position to delete a node\n");
        return;
    }
 
    struct node* temp = head;
    struct node* prev = NULL;
    int count = 1;
 
    while(count < pos){
        prev = temp;
        temp = temp->link;
        count += 1;
    }
 
    int data = temp->data;
 
    if(temp == head){
        head = head->link;
        free(temp);
    }
    else{
        prev->link = temp->link;
        free(temp);
    }
    printf("\nNode with data %d was Deleted\n", data);
}

void print(){
    if(head == NULL){
        printf("Linked List is Empty.\n");
    }
    printf("The linked list is: ");
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
}


int main(){
    printf("\n\n    Singly Linked List \n");
    printf("\n1. Insert a node at beginning");
    printf("\n2. Insert a node at end");
    printf("\n3. Insert a node at given position");
    printf("\n4. Delete a node from beginning");
    printf("\n5. Delete a node from end");
    printf("\n6. Delete a node from given position");
    printf("\n7. Traverse list ");
    printf("\n8. Exit\n");

    
    char choice='y';
    int option;
    int data,position;

    while(choice =='y'||choice =='Y'){
        printf("Enter an option:\t");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter Value.\t");
                scanf("%d",&data);
                insert_first(data);
                break;
            
            case 2: 
                printf("Enter Value.\t");
                scanf("%d",&data);
                insert_last(data);
                break;

            case 3:
                printf("Enter Value and position.\t");
                scanf("%d %d", &data, &position);
                insert_at_position(data, position);
                break;
            
            case 4:
                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                printf("Enter Position:\t");
                scanf("%d", &position);
                delete_at_position(position);
                break;
            case 7:
                print();
                break;
            case 8:
                printf("program Terminated\n");
                return 0;

            default:
                printf("\nInvalid choice\n");
        }
        printf("\nDo you want to continue? \t");
        while ((getchar()) != '\n');    //used to clear buffer inputs for characters. Alernative of fflush(stdin):
        scanf("%c", &choice);
    }
    return 0;
}
