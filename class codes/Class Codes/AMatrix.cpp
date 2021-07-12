#include <iostream>

using namespace std;

#define VISITED 1
#define NOTVISITED 0
#define NOEDGE 0
#define EDGE 1

class AMatrix
{
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
	void addEdge(int n1, int n2)
	{
		nodes [ n1 ] [ n2 ] = EDGE;
		//in case of undirected graph we will add this line
		//nodes [ n2 ] [ n1 ] = EDGE;
	}
	void show(void)
	{
		int i, j;
		for (i = 0 ; i < count ; i++)
		{
			cout << i << " : ";
			for ( j = 0 ; j < count ; j++ )
				if ( nodes [ i ] [ j ] == EDGE )
					cout << j << ' ';
			cout << '\n' ;  
		}
	}
	//Small dfs, visit all connected nodes only
	void dfs(int nodeNo, int *visited)
	{
		if ( visited [ nodeNo ] != VISITED)
		{
			visited[ nodeNo] = VISITED;
			cout << nodeNo << ' ';
			//Cheque for neighbors of current node
			for (int i = 0  ; i < count ; i++)
				if ( nodes [nodeNo] [ i ] == EDGE && visited [ i ] != VISITED )
					dfs( i, visited );//recursive call to visit connected nodes
		}
	}
	//Capital DFS used in books especially algorithm analysis books
	void dfs(int nodeNo)
	{
		int  *visited = new int [ count ];
		int i, j;
		for ( i = 0 ; i < count ; i++ )	
			visited [i] = NOTVISITED;
		for ( i = nodeNo , j = 0; j < count; j++ )	
		{ 
			if ( i == count && j < count)	
				i = 0;
			if ( visited [ i ] == NOTVISITED )
			{
				dfs( i , visited );//call to small dfs
				cout << '\n' ;
			}
			if (j == 0 || i != 0)	i++ ;
		}
		
		delete [] visited;
	}
};

int main(void)
{
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
	//matrix.show();
	//cout << '\n';
	matrix.dfs(6);
//	cout << '\n';
//	matrix.dfs(2);
//	cout << '\n';
//	matrix.dfs(3);
	return 0;
}	
