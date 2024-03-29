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
	void deleteNodeFromStart()
	{
		if (first->next!=NULL)
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
	void show()
	{
		if ( first -> next == NULL)
			cout << "List is empty\n";
		for ( Node *t = first -> next ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}

    void delete_negative(void) // No complete...
    {
        for (Node *t = first->next ; t != NULL && t -> data != d1; t = t -> next)
        {
            Node *temp = t -> next;
            if(temp->data < 0)
            {
                t->next = temp -> next;
                delete temp;
            }
        }
    }
};

int main(){
	LinkedList list;
	
	
	return 0;
}