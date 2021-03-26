#include <iostream>
#include "Node.cpp"

using namespace std;

#define DUMMY 0

class LinkedList
{
	Node *first, *last;
	int count;
public:
	LinkedList()
	{	
		first = new Node(DUMMY);
		count = 0;	
		last = NULL;	
	}
	void addNodeAtStart(int d)
	{
		
		Node *newNode = new Node(d);
		newNode -> next = first -> next;
		first -> next = newNode;
		if (last == NULL)	last = newNode;
		count++;
		first->data = count;
	}
	void addNodeAtEnd(int d)
	{
		if (last == NULL)	addNodeAtStart(d);
		else
		{
			last -> next = new Node(d);
			last = last -> next;
		}
		count++;
		first->data = count;
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
		count++;
		first->data = count;
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
		count--;
		first->data = count;
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
		count--;
		first->data = count;
	}
    void pair_show()
	{
		if ( first -> next == NULL)
			cout << "List is empty\n";
		for ( Node *t = first -> next ; t != NULL ; t = t -> next )
            {
			    cout << t -> data << ' '<< t -> next->data <<'\n';
            }
		cout << '\n' ;
	}
};

int main(){
	LinkedList list;
	list.addNodeAtStart(23);
	list.addNodeAtEnd(59);
    list.addNodeAtEnd(37);
    list.addNodeAtEnd(46);
	list.addNodeAtEnd(66);
	list.addNodeAtEnd(29);
    list.pair_show();
	return 0;
}