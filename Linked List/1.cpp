#include <bits/stdc++.h> 
/****************************************************

    Following is the class structure of the Node class:

    class Node {
    public:
	int data;
	Node *next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
}

*****************************************************/

Node* sortLL(Node* head) 
{
    if(head==NULL)
	{
		return NULL;
	}
	int count0=0;
	int count1=0;
	int count2=0;

	Node*temp=head;
	while(temp!=NULL)
	{
		if(temp->data==0)
		{
			count0++;
		}
		else if(temp->data==1)
		{
			count1++;
		}
		else
		{
			count2++;
		}
		temp=temp->next;
	}

	temp=head;
	while(temp!=NULL && count0--)
	{
		temp->data=0;
		temp=temp->next;
	}
	while(temp!=NULL && count1--)
	{
		temp->data=1;
		temp=temp->next;
	}
	while(temp!=NULL && count2--)
	{
		temp->data=2;
		temp=temp->next;
	}

	return head;
}
