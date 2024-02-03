#include<stdio.h>
int queue[100],choice,size,front,rear,val;
void enqueue();
int dequeue(void);
void display(void);

int main(){
    front=-1; rear=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&size);
    printf("\n\t QUEUE OPERATIONS USING CIRCULAR ARRAY");
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

int isFull(){
    if (front==0 && rear == size-1) {
        return 1;
    }
    if (front==rear+1) {
        return 1;
    }
    return 0;
}

int isEmpty(){
    return (front==-1);
}

void enqueue()
{   
    if(isFull()){
        printf("Queue is Full");
    }else{
        printf("Ente the value: ");
        scanf("%d",&val);
        if (front == -1) 
                front = 0;
            rear = (rear + 1) % size;
            queue[rear] = val;
    }
    
}
int dequeue(){   
    if(isEmpty()){
        printf("Queue is Empty.");
    }
    else{
        int val = queue[front];
        if (front == rear) { // Queue has only one element
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        printf("Dequeued Value is: %d", val);
        return val;
    }
}
void display(){
    if (isEmpty())
        printf("Queue is empty \n");
    else
    {
        printf("Queue is:");
        for (int i=front; i != rear; i = (i+1) % size)
            printf("%d ",queue[i]);
        printf("%d \n",queue[rear]);
        
    } 
}