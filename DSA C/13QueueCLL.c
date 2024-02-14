#include<stdio.h>
#include<malloc.h>

//cll implementation.
struct node{
    int data;
    struct node *link;
};

struct node* head = NULL;  //head pointer created

struct node* create_node(int);
void insert_last(int);
void delete_first();
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
        printf("Queue is Empty.");
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
 
    printf("\nNode with data %d was Dequeued\n", data);
}

void print(){
    if(head == NULL){
        printf("Linked List is Empty.\n");
    }else{
        printf("The Queue is: ");
        struct node* temp = head;
        while(temp ->link != head){
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("%d ", temp->data);
    }
    
}

//queue implementation
int choice,val;
void enqueue();
int dequeue(void);
void display(void);

void enqueue(){   
    printf("Ente the value: ");
    scanf("%d",&val);
    insert_last(val);
    
}
int dequeue(){  
    delete_first();
}
void display(){
    print();
}


int main(){
    printf("\n\t QUEUE OPERATIONS USING CIRCULAR LINKED LIST.");
    printf("\n\t 1.ENQUEUE\n\t 2.DEQUEUE\n\t 3.DISPLAY\n\t 4.EXIT");
    do{
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{   
                enqueue();
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                printf("\n\t EXIT POINT ");
                break;
            }
            default:{
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}

