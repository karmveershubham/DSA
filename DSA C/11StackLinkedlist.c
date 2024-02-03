#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void push(int);
void pop();
void display();



int main(){
    int top=-1,x, choice;
    printf("\n\t STACK OPERATIONS USING LINKED LIST");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf(" Enter a value to be pushed:");
                scanf("%d",&x);
                push(x);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
void push(int value){
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data=value;

    new_node->next=head;
    head=new_node;
}
void pop(){
    if(head==NULL){
        printf("\n\t Stack is under flow");
    }
    else{
        printf("\n\t The popped elements is %d",head->data);
        head=head->next;
    }
}
void display()
{
    if(head==NULL){
        printf("\n The STACK is empty");
       
    }
    else{
        printf("\n The elements in Stack: \n");
        struct node *temp=head;
        while(temp!=NULL){
            printf("%d \n",temp->data);
            temp=temp->next;
        }
        printf("\n Press Next Choice");
    }
   
}