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
    int count = 1;
 
    while(temp->link!= head){
        count += 1;
        temp = temp->link;
    }
    return count;
}

void insert_first(int value){

    struct node* new_node = create_node(value);
    if(head==NULL){
        head=new_node;
        head->link=head;
    }else{
        struct node* last=head; 
        while(last->link!=head){
            last=last->link;
        }
        last->link=new_node;
        new_node->link=head;
        //above lines are same as insert last.
        head=new_node;
    }
    
    printf("\nNode with data %d was Inserted\n", value);
    
}

void insert_last(int value){

    struct node* new_node = create_node(value);
    if(head == NULL){
        head=new_node;
        head->link=head;
    }else{
        struct node* last=head; 
        while(last->link!=head){
            last=last->link;
        }
        last->link=new_node;
        new_node->link=head;
    }
     
    printf("\nNode with data %d was Inserted\n", value);
}


void delete_first(){
    if(head == NULL){
        printf("List is Empty.");
        return;
    }
    int data = head->data;
    if(head->link == head)  
    {  
        head = NULL;  
        free(head);     
    }  
 
    struct node* temp = head;
    while(temp -> link != head)  
        temp = temp -> link;   
    temp->link = head->link;  
    free(head);  
    head = temp->link;  
 
    printf("\nNode with data %d was Deleted\n", data);
}

void delete_last(){
    if(head == NULL){
        printf("List is Empty.");
        return;
    }
    if(head->link == head)  {  
        head = NULL;  
        free(head);  
    }  

    struct node* temp = head;
    struct node* prev = NULL;
    int data;
 
    while(temp->link != head){
        prev = temp;
        temp = temp->link;
    }
 
    data = temp->data;
    prev->link=temp->link;
    free(temp);
 
    printf("\nNode with data %d was Deleted\n", data);

}


void print(){
    if(head == NULL){
        printf("Linked List is Empty.\n");
    }else{
        printf("The linked list is: ");
        struct node* temp = head;
        while(temp ->link != head){
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("%d ", temp->data);
    }
    
}


int main(){
    printf("\n\n Circular Linked List \n");
    printf("\n1. Insert a node at beginning");
    printf("\n2. Insert a node at end");
    printf("\n3. Delete a node from beginning");
    printf("\n4. Delete a node from end");
    printf("\n5. Traverse list ");
    printf("\n6. Exit\n");

    
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
                delete_first();
                break;
            case 4:
                delete_last();
                break;
            case 5:
                print();
                break;
            case 6:
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