#include <iostream>
#include "Node.cpp"

using namespace std;

#define DUMMY 0

class LinkedStackQueue
{ 
	private:
	Node *first, *last;
	int getFirstElement()
	{
		if (first->next==NULL)	throw (0);
		Node *t = first -> next;
		first -> next = t -> next;
		int res = t -> data;
		delete t;
		return res;
	}
	int seeFirstElement()
	{
		if (first->next==NULL)	throw (0);
		return first -> next -> data ;
	}
	void set_min_front()
	{
		if(front->next == NULL)
		{
			cout<<"EMPTY";
			return ;
		}
		int min = first->next->data;
		Node *temp_min = first->next;
		Node *idx = first->next;
		for(; idx!= NULL; idx = idx->next)
		{
			if(idx->data < min)
			{
				temp_min = idx;
				min = idx->data;
			}
		}
		// now time for swapping......
		int temp = first-> next ->data;
		first->next ->data = temp_min->data;
		temp_min->data = temp;
	}
public:
	LinkedStackQueue()
	{	
		first = new Node(DUMMY);	
		last = NULL;	
	}
	void push(int d)
	{
		first -> next = new Node (d, first -> next);
	}
	void enqueue(int d)
	{
		if (last == NULL)	first -> next = last = new Node(d);
		else 				last = last -> next = new Node (d);
	}
	int pop(){
		return getFirstElement();
	}
	int dequeue(){
		return getFirstElement();
	}
	int seeTop(){
		return seeFirstElement();
	}
	int seeFirst(){
		return seeFirstElement();
	}
};