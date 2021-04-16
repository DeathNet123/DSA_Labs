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
int main()
{
	LinkedStackQueue stackqueue;
	LinkedStackQueue last_print;

	/*Task 1...
	A large array of integers contains lists inside. Lists have positive integers and -1 indicates separators
	in between the lists. There must exist -1 at start and end of the array. You are required to print
	these lists in reverse order that is start printing from last list, but you have to print each list from
	start to end. See example carefully:
	Array has two lists:
	-1 23 59 37 -1 46 64 -1
	Output:
	46 64
	23 59 37*/

	//Pushing the values inside the stack..
	stackqueue.push(-1);
	stackqueue.push(23);
	stackqueue.push(59);
	stackqueue.push(37);
	stackqueue.push(-1);
	stackqueue.push(47);
	stackqueue.push(64);
	stackqueue.push(-1);
	int result {0}, counter {0};
	//Getting values out..
	stackqueue.pop();
	while(true)
	{
		try
		{
			result = stackqueue.pop();
		}
		catch(int i)
		{
			break;
		}
		if(result == -1)
		{	
			for(int idx = 0; idx < counter; idx++)
				cout<<last_print.pop()<<' ';
			cout<<'\n';
			counter = 0;
		}
		else
		{
			last_print.push(result);
			counter++;
		}	
			
	}
	return 0;
}
