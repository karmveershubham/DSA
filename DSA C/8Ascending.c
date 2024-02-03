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

int isAscending(struct node * temp){
    int tru=1;
    do{
        if((temp->next->data)<(temp->data)){
            return tru=0;
        };
        temp=temp->next;
    }
    while(temp->next);
    return tru;
    
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
    insert_first(9);
    insert_first(5);
    insert_first(4);
    insert_first(1);
    insert_first(2);

    print();

    if(isAscending(head)){
        printf("The SLL is Non Decreasing");
    }else{
        printf("The SLL is not Non-Decresing");
    }
}
