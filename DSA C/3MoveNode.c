#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* head=NULL;

void insert_first(int value){
    struct node* new_node =  (struct node*) malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=head;
    head=new_node;
    printf("\nNode with data %d was Inserted\n", value);
}

void moveNode(){
    if(head==NULL||head->next==NULL){
        return;
    }
    struct node *temp=head;
    
    while(temp->next->next){
       temp=temp->next;
    }
    struct node* new_node =  (struct node*) malloc(sizeof(struct node));
    new_node->data=temp->next->data;
    temp->next=NULL;
    new_node->next=head;
    head=new_node;
    printf("\nLast Node is Moved to First\n");

}

void print(){
    if(head == NULL){
        printf("Linked List is Empty.\n");
    }
    printf("The linked list is: ");
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    insert_first(5);
    insert_first(8);
    insert_first(1);
    insert_first(3);
    insert_first(9);

    print();

    //function called
    
    moveNode();

    print();
}
