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


void printSLLRecursion(struct node *p){
    if(p){
        printf("%d ", p->data);
        printSLLRecursion(p->next);
    }
    
}

int main(){
    insert_first(5);
    insert_first(8);
    insert_first(1);
    insert_first(3);
    insert_first(9);

    printf("The linked list is: ");
    printSLLRecursion(head);

   
}
