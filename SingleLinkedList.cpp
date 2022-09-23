#include<iostream>
#include<conio.h>

using namespace std;

class SLLNode{

    public:
        int info;
        SLLNode *next;

        SLLNode(){
            next=NULL;
        }

        SLLNode(int el){
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
        int size(){
            int size=0;
            SLLNode *temp=head;
            while(temp!=NULL){
                temp=temp->next;
                ++size;
            }
            return size;
        }
        void addToHead(int);
        void addToTail(int);
        void insertNode(int,int);
        void Traverse();
        void reverse();
        int deleteFromHead();
        int deleteFromTail();
        int deleteNode(int);
        int search(int);
        
};

int SLList::search(int val){
	SLLNode * temp=head;
	int count=1;
	while(temp!=NULL){
		if(temp->info==val)
		{
			return count;
		}
		count++;
		temp=temp->next;
	}
	return -1;		
} 

void SLList::reverse(){
	SLLNode* pre=NULL;
	SLLNode* curr=head;
    SLLNode* temp=head;
	SLLNode* forw;
	while(curr!=NULL){
		forw=curr->next;
		curr->next=pre;
		pre=curr;
		curr=forw;
	}
	head=pre;	
    tail=temp;	
}
void SLList::addToHead(int el){
    if(isEmpty()){
        head=tail=new SLLNode(el);
    }
    else{
        SLLNode *temp = new SLLNode(el);
        temp->next=head;
        head=temp;
    }
        
}

void SLList::addToTail(int el){
    if(isEmpty()){   //if list is not empty it means there is only one node is present which is head.
        head=tail=new SLLNode(el);
    }
    else{
        SLLNode *temp = new SLLNode(el);
        tail->next = temp;
        tail=temp;
    }
}

void SLList::insertNode(int pos,int el){  //el= element inserted in info  val= node value in list after which we insert element.
        int len=size();
        SLLNode *prev=NULL,*cur=head;
        if(pos<=0){
            cout<<"Invalid Position\n";
        }else if (pos==1){
            addToHead(el);
		}
		else if(pos==len+1 && pos!=1){
            addToTail(el);
        }
        else if(len>1 && pos<=len){
            int count=1;
            while(count!=pos)
            {
                prev=cur;
                cur=cur->next;
                count++;
            }
            if(count==pos)
            {   
                SLLNode *temp=new SLLNode(el);
                prev->next=temp;
                temp->next=cur;
            }
        }
        else
            cout<<"\nPosition out of List.\n";
}
int SLList::deleteFromHead(){
    int el=head->info;
    SLLNode *temp=head;
    if(head==tail){
        head=tail=NULL;
    }else{
        head=head->next;
        delete temp;
    }return el;
}
int SLList::deleteFromTail(){
    int el=tail->info;
    if(head==tail){
        head=tail=NULL;
    }else{
        SLLNode *temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
    }
    return el;
}

void SLList::Traverse(){
    SLLNode *temp = head;
    if(isEmpty()){
        cout<<"List is Empty";
    }
    else{
        while(temp!=0){
        cout<<temp->info<<" -> ";
        temp=temp->next;
        }
        cout<<"NULL";
    }
}

int SLList::deleteNode(int pos){
    if(head != NULL){
        if(pos==1){
            deleteFromHead();
        }
        else if(pos==size()){  //for tail 
            deleteFromTail();

        }else if(pos>1 and pos<size()){
            SLLNode *temp=head;
            
            for(int i=2; temp!=NULL&&i<pos;i++){
                temp=temp->next;
            }
            if(temp==NULL||temp->next==NULL){
                return -1;
            }
            SLLNode *next=temp->next->next;
            int val=temp->next->info;
            temp->next=next;
            return val;

        }else{
            cout<<"Position out of List.\n";
            return -1;
        }
    }else{
        cout<<"List is Empty"<<endl;
    }
}

int main()
{
    SLList l;
    int ch;
    cout<<"\n**** MENU ****";
    cout<<"\n1:Add to Head 2:Add to tail 3.Insert Node 4.Delete from Head \n5.Delete from Tail 6.Delete Node 7.Display 8.Search 9. Reverse 10:EXIT\n";
    while(1)
    {
        cout<<"\nEnter Your Choice: ";
        cin>>ch;
        int el,pos;
        switch(ch)
        {           
        case 1:{
            cout<<"Enter element: ";
            cin>>el;
            l.addToHead(el);
            l.Traverse();
            break;
        }
        case 2:{
            cout<<"Enter element: ";
            cin>>el;
            l.addToTail(el);l.Traverse();
            break;
        }
        case 3:{
            cout<<"Enter position and element: ";
            cin>>pos>>el;
            l.insertNode(pos,el);l.Traverse();
            break;
            }
        case 4:{
            if(!l.isEmpty()){
                int val=l.deleteFromHead(); 
                cout<<"Deleted element is: "<<val<<endl;	
            }
            l.Traverse();
            break;
        }
            
            
        case 5:{
            if(!l.isEmpty()){
                int val=l.deleteFromTail(); 
                cout<<"Deleted element is: "<<val<<endl;
            }
            l.Traverse();
            break;
        }
        
        case 6:{
            if(!l.isEmpty()){
                cout<<"Enter pos: ";
                cin>>pos;
                int val=l.deleteNode(pos);
                if(val!=-1)
                cout<<"Deleted element is: "<<val<<endl;
            }
            l.Traverse();
            break;	
        }
            
        case 7:{
            cout<<"Element in the list: ";
            l.Traverse();
            break;
        }
            
        case 8:{
            if(!l.isEmpty()){
                cout<<"Enter element: ";
                cin>>el;
                int in= l.search(el);
                if(in==-1){
                    cout<<"Element not found\n";
                }else{
                    cout<<el<<" is at position "<<in<<endl;
                }
            }
            l.Traverse();
            break;  
        }
        case 9:{
            l.reverse();
            cout<<"Reversed list is: ";
            l.Traverse();
            break;
        }     
        case 10:
            return 0;
            
        }
    }
    return 0;
    }


