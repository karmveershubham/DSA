#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Node
{
public:
    int info;
    Node* next;
};
class List:public Node
{

    Node *first,*last;
public:
    List()
    {
        first=NULL;
        last=NULL;
    }
    void create();
    void insert();
    void remove();
    void display();
    void search();
};
void List::create()
{
    Node *temp;
    temp=new Node;
    int n;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=first;
    }
    else
    {
        last->next=temp;
        last=temp;
    }
}
void List::insert()
{
    Node *prev,*cur;
    prev=NULL;
    cur=first;
    int count=1,pos,ch,n;
    Node *temp=new Node;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    cout<<"\nINSERT AS\n1:FIRSTNODE  2:LASTNODE  3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        temp->next=first;
        first=temp;
        break;
    case 2:
        last->next=temp;
        last=temp;
        break;
    case 3:
        cout<<"\nEnter the Position to Insert:";
        cin>>pos;

        int size=0;
        Node *temp1=first;
        while(temp1!=NULL){
            temp1=temp1->next;
            size++;
        }
        if(pos>0 && pos<=size){
            while(count!=pos)
            {
                prev=cur;
                cur=cur->next;
                count++;
            }
            if(count==pos)
            {
                prev->next=temp;
                temp->next=cur;
            }
        }
        else
            cout<<"\nNot Able to Insert\n";
        break;

    }
}
void List::remove()
{
    Node *prev=NULL,*cur=first;
    int count=1,pos,ch;
    cout<<"\nDELETE\n1:FIRSTNODE 2:LASTNODE 3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        if(first!=NULL)
        {
            cout<<"\nDeleted Element is "<<first->info<<endl;
            first=first->next;
        }
        else
            cout<<"\nNot Able to Delete\n";
        break;
    case 2:
        while(cur!=last)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==last)
        {
            cout<<"\nDeleted Element is: "<<cur->info<<endl;
            prev->next=NULL;
            last=prev;
        }
        else
            cout<<"\nNot Able to Delete\n";
        break;
    case 3:
        cout<<"\nEnter the Position of Deletion:";
        cin>>pos;

        int size=0;
        Node *temp1=first;
        while(temp1!=NULL){
            temp1=temp1->next;
            size++;
        }
        if(pos>0 && pos<=size){
            while(count!=pos)
            {
                prev=cur;
                cur=cur->next;
                count++;
            }
            if(count==pos)
            {
                cout<<"\nDeleted Element is: "<<cur->info<<endl;
                prev->next=cur->next;
            }
        }
        else
            cout<<"\nNot Able to Delete\n";
        break;
    }
}
void List::display()
{
    Node *temp=first;
    if(temp==NULL)
    {
        cout<<"\nList is Empty\n";
    }
    while(temp!=NULL)
    {
        cout<<temp->info;
        cout<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}
void List::search()
{
    int value,pos=0;
    bool flag=false;
    if(first==NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    cout<<"Enter the Value to be Searched:";
    cin>>value;
    Node *temp;
    temp=first;
    while(temp!=NULL)
    {
        pos++;
        if(temp->info==value)
        {
            flag=true;
            cout<<"Element "<<value<<" is Found at "<<pos<<" Position\n";
            return;
        }
        temp=temp->next;
    }
    if(!flag)
    {
        cout<<"Element "<<value<<" not Found in the List\n";
    }
}
int main()
{
    List l;
    int ch;
    cout<<"\n**** MENU ****";
        cout<<"\n1:CREATE 2:INSERT 3:DELETE 4:SEARCH 5:DISPLAY 6:EXIT\n";
    while(1)
    {
        cout<<"\n\nEnter Your Choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            l.create();
            l.display();
            break;
        case 2:
            l.insert();
            l.display();
            break;
        case 3:
            l.remove();
            l.display();
            break;
        case 4:
            l.search();
            break;
        case 5:
            l.display();
            break;
        case 6:
            return 0;
        }
    }
    getch();
    return 0;
}
