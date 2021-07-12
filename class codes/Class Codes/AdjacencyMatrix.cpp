#include <iostream>

using namespace std;

#define NOEDGE 0
#define EDGE 1

class AMatrix{
	int **nodes, count;
public:
	AMatrix(int count)
	{	
		this -> count = count;
		nodes = new int* [count];
		int i, j;
		for (i = 0 ; i < count ; i++)
		{
			nodes [ i ] = new int [count];
			for ( j = 0 ; j < count ; j++ )
				nodes [ i ] [ j ] = NOEDGE;  
		}
	}
	void addEdge(int n1, int n2){
		nodes [ n1 ] [ n2 ] = EDGE;
	}
	void show(){
		int i, j;
		for (i = 0 ; i < count ; i++){
			cout << i << " : ";
			for ( j = 0 ; j < count ; j++ )
				if ( nodes [ i ] [ j ] == EDGE )
					cout << j << ' ';
			cout << '\n' ;  
		}
	}
};

int main(){
	AMatrix matrix(7);
	matrix.addEdge(0,2);
	matrix.addEdge(0,3);
	matrix.addEdge(0,4);
	matrix.addEdge(1,0);
	matrix.addEdge(1,3);
	matrix.addEdge(2,4);
	matrix.addEdge(3,0);
	matrix.addEdge(4,1);
	matrix.addEdge(4,2);
	matrix.addEdge(4,3);
	matrix.addEdge(4,6);
	matrix.addEdge(6,5);
	matrix.show();
	return 0;
}	
