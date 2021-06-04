#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
        nodes [n2][n1] = EDGE;
	}
	void show()
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

    bool is_connected(int a, int b)
    {
        if(nodes[a][b] == EDGE)
            return true;
        return false;
    }

    int count_edges()
    {
        int sum = 0;
        for(int idx = 0 ; idx < count; idx++)
        {
            for(int kdx = 0 ; kdx < count; kdx++)
                if(nodes[idx][kdx] == EDGE)
                    sum++;
        }
        return sum;
    }
    
    bool is_path_exists(int a, int b)
    {
        queue<int> cake;
        bool *visited = new bool[count];
        for(int idx = 0 ; idx < count; idx++)
            visited[idx] = false;
        cake.push(a);
        while(!cake.empty())
        {
            int fake = cake.front();
            if(fake == b)
            {
                return true;
            }
            visited[fake] = true;
            cake.pop();
            for(int idx = 0; idx < count; idx++)
            {
                if(nodes[fake][idx] == EDGE)
                {
                    if(visited[idx] != true)
                        cake.push(idx);
                }
                    
            }
        }
        return false;
    }

    int count_edges(int a, int b)
    {
        if(nodes[a][b] == EDGE || nodes[b][a])
            return 1;
        if(!is_path_exists(a, b))
            return -1;
        //else....
        queue<int> cake;
        bool *visited = new bool[count];
        int *distance = new int[count];
        for(int idx = 0 ; idx < count; idx++)
        {
            visited[idx] = false;
            distance[idx] = 0;
        }
        cake.push(a);
        while(!cake.empty())
        {
            int fake = cake.front();
            if(fake == b)
            {
                return distance[b];
            }
            visited[fake] = true;
            cake.pop();
            for(int idx = 0; idx < count; idx++)
            {
                if(nodes[fake][idx] == EDGE)
                {
                    if(visited[idx] != true)
                    {
                        cake.push(idx);
                        distance[idx] =  distance[fake] + 1;
                        visited[idx] = true;
                    }
                        
                }
                    
            }
        }
    }

};

int main(void)
{
	AMatrix matrix(10);
	matrix.addEdge(0,1);
	matrix.addEdge(1,2);
	matrix.addEdge(2,0);
	matrix.addEdge(2,3);
	matrix.addEdge(3,4);
    cout<<matrix.is_path_exists(0, 4)<<'\n';
    cout<<matrix.count_edges(0,4);
	return 0;
}	
