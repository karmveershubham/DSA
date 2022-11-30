// Insert at index in dll

void DLL::delFromPos(int pos)
{
  int cnt=count();
	Node* temp=head;
	Node* before=NULL;
	if(isempty())
	{
		cout<<"UNDERFLOW"<<endl;
	}
	else 
	{
		if(pos==1)
		{
			delFromHead();
		}
		else if(pos>cnt)
		{
			cout<<"the index entered is invalid"<<endl;
		}
		else
		{
			while(pos>1)
			{
				temp=temp->next;
				pos--;
			}
			before=temp->prev;
			before->next=temp->next;
			temp->next->prev=before;
			delete temp;
			temp=NULL;
	   }
	}
}

// reverse  SLL by recursion
void reverse(Node *head, Node*curr, Node*pre){
	if(curr==Null)
	{
		head=prev;
	 	return;
	}
	Node * forward=curr->next;
	reverse(head,forward,curr);
	curr->next=prev;
}

// reverse SLL by recursion


