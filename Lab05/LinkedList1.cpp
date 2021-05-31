#include <iostream>
#include<vector>
#include "Node.cpp"

using namespace std;

#define DUMMY 0

class LinkedList
{
	Node *first, *last;
public:
	LinkedList()
	{	
		first = new Node(DUMMY);	
		last = NULL;	
	}
	void addNodeAtStart(int d)
	{
		Node *newNode = new Node(d);
		newNode -> next = first -> next;
		first -> next = newNode;
		if (last == NULL)	last = newNode;
	}
	void addNodeAtEnd(int d)
	{
		if (last == NULL)	addNodeAtStart(d);
		else
		{
			last -> next = new Node(d);
			last = last -> next;
		}
	}
	void addNodeAfter(int d1, int d2)
	{
		Node *t;
		for (t = first->next ; t != NULL && t -> data != d1; t = t -> next);
		if (t != NULL)
		{
			Node *newNode = new Node(d2);
			newNode -> next = t -> next;
			t -> next = newNode;
			if (t == last)	last = newNode;
		}
	}
	void cake(int d1, int d2)
	{
		Node *idx;
		for(idx = first->next; idx != NULL; idx = idx ->next)
		{
			if(idx -> data == d1)
			{
				Node *newNode = new Node(d2);
				newNode -> next = idx -> next;
				idx -> next = newNode;
				if(idx == last)	
					last = newNode;
				break;
			}
		}
	}
	void deleteNodeFromStart()
	{
		if (last!=NULL)
		{
			Node *t = first -> next;
			first -> next = t -> next; //t->next may be second node or NULL
			delete t;
			if (first -> next == NULL)		last = NULL;
		}
	}
	void deleteNodeFromEnd()
	{
		if (last!=NULL)
		{
			if (first -> next == last)		deleteNodeFromStart();						
			else{
				Node *t = first;
				for ( ; t->next != last; t = t -> next );//Move to second last node
				delete t->next;
				t->next = NULL;
				last = t;
			}
		}
	}
	string occurence_twice()
	{
		for(Node *idx = first -> next, int count = 1 ; idx != NULL ; idx = idx -> next, count++)
		{
			for(Node *kdx = idx -> next, int k_count = count + 1; kdx != NULL ; kdx = kdx->next, k_count++)
				if(kdx->data == idx->data)
				{
					cout<<count<<' '<<k_count;
					return "done";
				}
		}
		return "Does not exist";
	}
	void show()
	{
		if ( last == NULL)
			cout << "List is empty\n";
		for ( Node *t = first -> next ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
};

int main(){
	LinkedList list;
	list.addNodeAtStart(23);
	list.addNodeAtEnd(23);
	list.addNodeAtEnd(50);
	list.addNodeAtEnd(60);
	list.addNodeAtEnd(58);
	list.show();
	list.cake(60, 68);
	list.cake(68, 98);
	list.show();
	return 0;
}