#include <iostream>
#include<vector>
#include<algorithm>
#include "Node.cpp"

using namespace std;

#define DUMMY 0

class LinkedList
{
	Node *first, *last;
public:
	LinkedList(){	
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
		else{
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

    bool palindrome_check(void)
	{
        vector<int> main_data;
        vector<int> reverse_data;

        if ( first -> next == NULL)
			return true;
		
        for ( Node *t = first -> next ; t != NULL ; t = t -> next )
			main_data.push_back(t -> data);
        
        reverse_data = main_data;
        reverse(reverse_data.begin(), reverse_data.end());
        
        if (reverse_data == main_data)
            return true;
        
        return false;     
    }
};

int main(){
	LinkedList list;
	list.addNodeAtStart(1);
	list.addNodeAtEnd(0);
	list.addNodeAtEnd(1);

	if(list.palindrome_check())
        cout<<"Yes";
    else
        cout<<"No";
	return 0;
}