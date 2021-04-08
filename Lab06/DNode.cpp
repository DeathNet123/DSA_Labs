#include <iostream>

using namespace std;

class DNode{
	public:
		DNode *prev,*next;
		int data;
		DNode (int d, DNode *p = NULL , DNode *n = NULL ){
			data = d;
			prev = p;
			next = n;
		}
};

