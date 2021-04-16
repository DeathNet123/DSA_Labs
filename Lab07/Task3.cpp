#include <iostream>
#include <cstdlib>
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
int main(){
	LinkedStackQueue stack_parentheses;
	LinkedStackQueue stack_curly_brackets;
	LinkedStackQueue stack_square_brackets;
	string expression = "[x+{(y+z)*(y-x)+((x+y(2*z)))}])";
	
	//Pushed the values...
	for(char buff : expression)
	{
		if(buff == '[')
			stack_square_brackets.push(1);
		else if(buff == '(')
			stack_parentheses.push(1);
		else if(buff == '{')
			stack_curly_brackets.push(1);
	}
	
	//Popping values...
	for(char buff : expression)
	{
		if(buff == ']')
		try{
		stack_square_brackets.pop();
	}catch(int i){
		cout << "Incorrect";
		exit(0);
		break;
		
	}		
		else if(buff == ')')
		try{
		stack_parentheses.pop();
	}catch(int i){
		cout << "Incorrect";
		exit(0);
		break;
	}		
			
		else if(buff == '}')
			try{
		stack_curly_brackets.pop();
	}catch(int i){
		cout << "Incorrect";
		exit(0);
		break;
	}		
	}
	bool pare = false, curl = false, squ = false;

	try{
		stack_curly_brackets.pop();
	}catch(int i){
		curl = true;
	}

	try{
		stack_square_brackets.pop();
	}catch(int i){
		squ = true;
	}

	try{
		stack_parentheses.pop();
	}catch(int i){
		pare = true;
	}	

	if(curl && squ && pare){ cout << "Correct";}		
	return 0;
}
