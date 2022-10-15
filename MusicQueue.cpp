#include<iostream>
#include<conio.h>
using namespace std;

class SLLNode{

    public:
        string info;
        SLLNode *next;

        SLLNode(){
            next=NULL;
        }

        SLLNode(string el){
            info=el; next=NULL;
        }
};

class SLList{
    private:
        SLLNode *head, *tail;
    public:
        SLList(){
            head=tail=NULL;
        }

        int isEmpty(){
            return head==0;
        }
        
        void addToList(string);
        void Traverse();
        string deleteFromList();
        
        
};


void SLList::addToList(string el){
    if(isEmpty()){  
        head=tail=new SLLNode(el);
    }
    else{
        SLLNode *temp = new SLLNode(el);
        tail->next = temp;
        tail=temp;
    }
}

string SLList::deleteFromList(){
    string el=head->info;
    SLLNode *temp=head;
    if(head==tail){
        head=tail=NULL;
    }else{
        head=head->next;
        delete temp;
    }return el;
}

void SLList::Traverse(){
    SLLNode *temp = head;
    if(isEmpty()){
        cout<<"Empty";
    }
    else{
        while(temp!=0){
        cout<<temp->info<<" ";
        temp=temp->next;
        }
    }
}

int main()
{
    SLList l;
    int ch;
	string val;
    cout<<"\n1. Insert song to queue \n";
    cout<<"2. play song from queue \n";
    cout<<"3. Display all songs of queue \n";
    cout<<"4. Quit \n";
    while(1)
    {
        
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch (ch)
        {
            case 1:
                cout<<"Enter song to  insert in queue: "; 
                cin>>val;
                l.addToList(val);
                break;
            case 2:
                if(l.isEmpty())
                    cout<<"Queue Underflow \n";
                else{
                    val=l.deleteFromList();
                    cout<<"The song playing is: "<<val;
                }
                break;
            case 3:
                cout<<"The Queue is: ";
                l.Traverse();
                break;
            case 4:
                return 0;
            default:
                cout<<"Wrong choice \n";
        } 
    } 
    getch();
    return 0;
}



