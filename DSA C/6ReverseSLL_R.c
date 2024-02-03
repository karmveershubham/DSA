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

struct node *reverse(struct node *prev, struct node *curr){
    if(curr){
        reverse(curr, curr->next);  
        
        //when you are at yhe end of the list the assign the current next pointer to previous one. 
        //This will change the pointer in reverse direcction
        curr->next=prev;

    }else{
        head= prev;
    }
    return head;
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

    reverse(NULL,head);

    printf("The reversed linked list is:");
    print();


   
}
