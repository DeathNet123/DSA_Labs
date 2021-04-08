#include <iostream>
#include "DNode.cpp"

using namespace std;

#define DUMMY 0

class DHCLList{
	DNode *head;
public:
	DHCLList(){	head = new DNode(DUMMY);	head -> next = head -> prev = head;	}
	void addNodeAtHead(int d){
		DNode *newNode =new DNode(d, head, head->next);
		head -> next -> prev = newNode;
		head -> next = newNode;
	}
	void addNodeAtTail(int d){
		DNode *newNode =new DNode(d, head->prev, head);
		head -> prev -> next = newNode;
		head -> prev = newNode;
	}
	void print(DNode *t){
		if (t == head)	return;
		cout << t -> data << ' ';	
		print(t->next);
	}
	void print(){
		print(head->next);
		cout << '\n';	
	}
	void printR(DNode *t){
		if (t == head)	return;
		cout << t -> data << ' ';	
		printR(t->prev);
	}
	void printR(){
		printR(head->prev);
		cout << '\n';	
	}
	void addInOrder(int d, DNode *t){
		if (t == head || t -> data > d){
			DNode *newNode = new DNode (d, t -> prev, t);
			t -> prev -> next = newNode;
			t -> prev = newNode;
			return;
		}
		addInOrder(d, t -> next) ;
	}
	void addNodeInOrder(int d){
		if (head -> next == head){
			addNodeAtHead(d);
			return;
		}
		addInOrder(d, head -> next) ;
	}
	/*void addNodeAfter(int d1, int d2){
		Node *t;
		for (t = first->next ; t != NULL && t -> data != d1; t = t -> next);
		if (t != NULL){
			Node *newNode = new Node(d2);
			newNode -> next = t -> next;
			t -> next = newNode;
			if (t == last)	last = newNode;
		}
	}
	void deleteNodeFromStart(){
		if (first->next!=NULL){
			Node *t = first -> next;
			first -> next = t -> next; //t->next may be second node or NULL
			delete t;
			if (first -> next == NULL)		last = NULL;
		}
	}
	void deleteNodeFromEnd(){
		if (last!=NULL){
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
	void show(){
		if ( first -> next == NULL)
			cout << "List is empty\n";
		for ( Node *t = first -> next ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}*/

    //Main Part Question two Part A..
    void swap(int d1, int d2)
    {
        DNode *A = NULL, *B = NULL;
        for(DNode *idx = head->next; idx != head; idx = idx -> next)
        {
            if(idx->data == d1)
                A = idx;
            else if(idx->data == d2)
                B = idx;
            if(A && B)
                break;
        }
        if(!A || !B)
            return;
        else if (A->data == B->data)
            return;
        
        DNode p=*A;
        *A=*B;
        *B=p;

        B->next = A->next;
        B->prev = A->prev;
        A->next = p.next;
        A->prev = p.prev;
    }

    //Question 2 Part B
};

int main(){
	DHCLList list;
	list.addNodeInOrder(23);
	list.addNodeInOrder(13);
	list.addNodeInOrder(53);
	list.addNodeInOrder(83);
	list.addNodeInOrder(73);
	list.addNodeInOrder(43);
	list.addNodeInOrder(93);
	list.print();
	list.swap(23,43);
    list.print();
	return 0;
}