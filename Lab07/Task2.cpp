#include <iostream>
#include "Node.cpp"

using namespace std;

#define DUMMY 0

class LinkedStackQueue{ 
	Node *first, *last;
	int getFirstElement(){
		if (first->next==NULL)	throw (0);
		Node *t = first -> next;
		first -> next = t -> next;
		int res = t -> data;
		delete t;
		return res;
	}
	int seeFirstElement(){
		if (first->next==NULL)	throw (0);
		return first -> next -> data ;
	}
public:
	LinkedStackQueue(){	first = new Node(DUMMY);	last = NULL;	}
	void push(int d){
		first -> next = new Node (d, first -> next);
	}
	void enqueue(int d){
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

bool is_comp(int number)
{
	int check = 0;
	for(int idx = 1; idx <= number; idx++)
	{
		if(number % idx == 0)
			check++;
	}
	if(check <= 2)
		return false;
	return true;
}
int main(){
	LinkedStackQueue stackQueue;
	int number{0};
	cin>>number;
	for(int idx = 2; idx <= number; idx++)
	{
		if(number % idx == 0)
		{
			stackQueue.push(idx);
		}	
	}
	int result {0};
	bool buff = false;
	while(true)
	{
		try	
		{
			result = stackQueue.pop();
		}
		catch(int i)
		{
			break;
		}
		for(int idx = 2; idx <= result; idx++)
			if(result % idx == 0 && is_comp(result))
			{
				cout<<"Divisor of "<<result<<':'<<idx;
				if(result/idx != idx)
					cout<<", "<<result/idx<<'\n';
				if(result/idx == idx && !is_comp(idx))
					buff = true;
				break;
			}
		if(buff)
			break;

	}
	cout<<'\n';
	return 0;
}
