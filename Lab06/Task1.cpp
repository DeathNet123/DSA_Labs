#include <iostream>

using namespace std;

class Node{
	public:
		Node *next;
		int data;
		Node (int d){
			data = d;
			next = NULL;
		}
};
class LinkedList{
	Node *first, *last;
public:
	LinkedList(){

		first = new Node(0);
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
    Node* addInOrder(int d, Node *t){
		if ( t == NULL || t->data > d){
			if (t == NULL){
				last = new Node(d);
				return last;
			}
			Node *newNode  = new Node(d);
			newNode -> next = t;
			return newNode;
		}
		else
			t -> next = addInOrder(d, t->next);
		return t;
	}
	void addInOrder(int d){
		first -> next = addInOrder(d, first->next);
	}
	Node* deleteNode(int d, Node* t){
		if (t == NULL)   	return NULL;
		if (t -> data == d){
			Node *toDelete = t -> next;
			delete t;
			return toDelete;
		}
		else{
			t -> next = deleteNode( d, t -> next);
			if (t -> next == NULL)	last = t;
		}
		return t;
	}
	void deleteNode(int d){
		if (first -> next == NULL)	return;
		first -> next = deleteNode(d, first -> next) ;
	}
	void printRecReverse(Node *t){
		if (t ==  NULL)		return;
			printRecReverse( t -> next);
		cout << t -> data << ' ';
	}
	void printRecReverse(){
		printRecReverse(first->next);
		cout << '\n' ;
	}
	void printRec(Node *t){
		if (t ==  NULL)		return;
		cout << t -> data << ' ';
		printRec( t -> next);
	}	
	//wrapper function
	void printRec(){
		printRec(first->next);
		cout << '\n' ;
	}

    //Main Part A of Question 1...
    bool print_kth_position(int k) //Wrapper function
    {
        return print_kth_position(k, first -> next);
    }

    bool print_kth_position(int k, Node *idx ,int count = 0)
    {
        if(idx == NULL)
            return false;
        else
        {
            if(idx -> data > 0)
            {
                count++;
                if(k == count)
                {
                    cout<<idx->data;
                    return true;
                }
            }
            return print_kth_position(k, idx -> next, count);
        }
    }

    //Part B of Question 1..

    bool is_sum_equal(int n) //Wrapper function..
    {
        return is_sum_equal(n , first -> next);
    }

    bool is_sum_equal(int n, Node *idx)
    {
        if(idx == NULL)
            return false;
        int tester = idx -> data;
        idx -> data = 0;
        for(Node *kdx = first -> next; kdx != NULL; kdx = kdx-> next)
        {
            if(idx->data + kdx->data == n)
                return true;
        }
        idx->data = tester;
        return is_sum_equal(n, idx->next);
    }
};
int main(){
	LinkedList list;
	list.addNodeAtStart(30);
    list.addNodeAtEnd(-40);
    list.addNodeAtEnd(80);
    list.addNodeAtEnd(20);
    list.addNodeAtEnd(12);
	list.printRec();
    list.print_kth_position(7);
    list.is_sum_equal(100);
	
	return 0;
}

